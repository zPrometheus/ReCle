#include "IconLoader.h"
#include "core/Utilities.h"
#include <qsettings.h>
#include "core/Appearance.h"
#include <QtDebug>
#include <core/logging.h>
#include <qdir.h>
#include "core/logging.h"

QList<int> IconLoader::mSizes;
QString IconLoader::mCustomIconPath;
QList<QString> IconLoader::mIconSubPath;
bool IconLoader::mUseSysIcons;

void IconLoader::Init() {
	mSizes.clear();
	mSizes << 22 << 32 << 48;
	mCustomIconPath = Utilities::GetConfigPath(Utilities::Path_Icons);
	mIconSubPath.clear();
	mIconSubPath << "/icons" << "/provides" << "last.fm" << "";
	QSettings settings;
	settings.beginGroup(Appearance::kSettingsGroup);
	mUseSysIcons = settings.value("b_use_sys_icons", false).toBool();
}

QIcon IconLoader::Load(const QString& name, const IconType& icontype)
{
	QIcon ret;

	if (name.isEmpty()) {
		qLog(Warning) << "Icon name is null";
		return ret;
	}
#if QT_VERSION >= 0x040600
	if (mUseSysIcons) {
		ret = QIcon::fromTheme(name);
		if (!ret.isNull()) return ret;
	}
#endif

	// Set the icon load location based on IConType
	switch (icontype) {
	case Base:
	case Provider: {
		const QString custom_icon_location = mCustomIconPath
			+ mIconSubPath.at(icontype);
		qLog(Debug) << "Base Provider path is" << custom_icon_location;
		if (QDir(custom_icon_location).exists()) {
			const QString locate(custom_icon_location + "/%1x%2/%3.png");
			qLog(Debug) << "icon path is find";
			for (int size : mSizes) {
				QString filename_custom(locate.arg(size).arg(size).arg(name));

				if (QFile::exists(filename_custom)) ret.addFile(filename_custom,
					QSize(size, size));
			}
			if (!ret.isNull()) return ret;
		}

		const QString path(":" + mIconSubPath.at(icontype) + "/%1x%2/%3.png");
		for (int size : mSizes) {
			QString filename(path.arg(size).arg(size).arg(name));

			if (QFile::exists(filename)) ret.addFile(filename, QSize(size, size));
		}
		break;
	}
	case Lastfm:
	case Other: {
		// lastfm icons location
		const QString mCustomFmOtherIconLocation = mCustomIconPath
			+ mIconSubPath.at(icontype);
		qLog(Debug) << "Other icons path is" << mCustomFmOtherIconLocation;
		if (QDir(mCustomFmOtherIconLocation).exists()) {
			// Try to load icons from the custom icon location initially
			const QString locate_file(
				mCustomFmOtherIconLocation + "/" + name + ".png");

			if (QFile::exists(locate_file)) ret.addFile(locate_file);
			if (!ret.isNull()) return ret;
		}
		// Otherwise use our fallback theme
		const QString path_file(":" + mIconSubPath.at(icontype)
			+ "/" + name + ".png");

		if (QFile::exists(path_file)) ret.addFile(path_file);
		break;
	}
	default:
		// Should never be reached
		qLog(Warning) << "Couldn't recognize IconType" << name;
	}

	// Load icon from system theme only if it hasn't been found
	if (ret.isNull()) {
		ret = QIcon::fromTheme(name);
		if (!ret.isNull()) return ret;
		qLog(Warning) << "Couldn't load icon" << name;
	}
	return ret;
}



IconLoader::~IconLoader()
{
}
