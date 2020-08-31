#include "IconLoader.h"
#include "core/Utilities.h"
#include <qsettings.h>
#include "core/Appearance.h"
#include <QtDebug>
#include <core/logging.h>

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

}

IconLoader::~IconLoader()
{
}
