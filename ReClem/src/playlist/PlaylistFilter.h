#pragma once
#include <qsortfilterproxymodel.h>


class PlaylistFilter : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	PlaylistFilter(QObject* parent);
	~PlaylistFilter();

	// QAbstractItemModel
	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
};

