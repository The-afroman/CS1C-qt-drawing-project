#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include "vector.h"
#include "shape.h"
#include "canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

private:
    //void move();
    void paintEvent(QPaintEvent * /* event */);
    Ui::MainWindow *ui;
    RenderArea *renderArea;
};

#endif // MAINWINDOW_H
