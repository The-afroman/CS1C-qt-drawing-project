#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QWidget>
#include <QtWidgets>
#include "loginwindow.h"
#include "contactwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderArea = new RenderArea;
    setCentralWidget(renderArea);


    ui->spinBox_2->setRange(-1000,1000);
    ui->spinBox_3->setRange(-500,500);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);

    ui->spinBox_4->setRange(-1000,1000);
    ui->spinBox_5->setRange(-500,500);
    ui->spinBox_4->setValue(0);
    ui->spinBox_5->setValue(0);

    ui->spinBox_6->setRange(-1000,1000);
    ui->spinBox_7->setRange(-500,500);
    ui->spinBox_6->setValue(0);
    ui->spinBox_7->setValue(0);

    ui->spinBox_8->setRange(-1000,1000);
    ui->spinBox_9->setRange(-500,500);
    ui->spinBox_8->setValue(0);
    ui->spinBox_9->setValue(0);

    ui->spinBox_10->setRange(-1000,1000);
    ui->spinBox_11->setRange(-500,500);
    ui->spinBox_10->setValue(0);
    ui->spinBox_11->setValue(0);

    ui->spinBox_12->setRange(-1000,1000);
    ui->spinBox_13->setRange(-500,500);
    ui->spinBox_12->setValue(0);
    ui->spinBox_13->setValue(0);

    ui->spinBox_14->setRange(-1000,1000);
    ui->spinBox_15->setRange(-500,500);
    ui->spinBox_14->setValue(0);
    ui->spinBox_15->setValue(0);

    ui->spinBox_16->setRange(-1000,1000);
    ui->spinBox_17->setRange(-500,500);
    ui->spinBox_16->setValue(0);
    ui->spinBox_17->setValue(0);
}

void MainWindow::on_pushButton_clicked()
{
    cout << "button!!!!\n\n";
    int ofsetAr[8][2];
    renderArea->saveShapes(ofsetAr, 8);
}

void MainWindow::paintEvent(QPaintEvent * /* event */)
{
   // ui->spinBox_2->value();
   // ui->spinBox_3->value();

   // if admin access is granted, then any changes made to the spinBoxes will
   // move the shapes. However, if logged in as a guest (a.k.a. no admin access),
   // then updating the values in the spinBoxes will have no effect whatsoever
    if (adminAccessGranted)
    {
        renderArea->updatePoints(ui->spinBox_2->value(),ui->spinBox_3->value(),
                                 ui->spinBox_4->value(), ui->spinBox_5->value(),
                                 ui->spinBox_6->value(), ui->spinBox_7->value(),
                                 ui->spinBox_8->value(), ui->spinBox_9->value(),
                                 ui->spinBox_10->value(), ui->spinBox_11->value(),
                                 ui->spinBox_12->value(), ui->spinBox_13->value(),
                                 ui->spinBox_14->value(), ui->spinBox_15->value(),
                                 ui->spinBox_16->value(), ui->spinBox_17->value());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
