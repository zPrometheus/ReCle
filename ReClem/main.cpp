#include "ReClem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReClem w;
    w.show();
    return a.exec();
}
