#pragma once
#include <qtreeview.h>
#include "Playlist.h"
class Application;
class PlaylistHeader;
class PlaylistView:public QTreeView
{
public:
	PlaylistView(QWidget* parent = nullptr);

	static const int kStateVersion;
	static const char* kSettingBackgroundImageType;
	static const char* kSettingBackgroundImageFilename;
	static const int kAutoscrollGraceTimeout;  // seconds
	static const int kDefaultBlurRadius;//ģ���İ뾶��
	static const int kDefaultOpacityLevel;//��͸���ļ���

	Qt::Alignment ColumnAlignment(int section) const;

	void SetApplication(Application* app);
	void SetPlaylist(Playlist* play);
	void SetReadOnlySettings(bool readonly) { mReadOnlySettings = readonly; }

	void DrawTree(QPainter* painter, const QRegion& region) const;
	void SetModel(QAbstractItemModel* model);

	private slots:
	void DirtyGeometry();
	void SetRatingLockStatus(bool state);
	void InvalidateCachedCurrentPixmap();
	void PlaylistView::InhibitAutoscrollTimeout();

private:
	bool mReadOnlySettings;
	ColumnAlignmentMap mColumnAlignment;
	PlaylistHeader* mHeader;
	QPixmap mCurrentTrackPlay;
	QPixmap mCurrentTrackPause;
	QPixmap mCacheCurrentRow;
	bool mDirtyGeometry;
	Application* mApp;
	bool mRatingLocked;
	QTimer* mInhibitAutoScrollTimer;
	bool mInhibitAutoscroll;
};

