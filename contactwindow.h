#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QMainWindow>

namespace Ui {
class contactWindow;
}

class contactWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit contactWindow(QWidget *parent = nullptr);
    ~contactWindow();

private:
    Ui::contactWindow *ui;
};

#endif // CONTACTWINDOW_H
