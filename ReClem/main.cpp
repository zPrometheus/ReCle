#include "ReClem.h"
#include <QtWidgets/QApplication>
#include "ui/IconLoader.h"

int main(int argc, char *argv[])
{
	IconLoader::Init();
    QApplication a(argc, argv);
    ReClem w;
    w.show();
    return a.exec();
}
