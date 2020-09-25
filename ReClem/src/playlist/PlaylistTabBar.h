#pragma once
#include <qtabbar.h>


class PlaylistTabBar : public QTabBar
{
	Q_OBJECT
public:
	PlaylistTabBar(QWidget* parent= nullptr);
	~PlaylistTabBar();
	int current_id() const;
	void set_current_id(int id);
	int index_of(int id) const;
private:
	QAction* mNew;
	QAction* mRename;
	QAction* mClose;
	QAction* mSave;
};

