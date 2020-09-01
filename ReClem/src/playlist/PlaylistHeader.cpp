#include "PlaylistHeader.h"
#include <qmenu.h>
#include <qsettings.h>
#include <QContextMenuEvent>
#include "Playlist.h"
#include "PlaylistView.h"

PlaylistHeader::PlaylistHeader(Qt::Orientation orientation,PlaylistView* view,QWidget* parent)
	:StretchHeaderView(orientation,parent),
	mView(view),
	mMenu(new QMenu(this))
{
	mHideAction = mMenu->addAction(tr("&Hide..."), this, SLOT(HideCurrent));
	mStretchAction = mMenu->addAction(tr("&Stretch columns to fit window"), this, SLOT(ToggleStretchEnabled()));
	mRatingLock = mMenu->addAction(tr("&Lock Rating"), this, SLOT(ToggleRatingEditStatus));
	mRatingLock->setCheckable(true);
	QSettings s;
	s.beginGroup("Playlist");
	mRatingLock->setChecked(s.value("RatingLocked", false).toBool());
	s.endGroup();
	mMenu->addSeparator();

	QMenu* AlignMenu = new QMenu(tr("&Align text"), this);
	QActionGroup* AlignGroup = new QActionGroup(this);
	mAlignLeftAction = new QAction(tr("&Left"), AlignGroup);
	mAlignCenterAction = new QAction(tr("&Center"), AlignGroup);
	mAlignRightAction = new QAction(tr("&Right"), AlignGroup);

	mAlignLeftAction->setCheckable(true);
	mAlignCenterAction->setCheckable(true);
	mAlignRightAction->setCheckable(true);
	AlignMenu->addActions(AlignGroup->actions());

	connect(AlignGroup, SIGNAL(triggered(QAction*)),
		SLOT(SetColumnAlignment(QAction*)));

	mMenu->addMenu(AlignMenu);
	mMenu->addSeparator();

	mStretchAction->setCheckable(true);
	mStretchAction->setChecked(isStretchEnabled());

	connect(this, SIGNAL(StretchEnabledChanged(bool)), mStretchAction,
		SLOT(setChecked(bool)));
}

void PlaylistHeader::contextMenuEvent(QContextMenuEvent* e)
{
	mMenuSection = logicalIndexAt(e->pos());
	if (mMenuSection == -1 || (mMenuSection == logicalIndex(0)
		&& logicalIndex(1) == -1))
		mHideAction->setVisible(false);
	else {
		mHideAction->setVisible(true);
		QString title(
			model()->headerData(mMenuSection, Qt::Horizontal).toString());
		mHideAction->setText(tr("&Hide %1").arg(title));

		mRatingLock->setVisible(mMenuSection == Playlist::Column_Rating);

		Qt::Alignment alignment = mView->ColumnAlignment(mMenuSection);
		if (alignment & Qt::AlignLeft)
			mAlignLeftAction->setChecked(true);
		else if (alignment & Qt::AlignHCenter)
			mAlignCenterAction->setChecked(true);
		else if (alignment & Qt::AlignRight)
			mAlignRightAction->setChecked(true);
	}
/*
	qDeleteAll(show_actions_);
	show_actions_.clear();
	for (int i = 0; i < count(); ++i) {
		AddColumnAction(i);
	}
	menu_->popup(e->globalPos());
	*/
	}

void PlaylistHeader::AddColumnAction(int index) {
#ifndef HAVE_MOODBAR
	if (index == Playlist::Column_Mood)
		return;
#endif

	QString title(model()->headerData(index, Qt::Horizontal).toString());

	QAction* action = mMenu->addAction(title);
	action->setCheckable(true);
	action->setChecked(!isSectionHidden(index));
	mShowAction << action;

	connect(action, &QAction::triggered,
		[this, index]() { ToggleVisible(index); });

}

void PlaylistHeader::ToggleVisible(int section)
{
	SetSectionHiddenOrShow(section, !isSectionHidden(section));
	emit SectionVisibilityChanged(section, !isSectionHidden(section));
}

void PlaylistHeader::enterEvent(QEvent*) { emit MouseEntered(); }

void PlaylistHeader::ToggleRatingEditStatus() {
	emit SectionRatingLockStatusChanged(mRatingLock->isChecked());
}

void PlaylistHeader::HideCurrent() {
	if (mMenuSection == -1) return;

	SetSectionHiddenOrShow(mMenuSection, true);
}

PlaylistHeader::~PlaylistHeader()
{


}
