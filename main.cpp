#include "loginwindow.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow w;
    MainWindow w2;
    //RenderArea w3;


    w2.show();
    w.show();

    //w3.show();

    return a.exec();
}
