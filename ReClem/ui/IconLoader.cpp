#include "IconLoader.h"
#include "core/Utilities.h"
#include <qsettings.h>
#include "core/Appearance.h"

IconLoader::IconLoader()
{
}

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


IconLoader::~IconLoader()
{
}
