#pragma once
#include <qtreeview.h>
class Playlist;
class Application;
class PlaylistView:public QTreeView
{
public:
	PlaylistView(QWidget* parent = nullptr);

	static const int kStateVersion;
	static const char* kSettingBackgroundImageType;
	static const char* kSettingBackgroundImageFilename;

	static const int kDefaultBlurRadius;//ģ���İ뾶��
	static const int kDefaultOpacityLevel;//��͸���ļ���

	void SetApplication(Application* app);
	void SetPlaylist(Playlist* play);
	void SetReadOnlySettings(bool readonly) { mReadOnlySettings = readonly; }

	void DrawTree(QPainter* painter, const QRegion& region) const;
	void SetModel(QAbstractItemModel* model);
private:
	bool mReadOnlySettings;

};

