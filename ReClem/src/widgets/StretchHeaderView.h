#pragma once
#include "qheaderview.h"
class StretchHeaderView :
	public QHeaderView
{
	Q_OBJECT
public:
	StretchHeaderView(Qt::Orientation orientation,QWidget* parent=nullptr);
	~StretchHeaderView();

	typedef double ColumnWidthType;
	static const int kMinimumColumnWidth;
	static const int kMagicNumber;

	void setModel(QAbstractItemModel* model);

	bool isStretchEnabled() const { return mStretchEnabled; };
private:
	bool mStretchEnabled;
	bool mInMouseMoveEvent;
	QVector<ColumnWidthType> mColumnWidths;



	private slots:
	void SectionResized(int logical, int OldSize, int NewSize);
	

};

