#include "PlaylistView.h"

PlaylistView::PlaylistView(QWidget* parent)
	:QTreeView(parent)
{


}

Qt::Alignment PlaylistView::ColumnAlignment(int section) const
{
	return mColumnAlignment.value(section, Qt::AlignLeft | Qt::AlignHCenter);
}