#pragma once
#include <QWidget>
#include <qtimer.h>

class Ui_playlistcontainer;
class QLabel;
class QTimeLine;
class Application;
class QSettings;
class Playlist;
class PlaylistView;
class PlaylistManager;

class PlaylistContainer :public QWidget
{
	Q_OBJECT
public:
	PlaylistContainer(QWidget* parent = nullptr);
	
	~PlaylistContainer();

	static const char* kSettingsGroup;
	static const int kFilterDelayMs;

	PlaylistView* view() const;
	void setViewModel(Playlist*);

private:
	Ui_playlistcontainer* ui;
	QAction* mUndo;
	QAction* mRedo;
	QLabel* mNoMatchesLabel;
	QTimeLine* mTabBarAnimation;

	bool mDirty;
	bool mStartingUp;
	Application* mApp;
	QTimer* mFilterTimer;

	Playlist* mPlist;
	PlaylistManager* mManager;

	private slots:
	void SetTabBarHeight(int height);
	void DirtyTabBar(void);
	void UpdateFilter();
	void SelectionChanged();
	void UpdateNoMatchesLabel();
	void RepositionNoMatchesLabel(bool force);

	void Save(QSettings* settings);
signals:
	void ViewSelectionModelChanged();
};

