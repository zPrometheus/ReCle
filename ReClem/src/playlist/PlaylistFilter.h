#pragma once
#include <qsortfilterproxymodel.h>
#include <QSet>
#include <QScopedPointer>
class FilterTree;

class PlaylistFilter : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	PlaylistFilter(QObject* parent);
	~PlaylistFilter();

	// QAbstractItemModel
	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
	bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const;

private:
	mutable QScopedPointer<FilterTree> mFilterTree;
	mutable uint mQueryHash;

	QMap<QString, int> mColumnNames;
	QSet<int> mNumericalColumns;

};

