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
		if (!LogicalSectionsToResize.isEmpty()) {
			mInMouseMoveEvent = false;
			UpdateWidths(LogicalSectionsToResize);
			NormaliseWidths(LogicalSectionsToResize);
			mInMouseMoveEvent = true;
		}
	}

}

void StretchHeaderView::UpdateWidths(const QList<int>& sections)
{
	if (!mStretchEnabled) return;
	ColumnWidthType TotalW = 0.0;

	for (int i = 0; i < mColumnWidths.count(); i++)
	{
		const ColumnWidthType w = mColumnWidths[i];
		int pixels = w * width();

		if (pixels != 0 && TotalW - int(TotalW) > 0.5) pixels++;

		TotalW += w;

		if (!sections.isEmpty() && !sections.contains(i)) continue;

		if (pixels == 0 && !isSectionHidden(i))
			hideSection(i);
		else if (pixels != 0 && isSectionHidden(i))
			showSection(i);
		if (pixels != 0)
			resizeSection(i, pixels);
	}

}

void StretchHeaderView::NormaliseWidths(const QList<int> & sections)
{
	if (!mStretchEnabled) return;

	const ColumnWidthType TotalSum =
		std::accumulate(mColumnWidths.begin(), mColumnWidths.end(), 0.0);
	ColumnWidthType SelectedSum = TotalSum;

	if (!sections.isEmpty())
	{
		SelectedSum = 0.0;
		for (int i = 0; i < count(); i++)
			if (sections.contains(i)) SelectedSum += mColumnWidths[i];
	}
	if (TotalSum != 0.0 && !qFuzzyCompare(TotalSum, 1.0)) {
		const ColumnWidthType mult =
			(SelectedSum + (1.0 - TotalSum)) / SelectedSum;
		for (int i = 0; i < mColumnWidths.count(); ++i) {
			if (sections.isEmpty() || sections.contains(i)) mColumnWidths[i] *= mult;
		}
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

	emit StretchEnabledChanged(mStretchEnabled);

	return true;
}

void StretchHeaderView::setModel(QAbstractItemModel* model)
{
	QHeaderView::setModel(model);
}

void StretchHeaderView::HideSection(int logical)
{
	// Would this hide the last section?
	bool all_hidden = true;
	for (int i = 0; i < count(); ++i) {
		if (i != logical && !isSectionHidden(i) && sectionSize(i) > 0) {
			all_hidden = false;
			break;
		}
	}
	if (all_hidden) {
		return;
	}

	if (!mStretchEnabled) {
		hideSection(logical);
		return;
	}

	mColumnWidths[logical] = 0.0;
	NormaliseWidths();
	UpdateWidths();

}

void StretchHeaderView::ShowSection(int logical)
{
	if (!mStretchEnabled) {
		showSection(logical);
		return;
	}

	// How many sections are visible already?
	int visible_count = 0;
	for (int i = 0; i < count(); ++i) {
		if (!isSectionHidden(i)) visible_count++;
	}

	mColumnWidths[logical] = visible_count == 0 ? 1.0 : 1.0 / visible_count;
	NormaliseWidths();
	UpdateWidths();

}

void StretchHeaderView::SetSectionHiddenOrShow(int logical,int hidden)
{
	if (hidden)
		HideSection(logical);
	else
		ShowSection(logical);
}
StretchHeaderView::~StretchHeaderView()
{


}
