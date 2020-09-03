#include "PlaylistFilter.h"
//#include <qabstractitemmodel.h>


PlaylistFilter::PlaylistFilter(QObject* parent)
{

}

// QAbstractItemModel
void PlaylistFilter::sort(int column, Qt::SortOrder order)
{
	sourceModel()->sort(column, order);
}

PlaylistFilter::~PlaylistFilter()
{


}

bool PlaylistFilter::filterAcceptsRow(int row,
	const QModelIndex& parent) const {
	QString filter = filterRegExp().pattern();

	uint hash = qHash(filter);
	if (hash != query_hash_) {
		// Parse the query
		FilterParser p(filter, column_names_, numerical_columns_);
		filter_tree_.reset(p.parse());

		query_hash_ = hash;
	}

	// Test the row
	return filter_tree_->accept(row, parent, sourceModel());
}
