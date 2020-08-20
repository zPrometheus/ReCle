#pragma once
#include "qheaderview.h"
class StretchHeaderView :
	public QHeaderView
{
	Q_OBJECT
public:
	StretchHeaderView(Qt::Orientation orientation,QWidget* parent=nullptr);
	~StretchHeaderView();

	bool isStretchEnabled() const { return mStretchEnabled; };
private:
	bool mStretchEnabled;


};

