#include "mainwindow.h"
#include <QApplication>
#include "shapeParser.h"
int main(int argc, char *argv[])
{
    inputShape("shapes.txt");
    cout << "hello world";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
