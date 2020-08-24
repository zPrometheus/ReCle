#include "StretchHeaderView.h"

const int StretchHeaderView::kMinimumColumnWidth = 20;
const int StretchHeaderView::kMagicNumber = 0x502c950f;
StretchHeaderView::StretchHeaderView(Qt::Orientation orientation, QWidget* parent)
	:QHeaderView(orientation, parent), mStretchEnabled(false),
	mInMouseMoveEvent(false)
{
	connect(this, SIGNAL(sectionResized(int, int, int)), SLOT(SectionResized(int, int, int)));
	setMinimumSectionSize(kMinimumColumnWidth);

}

void StretchHeaderView::SectionResized(int logical, int OldSize, int NewSize)
{
	if (!mStretchEnabled)
		return;
	if (mInMouseMoveEvent) {
		mColumnWidths[logical] = ColumnWidthType(NewSize) / width();

		int visual = visualIndex(logical);
		QList<int> LogicalSectionsToResize;
		for (int i = 0; i < count(); i++)
		{
			if (!isSectionHidden(i) && visualIndex(i) > visual)
				LogicalSectionsToResize << i;
		}
		//......to be continued ,


	}

}

bool StretchHeaderView::RestoreState(const QByteArray& data)
{
	QDataStream s(data);
	s.setVersion(QDataStream::Qt_5_11);
	int MagicNumber;
	s >> MagicNumber;
	if (MagicNumber != kMagicNumber || s.atEnd())
		return false;

	QList<int> PixelWidths;
	QList<int> VisualIndices;
	int SortIndicatorOrder = Qt::AscendingOrder;
	int SortIndicatorSection = 0;

	s >> mStretchEnabled;
	s >> PixelWidths;
	s >> VisualIndices;
	s >> mColumnWidths;
	s >> SortIndicatorOrder;
	s >> SortIndicatorSection;
	
	setSortIndicator(SortIndicatorSection,Qt::SortOrder(SortIndicatorOrder));
	const int PersistedColumnCount =
		qMin(qMin(VisualIndices.count(), PixelWidths.count()), mColumnWidths.count());

	// Set column visible state, visual indices and, if we're not in stretch mode,
	// pixel widths.
	for (int i = 0; i < count() && i < PersistedColumnCount; ++i) {
		setSectionHidden(i, PixelWidths[i] <= kMinimumColumnWidth);
		moveSection(visualIndex(VisualIndices[i]), i);

		if (!mStretchEnabled) {
			resizeSection(i, PixelWidths[i]);
		}
	}

	// Have we added more columns since the last time?
	while (mColumnWidths.count() < count()) {
		mColumnWidths << 0;
	}

	if (mStretchEnabled) {
		// In stretch mode, we've already set the proportional column widths so
		// apply
		// them now.
		UpdateWidths();
	}

	emit StretchEnabledChanged(stretch_enabled_);

	return true;
}

void StretchHeaderView::setModel(QAbstractItemModel* model)
{
	QHeaderView::setModel(model);
}

StretchHeaderView::~StretchHeaderView()
{


}
