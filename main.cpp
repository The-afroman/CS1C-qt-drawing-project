#include "mainwindow.h"
#include <QApplication>

#include "readinshapes.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    readInShapes();

    return a.exec();
}
