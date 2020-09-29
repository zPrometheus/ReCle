#include "PlaylistTabBar.h"
#include <qvariant.h>

#include "playlist.h"
#include "playlistmanager.h"
#include "playlisttabbar.h"
#include "playlistview.h"
//#include "songmimedata.h"
#include "core/logging.h"
#include "ui/IconLoader.h"

#include <qsettings.h>
#include <QCheckBox>
#include <QContextMenuEvent>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QInputDialog>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>
#include <QToolTip>
#include "widgets/renametablineedit.h"

const char* PlaylistTabBar::kSettingsGroup = "PlaylistTabBar";

PlaylistTabBar::PlaylistTabBar(QWidget* parent)
	: QTabBar(parent),
	manager_(nullptr),
	menu_(new QMenu(this)),
	menu_index_(-1),
	suppress_current_changed_(false),
	initialized_(false),
	rename_editor_(new RenameTabLineEdit(this)) {
	setAcceptDrops(true);
	setElideMode(Qt::ElideRight);
	setUsesScrollButtons(true);
	setTabsClosable(true);

	close_ = menu_->addAction(IconLoader::Load("list-remove", IconLoader::Base),
		tr("Close playlist"), this, SLOT(Close()));
	rename_ = menu_->addAction(IconLoader::Load("edit-rename", IconLoader::Base),
		tr("Rename playlist..."), this, SLOT(Rename()));
	save_ = menu_->addAction(IconLoader::Load("document-save", IconLoader::Base),
		tr("Save playlist..."), this, SLOT(Save()));
	menu_->addSeparator();

	rename_editor_->setVisible(false);
	connect(rename_editor_, SIGNAL(editingFinished()), SLOT(RenameInline()));
	connect(rename_editor_, SIGNAL(EditingCanceled()), SLOT(HideEditor()));

	connect(this, SIGNAL(currentChanged(int)), SLOT(CurrentIndexChanged(int)));
	connect(this, SIGNAL(tabMoved(int, int)), SLOT(TabMoved()));
	// We can't just emit Close signal, we need to extract the playlist id first
	connect(this, SIGNAL(tabCloseRequested(int)), SLOT(CloseFromTabIndex(int)));
}

void PlaylistTabBar::SetActions(QAction* new_playlist, QAction* load_playlist) {
	menu_->insertAction(0, new_playlist);
	menu_->insertAction(0, load_playlist);

	new_ = new_playlist;
}

void PlaylistTabBar::SetManager(PlaylistManager* manager) {
	manager_ = manager;
	connect(manager_, SIGNAL(PlaylistFavorited(int, bool)),
		SLOT(PlaylistFavoritedSlot(int, bool)));
	connect(manager_, SIGNAL(PlaylistManagerInitialized()), this,
		SLOT(PlaylistManagerInitialized()));
}

void PlaylistTabBar::PlaylistManagerInitialized() {
	// Signal that we are done loading and thus further changes should be
	// committed to the db.
	initialized_ = true;
	disconnect(manager_, SIGNAL(PlaylistManagerInitialized()), this,
		SLOT(PlaylistManagerInitialized()));
}

void PlaylistTabBar::contextMenuEvent(QContextMenuEvent* e) {
	// we need to finish the renaming action before showing context menu
	if (rename_editor_->isVisible()) {
		// discard any change
		HideEditor();
	}

	menu_index_ = tabAt(e->pos());
	rename_->setEnabled(menu_index_ != -1);
	close_->setEnabled(menu_index_ != -1 && count() > 1);
	save_->setEnabled(menu_index_ != -1);

	menu_->popup(e->globalPos());
}

void PlaylistTabBar::mouseReleaseEvent(QMouseEvent* e) {
	if (e->button() == Qt::MidButton) {
		// Update menu index
		menu_index_ = tabAt(e->pos());
		Close();
	}

	QTabBar::mouseReleaseEvent(e);
}

void PlaylistTabBar::mouseDoubleClickEvent(QMouseEvent* e) {
	int index = tabAt(e->pos());

	// discard a double click with the middle button
	if (e->button() != Qt::MidButton) {
		if (index == -1) {
			new_->activate(QAction::Trigger);
		}
		else {
			// update current tab
			menu_index_ = index;

			// set position
			rename_editor_->setGeometry(tabRect(index));
			rename_editor_->setText(tabText(index));
			rename_editor_->setVisible(true);
			rename_editor_->setFocus();
		}
	}

	QTabBar::mouseDoubleClickEvent(e);
}

void PlaylistTabBar::Rename() {
	if (menu_index_ == -1) return;

	QString name = tabText(menu_index_);
	name = QInputDialog::getText(this, tr("Rename playlist"),
		tr("Enter a new name for this playlist"),
		QLineEdit::Normal, name);

	if (name.isNull()) return;

	emit Rename(tabData(menu_index_).toInt(), name);
}

void PlaylistTabBar::RenameInline() {
	emit Rename(tabData(menu_index_).toInt(), rename_editor_->text());
	HideEditor();
}

void PlaylistTabBar::HideEditor() {
	// editingFinished() will be called twice due to Qt bug #40, so we reuse the
	// same instance, don't delete it
	rename_editor_->setVisible(false);

	// hack to give back focus to playlist view
	manager_->SetCurrentPlaylist(manager_->current()->id());
}

void PlaylistTabBar::Close() {
	if (menu_index_ == -1) return;

	const int playlist_id = tabData(menu_index_).toInt();

	QSettings s;
	s.beginGroup(kSettingsGroup);

	const bool ask_for_delete = s.value("warn_close_playlist", true).toBool();

	if (ask_for_delete && !manager_->IsPlaylistFavorite(playlist_id) &&
		!manager_->playlist(playlist_id)->GetAllSongs().empty()) {
		QMessageBox confirmation_box;
		confirmation_box.setWindowIcon(QIcon(":/icon.png"));
		confirmation_box.setWindowTitle(tr("Remove playlist"));
		confirmation_box.setIcon(QMessageBox::Question);
		confirmation_box.setText(
			tr("You are about to remove a playlist which is not part of your "
				"favorite playlists: "
				"the playlist will be deleted (this action cannot be undone). \n"
				"Are you sure you want to continue?"));
		confirmation_box.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);

		QCheckBox dont_prompt_again(tr("Warn me when closing a playlist tab"),
			&confirmation_box);
		dont_prompt_again.setChecked(ask_for_delete);
		dont_prompt_again.blockSignals(true);
		dont_prompt_again.setToolTip(
			tr("This option can be changed in the \"Behavior\" preferences"));

		QGridLayout* grid = qobject_cast<QGridLayout*>(confirmation_box.layout());
		QDialogButtonBox* buttons = confirmation_box.findChild<QDialogButtonBox*>();
		if (grid && buttons) {
			const int index = grid->indexOf(buttons);
			int row, column, row_span, column_span = 0;
			grid->getItemPosition(index, &row, &column, &row_span, &column_span);
			QLayoutItem* buttonsItem = grid->takeAt(index);
			grid->addWidget(&dont_prompt_again, row, column, row_span, column_span,
				Qt::AlignLeft | Qt::AlignTop);
			grid->addItem(buttonsItem, ++row, column, row_span, column_span);
		}
		else {
			confirmation_box.addButton(&dont_prompt_again, QMessageBox::ActionRole);
		}

		if (confirmation_box.exec() != QMessageBox::Yes) {
			return;
		}

		// If user changed the pref, save the new one
		if (dont_prompt_again.isChecked() != ask_for_delete) {
			s.setValue("warn_close_playlist", dont_prompt_again.isChecked());
		}
	}

	// Close the playlist. If the playlist is not a favorite playlist, it will be
	// deleted, as it will not be visible after being closed. Otherwise, the tab
	// is closed but the playlist still exists and can be resurrected from the
	// "Playlists" tab.
	emit Close(playlist_id);

	// Select the nearest tab.
	if (menu_index_ > 1) {
		setCurrentIndex(menu_index_ - 1);
	}

	// Update playlist tab order/visibility
	TabMoved();
}

void PlaylistTabBar::CloseFromTabIndex(int index) {
	// Update the global index
	menu_index_ = index;
	Close();
}

void PlaylistTabBar::Save() {
	if (menu_index_ == -1) return;

	emit Save(tabData(menu_index_).toInt());
}

int PlaylistTabBar::current_id() const {
	if (currentIndex() == -1) return -1;
	return tabData(currentIndex()).toInt();
}

int PlaylistTabBar::index_of(int id) const {
	for (int i = 0; i < count(); ++i) {
		if (tabData(i).toInt() == id) {
			return i;
		}
	}
	return -1;
}

void PlaylistTabBar::set_current_id(int id) { setCurrentIndex(index_of(id)); }

int PlaylistTabBar::id_of(int index) const {
	if (index < 0 || index >= count()) {
		qLog(Warning) << "Playlist tab index requested is out of bounds!";
		return 0;
	}
	return tabData(index).toInt();
}

void PlaylistTabBar::set_icon_by_id(int id, const QIcon& icon) {
	setTabIcon(index_of(id), icon);
}

void PlaylistTabBar::RemoveTab(int id) { removeTab(index_of(id)); }

void PlaylistTabBar::set_text_by_id(int id, const QString& text) {
	setTabText(index_of(id), text);
	setTabToolTip(index_of(id), text);
}

void PlaylistTabBar::CurrentIndexChanged(int index) {
	if (!suppress_current_changed_) emit CurrentIdChanged(tabData(index).toInt());
}
