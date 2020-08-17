#pragma once
#include <QWidget>

class Ui_playlistcontainer;
class QLabel;
class QTimeLine;
class Application;

class PlaylistContainer :public QWidget
{
	Q_OBJECT
public:
	PlaylistContainer(QWidget* parent = nullptr);
	
	~PlaylistContainer();

private:
	Ui_playlistcontainer* ui;
	QAction* mUndo;
	QAction* mRedo;
	QLabel* mNoMatchesLabel;
	QTimeLine* mTabBarAnimation;

	bool mDirty;
	Application* mApp;

	private slots:
	void SetTabBarHeight(int height);
	void DirtyTabBar(void);

	
};

