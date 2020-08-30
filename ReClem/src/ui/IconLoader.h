#pragma once
#include <qicon.h>
class IconLoader
{
public:
	enum IconType {
		Base = 0,
		Provider = 1,
		Lastfm = 2,
		Other = 3
	};
	static void Init();
	static QIcon Load(const QString& name, const IconType& icontype);
public:
	
	~IconLoader();
private:
	IconLoader() {};
	static QList<int> mSizes;
	static QString mCustomIconPath;
	static QList<QString> mIconSubPath;
	static bool mUseSysIcons;
};

