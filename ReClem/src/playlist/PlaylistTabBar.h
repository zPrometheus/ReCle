#pragma once
#include <qtabbar.h>


class PlaylistTabBar : public QTabBar
{
	Q_OBJECT
public:
	PlaylistTabBar(QWidget* parent= nullptr);
	~PlaylistTabBar();

private:
	QAction* mNew;
	QAction* mRename;
	QAction* mClose;
	QAction* mSave;
};

