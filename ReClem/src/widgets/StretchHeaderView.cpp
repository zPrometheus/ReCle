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

void StretchHeaderView::setModel(QAbstractItemModel* model)
{
	QHeaderView::setModel(model);
}

StretchHeaderView::~StretchHeaderView()
{


}
