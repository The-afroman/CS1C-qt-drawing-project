#include "loginwindow.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow w;
    MainWindow w2;
    w.show();
    w2.show();

    return a.exec();
}
