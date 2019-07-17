#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

// Albert Le
// 7/16/19 11:18 pm lastest edit

// Opens a login window, allowing the user to enter
// a username and password and to click on an "Enter"
// button. If username and password are not "temp" and
// "pw" respectively, then the window will display an
// error message after clicking the "Enter" button.

// If username and password are correct, then the window
// will automatically close after clicking "Enter".
void loginWindow::on_loginButton_clicked()
{
    if (ui->usernameInput->toPlainText() == "temp" &&
        ui->passwordInput->toPlainText() == "pw")
    {
        this->close();
    }
    else
    {
        ui->errorMessage->setText("Use 'temp' and 'pw' for a guest account");
    }
}
