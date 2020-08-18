#pragma once
#include <qtabbar.h>


class PlaylistTabBar : public QTabBar
{
	Q_OBJECT
public:
	PlaylistTabBar(QWidget* parent= nullptr);
	~PlaylistTabBar();
	int current_id() const;
private:
	QAction* mNew;
	QAction* mRename;
	QAction* mClose;
	QAction* mSave;
};

