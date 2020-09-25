#include "PlaylistContainer.h"
#include "ui_playlistcontainer.h"
#include "core/Appearance.h"
#include "core/Application.h"
#include "playlist/PlaylistManager.h"
#include "ui/IconLoader.h"

#include <qlabel.h>
#include <qsettings.h>
#include <qtimeline.h>
#include <qtimer.h>
#include <qobject.h>
#include <qundostack.h>
#include <qaction.h>

const char* PlaylistContainer::kSettingsGroup = "playlist";
const int PlaylistContainer::kFilterDelayMs = 100;

PlaylistContainer::PlaylistContainer(QWidget* parent)
	:QWidget(parent),mUndo(nullptr),mRedo(nullptr),
	mNoMatchesLabel(nullptr),mDirty(false),mTabBarAnimation(new QTimeLine(500,this)),
	mFilterTimer(new QTimer(this)),
	mManager(nullptr),
	ui(new Ui_playlistcontainer)
{
	ui->setupUi(this);
	mNoMatchesLabel = new QLabel(ui->playlist);
	mNoMatchesLabel->setAttribute(Qt::WA_TransparentForMouseEvents);//
	mNoMatchesLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	mNoMatchesLabel->setText("no matches label is here");
	
	QPalette NoMatcherPalette = mNoMatchesLabel->palette();
	const QColor NoMatcherColor = NoMatcherPalette.color(QPalette::Disabled, QPalette::Text);
	NoMatcherPalette.setColor(QPalette::Normal, QPalette::WindowText,
		NoMatcherColor);
	NoMatcherPalette.setColor(QPalette::Inactive, QPalette::WindowText,
		NoMatcherColor);
	mNoMatchesLabel->setPalette(NoMatcherPalette);

	ui->toolbar->setStyleSheet("QFrame {border:0px;}");

	QSettings settings;
	settings.beginGroup(Appearance::kSettingsGroup);
	bool hide_toolbar = settings.value("b_hide_filter_toolbar", false).toBool();
	ui->toolbar->setVisible(!hide_toolbar);

	QFont NoMatchesFont = mNoMatchesLabel->font();
	NoMatchesFont.setBold(true);
	mNoMatchesLabel->setFont(NoMatchesFont);

	ui->tab_bar->setExpanding(false);
	ui->tab_bar->setMovable(true);

	connect(mTabBarAnimation, SIGNAL(frameChanged(int)), SLOT(SetTabBarHeight(int)));
	ui->tab_bar->setMaximumHeight(0);

	// Connections
	connect(ui->tab_bar, SIGNAL(currentChanged(int)), SLOT(DirtyTabBar()));
	connect(ui->tab_bar, SIGNAL(Save(int)), SLOT(SavePlaylist(int)));

	mFilterTimer->setSingleShot(true);
	mFilterTimer->setInterval(kFilterDelayMs);
	connect(mFilterTimer, SIGNAL(timeout()), this, SLOT(UpdateFilter()));

	connect(ui->filter, SIGNAL(textChanged(QString)), SLOT(MaybeUpdateFilter()));
	connect(ui->playlist, SIGNAL(FocusOnFilterSignal(QKeyEvent*)),
		SLOT(FocusOnFilter(QKeyEvent*)));

	ui->filter->installEventFilter(this);

}

PlaylistView* PlaylistContainer::view() const{
	return ui->playlist;
}


void PlaylistContainer::setViewModel(Playlist* playlist)
{
	mPlist = playlist;

	playlist->IgnoreSorting(true);  //?
	view()->setModel(playlist->proxy()); //m
	view()->SetPlaylist(playlist);

	view()->selectionModel()->select(mManager->current_selection(),
		QItemSelectionModel::ClearAndSelect);
	playlist->IgnoreSorting(false);

	connect(view()->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this,
		SLOT(SelectionChanged()));
	emit ViewSelectionModelChanged();

	// Update filter
	ui->filter->setText(playlist->proxy()->filterRegExp().pattern());

	// Update the no matches label
	connect(mPlist->proxy(), SIGNAL(modelReset()),
		SLOT(UpdateNoMatchesLabel()));
	connect(mPlist->proxy(), SIGNAL(rowsInserted(QModelIndex, int, int)),
		SLOT(UpdateNoMatchesLabel()));
	connect(mPlist->proxy(), SIGNAL(rowsRemoved(QModelIndex, int, int)),
		SLOT(UpdateNoMatchesLabel()));
	connect(mPlist, SIGNAL(modelReset()), SLOT(UpdateNoMatchesLabel()));
	connect(mPlist, SIGNAL(rowsInserted(QModelIndex, int, int)),
		SLOT(UpdateNoMatchesLabel()));
	connect(mPlist, SIGNAL(rowsRemoved(QModelIndex, int, int)),
		SLOT(UpdateNoMatchesLabel()));
	UpdateNoMatchesLabel();

	// Ensure that tab is current
	if (ui->tab_bar->current_id() != mManager->current_id())
		ui->tab_bar->set_current_id(mManager->current_id());

	// Sort out the undo/redo actions
	delete mUndo;
	delete mRedo;
	mUndo = playlist->undo_stack()->createUndoAction(this);
	mRedo = playlist->undo_stack()->createRedoAction(this);
	mUndo->setIcon(IconLoader::Load("edit-undo", IconLoader::Base));
	mUndo->setShortcut(QKeySequence::Undo);
	mRedo->setIcon(IconLoader::Load("edit-redo", IconLoader::Base));
	mRedo->setShortcut(QKeySequence::Redo);

	ui->undo->setDefaultAction(mUndo);
	ui->redo->setDefaultAction(mRedo);

	emit UndoRedoActionsChanged(mUndo, mRedo);

}

void PlaylistContainer::UpdateNoMatchesLabel() {
	Playlist* playlist = mManager->current();
	const bool has_rows = playlist->rowCount() != 0;
	const bool has_results = playlist->proxy()->rowCount() != 0;

	QString text;
	if (has_rows && !has_results) {
		if (ui->filter->text().trimmed().compare(
			"the answer to life the universe "
			"and everything",
			Qt::CaseInsensitive) == 0) {
			text = "42";
		}
		else {
			text = tr(
				"No matches found.  Clear the search box to show the whole playlist "
				"again.");
		}
	}

	if (!text.isEmpty()) {
		mNoMatchesLabel->setText(text);
		RepositionNoMatchesLabel(true);
		mNoMatchesLabel->show();
	}
	else {
		mNoMatchesLabel->hide();
	}
}

void PlaylistContainer::RepositionNoMatchesLabel(bool force) {
	if (!force && !mNoMatchesLabel->isVisible()) return;

	const int kBorder = 10;

	QPoint pos =
		ui->playlist->viewport()->mapTo(ui->playlist, QPoint(kBorder, kBorder));
	QSize size = ui->playlist->viewport()->size();
	size.setWidth(size.width() - kBorder * 2);
	size.setHeight(size.height() - kBorder * 2);

	mNoMatchesLabel->move(pos);
	mNoMatchesLabel->resize(size);
}

void PlaylistContainer::SelectionChanged() {
	mManager->SelectionChanged(view()->selectionModel()->selection());
}


void PlaylistContainer::UpdateFilter()
{
	

}

void PlaylistContainer::Save(QSettings* settings) {
  if (mStartingUp || !mDirty) return;
  mDirty = false;

  settings->beginGroup(kSettingsGroup);
  settings->setValue("current_playlist", ui->tab_bar->current_id());
  settings->endGroup();
}

void PlaylistContainer::SetTabBarHeight(int height)
{
	ui->tab_bar->setMaximumHeight(height);
}

void PlaylistContainer::DirtyTabBar() {
	mDirty = true;
	mApp->DirtySettings();
}

PlaylistContainer::~PlaylistContainer()
{


}
