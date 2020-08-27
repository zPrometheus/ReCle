#pragma once
#include <qtreeview.h>
#include "Playlist.h"
class Application;
class PlaylistView:public QTreeView
{
public:
	PlaylistView(QWidget* parent = nullptr);

	static const int kStateVersion;
	static const char* kSettingBackgroundImageType;
	static const char* kSettingBackgroundImageFilename;

	static const int kDefaultBlurRadius;//模糊的半径？
	static const int kDefaultOpacityLevel;//不透明的级别？

	Qt::Alignment ColumnAlignment(int section) const;

	void SetApplication(Application* app);
	void SetPlaylist(Playlist* play);
	void SetReadOnlySettings(bool readonly) { mReadOnlySettings = readonly; }

	void DrawTree(QPainter* painter, const QRegion& region) const;
	void SetModel(QAbstractItemModel* model);
private:
	bool mReadOnlySettings;
	ColumnAlignmentMap mColumnAlignment;
};

