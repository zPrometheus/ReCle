#pragma once
#include <qcolor.h>
#include <qobject.h>

class Appearance:public QObject
{
public:
	Appearance(QObject* parent=nullptr);
	~Appearance();

	static const char* kSettingsGroup;
};

