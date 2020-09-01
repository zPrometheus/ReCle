#pragma once
#include "widgets/StretchHeaderView.h"
class PlaylistView;
class QMenu;
class PlaylistHeader : public StretchHeaderView
{

	Q_OBJECT
public:
	PlaylistHeader(Qt::Orientation orientation,PlaylistView* view,
		QWidget* parent);
	~PlaylistHeader();
	
	void enterEvent(QEvent*);
	void contextMenuEvent(QContextMenuEvent* e);


signals:
	void SectionVisibilityChanged(int logical, bool visible);
	void MouseEntered();
	void SectionRatingLockStatusChanged(bool state);

	private:
		void AddColumnAction(int index);

		private slots:
		void ToggleVisible(int section);
		void HideCurrent();
		void ToggleRatingEditStatus();
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
	QList<QAction*> mShowAction;
};

