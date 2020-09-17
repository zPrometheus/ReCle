#include "Utilities.h"
#include <qdir.h>
#include <qapplication.h>
#include "core/Application.h"
#include <qstandardpaths.h>


namespace Utilities {

	QString GetConfigPath(ConfigPath config)
	{
		switch (config)
		{
			case Path_Root: {
				if (Application::IsPortable())
				{
					QDir d(QCoreApplication::applicationDirPath());
					return d.filePath(Application::kPortableDataDir);
				}
				//QDir d(QDir::currentPath());
				return QDir::currentPath() + "/data";
					//QString("%1/%2").arg(
					/*QStandardPaths::writableLocation(QStandardPaths::ConfigLocation),
					QCoreApplication::organizationName());*/
					
			}break;

			case Path_CacheRoot:
			{
				if (Application::kIsPortable) {
					return GetConfigPath(Path_Root) + "/cache";
				}
#if defined(Q_OS_UNIX) 
				return QString("%1/%2").arg(QStandardPaths::writableLocation(
					QStandardPaths::GenericCacheLocation),
					QCoreApplication::organizationName());
#else
				return GetConfigPath(Path_Root);
#endif
			} break;

			case Path_Icons:
				return GetConfigPath(Path_Root) + "/customiconset";

			case Path_AlbumCovers:
				return GetConfigPath(Path_Root) + "/albumcovers";

			case Path_NetworkCache:
				return GetConfigPath(Path_CacheRoot) + "/networkcache";

			case Path_MoodbarCache:
				return GetConfigPath(Path_CacheRoot) + "/moodbarcache";

			case Path_PixmapCache:
				return GetConfigPath(Path_CacheRoot) + "/pixmapcache";

			case Path_GstreamerRegistry:
				return GetConfigPath(Path_Root) +
					QString("/gst-registry-%1-bin")
					.arg(QCoreApplication::applicationVersion());
			case Path_DefaultMusicLibrary:
				return QDir::homePath();

			case Path_LocalSpotifyBlob:
				return GetConfigPath(Path_Root) + "/spotifyblob";

			default:
				qFatal("%s", Q_FUNC_INFO);
				return QString();
			}

		}
}