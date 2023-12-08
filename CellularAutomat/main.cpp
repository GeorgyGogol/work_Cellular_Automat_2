#include "stdafx.h"
#include "AppCore.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppCore appCore(&a);
    appCore.Run();
    return a.exec();
}

