#include <QtGui/QApplication>
#include "mainwindow.h"
#include "configmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setQuitOnLastWindowClosed(false);
    ConfigManager config;

    QString login = config.getLogin();
    if(login == "")
    {
        w.show();
    }

    return a.exec();
}
