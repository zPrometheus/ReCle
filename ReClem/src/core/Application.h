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
	Application(QObject* parent);
	~Application();


	void DirtySettings();

private :
	std::unique_ptr<ApplicationImpl> mP;
};

