#include "LogIn.h"
#include <QtWidgets/QApplication>
#include "AddCity.h"
#include "Admin.h"
#include "MWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MWindow w;
    w.show();
    return a.exec();
}
