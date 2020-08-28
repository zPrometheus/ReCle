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

	bool RestoreState(const QByteArray& data);

	void HideSection(int logical);

	void ShowSection(int logical);

	void SetSectionHiddenOrShow(int logical, int hidden);
signals:
	void StretchEnabledChanged(bool enabled);
private:
	bool mStretchEnabled;
	bool mInMouseMoveEvent;
	QVector<ColumnWidthType> mColumnWidths;

private:
	void NormaliseWidths(const QList<int>& sections = QList<int>());
	void UpdateWidths(const QList<int>& sections = QList<int>());
	private slots:
	void SectionResized(int logical, int OldSize, int NewSize);
	

};

