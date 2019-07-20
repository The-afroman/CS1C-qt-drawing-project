#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QWidget>
#include <QtWidgets>
#include "vector.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    renderArea = new RenderArea;
    ui->setupUi(this);
    MainWindow::setCentralWidget(renderArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}
