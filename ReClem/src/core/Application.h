#pragma once

#include <qobject.h>

#include <memory>
#include <qtimer.h>
#include "core/Appearance.h"
#include "core/Application.h"

class Application;
class ApplicationImpl;


class Application:public QObject
{
	Q_OBJECT
public:
	static bool kIsPortable;
	static const char* kPortableDataDir;

	Application(QObject* parent);
	~Application();

	static bool IsPortable() { return kIsPortable; }

	void DirtySettings();

private :
	std::unique_ptr<ApplicationImpl> mP;
};

