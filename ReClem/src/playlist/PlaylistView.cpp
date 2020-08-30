#include "PlaylistView.h"
#include "PlaylistHeader.h"
#include "ui/IconLoader.h"

PlaylistView::PlaylistView(QWidget* parent)
	:QTreeView(parent), mHeader(new PlaylistHeader(Qt::Horizontal, this, this))
{
	setHeader(mHeader);
	mHeader->setSectionsMovable(true);
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
	mHeader->setFirstSectionMovable(true);
#endif
	//QIcon currenttrack_play =
	//	IconLoader::Load("currenttrack_play", IconLoader::Other);
	/*currenttrack_play_ =
		currenttrack_play.pixmap(currenttrack_play.actualSize(QSize(32, 32)));
	QIcon currenttrack_pause =
		IconLoader::Load("currenttrack_pause", IconLoader::Other);
	currenttrack_pause_ =
		currenttrack_pause.pixmap(currenttrack_pause.actualSize(QSize(32, 32)));


		*/
}

Qt::Alignment PlaylistView::ColumnAlignment(int section) const
{
	return mColumnAlignment.value(section, Qt::AlignLeft | Qt::AlignHCenter);
}