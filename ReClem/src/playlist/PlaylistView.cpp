#include "PlaylistView.h"
#include "PlaylistHeader.h"
#include "ui/IconLoader.h"
#include "core/Application.h"
#include <qsettings.h>

const char* Playlist::kSettingsGroup = "Playlist";

PlaylistView::PlaylistView(QWidget* parent)
	:QTreeView(parent), mHeader(new PlaylistHeader(Qt::Horizontal, this, this))
{
	setHeader(mHeader);
	mHeader->setSectionsMovable(true);
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
	mHeader->setFirstSectionMovable(true);
#endif
	QIcon currenttrack_play =
		IconLoader::Load("currenttrack_play", IconLoader::Other);
	mCurrentTrackPlay =
		currenttrack_play.pixmap(currenttrack_play.actualSize(QSize(32, 32)));
	QIcon currenttrack_pause =
		IconLoader::Load("currenttrack_pause", IconLoader::Other);
	mCurrentTrackPause =
		currenttrack_pause.pixmap(currenttrack_pause.actualSize(QSize(32, 32)));

	connect(mHeader, SIGNAL(sectionResized(int, int, int)),
		SLOT(DirtyGeometry()));
	connect(mHeader, SIGNAL(sectionMoved(int, int, int)), SLOT(DirtyGeometry()));
	connect(mHeader, SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)),
		SLOT(DirtyGeometry()));
	connect(mHeader, SIGNAL(SectionVisibilityChanged(int, bool)),
		SLOT(DirtyGeometry()));
	connect(mHeader, SIGNAL(SectionRatingLockStatusChanged(bool)),
		SLOT(SetRatingLockStatus(bool)));
	connect(mHeader, SIGNAL(sectionResized(int, int, int)),
		SLOT(InvalidateCachedCurrentPixmap()));
	connect(mHeader, SIGNAL(sectionMoved(int, int, int)),
		SLOT(InvalidateCachedCurrentPixmap()));
	connect(mHeader, SIGNAL(SectionVisibilityChanged(int, bool)),
		SLOT(InvalidateCachedCurrentPixmap()));
	connect(mHeader, SIGNAL(StretchEnabledChanged(bool)), SLOT(DirtySettings()));
	connect(mHeader, SIGNAL(StretchEnabledChanged(bool)),
		SLOT(StretchChanged(bool)));
	connect(mHeader, SIGNAL(MouseEntered()), SLOT(RatingHoverOut()));
}

void PlaylistView::DirtyGeometry()
{
	mDirtyGeometry = true;
	mApp->DirtySettings();
}

void PlaylistView::InvalidateCachedCurrentPixmap() {
	mCacheCurrentRow = QPixmap();
}


void PlaylistView::SetRatingLockStatus(bool state)
{
	if (mReadOnlySettings) return;
	mRatingLocked = state;
	QSettings s;
	s.beginGroup(Playlist::kSettingsGroup);
	s.setValue("RatingLocked", state);
}

Qt::Alignment PlaylistView::ColumnAlignment(int section) const
{
	return mColumnAlignment.value(section, Qt::AlignLeft | Qt::AlignHCenter);
}