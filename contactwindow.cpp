#include "contactwindow.h"
#include "ui_contactwindow.h"

contactWindow::contactWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::contactWindow)
{
    ui->setupUi(this);
}

contactWindow::~contactWindow()
{
    delete ui;
}
