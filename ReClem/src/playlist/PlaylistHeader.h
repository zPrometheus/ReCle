#pragma once
#include "widgets/StretchHeaderView.h"
class PlaylistView;
class QMenu;
class PlaylistHeader : public StretchHeaderView
{
public:
	Q_OBJECT
	PlaylistHeader(Qt::Orientation orientation,PlaylistView* view,
		QWidget* parent);
	~PlaylistHeader();

	void contextMenuEvent(QContextMenuEvent* e);

	private:
		void AddColumnAction(int index);
private:
	int mMenuSection;
	QMenu *mMenu;
	QAction* mHideAction;
	QAction* mRatingLock;
	QAction* mStretchAction;
	QAction* mAlignLeftAction;
	QAction* mAlignRightAction;
	QAction* mAlignCenterAction;
	PlaylistView* mView;
};

