#include "Application.h"

bool Application::kIsPortable = false;
const char* Application::kPortableDataDir = nullptr;

class ApplicationImpl {
public:
	ApplicationImpl(Application* app)
		:mSettingsTimer(app) {


	}

	QTimer mSettingsTimer;
};


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
