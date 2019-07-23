#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    ui->errorMessage->setText("Guest account granted (default)...");
}

loginWindow::~loginWindow()
{
    delete ui;
}

// Albert Le
// 7/22/19 5:38 pm lastest edit

// Opens a login window, allowing the user to enter
// a username and password and to click on an "Enter"
// button. If username and password are not the correct
// login information, it will output an error message.
// It defaults the user to a guest account. If they enter
// the correct username and pw, then it will output an
// "Admin access granted" message, and then the user can
// exit the login window. It should pass an argument (a bool)
// to MainWindow.

void loginWindow::on_loginButton_clicked()
{
    if (ui->usernameInput->toPlainText() == "qtAdmin" &&
        ui->passwordInput->toPlainText() == "qtPW")
    {
        ui->errorMessage->setText("Admin access granted...");

        // put in flag to pass to MainWindow. Perhaps a bool.
    }
    else
    {
        ui->errorMessage->setText("Incorrect login for admin access.");
    }

}

void loginWindow::on_closeWindow_clicked()
{
    this->close();
}
