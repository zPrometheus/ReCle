#pragma once
#include <qstring.h>
namespace Utilities
{
	enum ConfigPath {
		Path_Root,
		Path_Icons,
		Path_AlbumCovers,
		Path_NetworkCache,
		Path_GstreamerRegistry,
		Path_DefaultMusicLibrary,
		Path_LocalSpotifyBlob,
		Path_MoodbarCache,
		Path_PixmapCache,
		Path_CacheRoot,
	};
	QString GetConfigPath(ConfigPath config);
};

