#pragma once

#include <qobject.h>

class Application:public QObject
{
	Q_OBJECT
public:
	Application(QObject* parent);
	~Application();


	void DirtySettings();
};

