#include "Application.h"



Application::Application(QObject* parent)
	:QObject(parent)
{
	setObjectName("Clementine Application");

}

void Application :: DirtySettings()
{
	mP->mSettingsTimer.start();
}

Application::~Application()
{


}
