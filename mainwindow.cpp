#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "vector.h"
#include "shapeParser.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//workaround until canvas completed
void MainWindow::paintEvent(QPaintEvent * /* event */)
{
        //workaround until canvas completed
        myVector<Shape*> shapeVect;
        myVector<Shape*>::iterator p;
        inputShape(shapeVect);

        for (p = shapeVect.begin(); p < shapeVect.end(); p++)
        {
            (*p)->draw(this);
        }
}
