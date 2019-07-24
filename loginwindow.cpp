#include "loginwindow.h"
#include "ui_loginwindow.h"

bool adminAccessGranted = false;

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
// 7/23/19 8:19 pm lastest edit

// Opens a login window, allowing the user to enter
// a username and password and to click on an "Enter"
// button. If username and password are not the correct
// login information, it will output an error message.
// It defaults the user to a guest account. If they enter
// the correct username and pw, then it will output an
// "Admin access granted" message, and then the user can
// exit the login window. Updates the global variable
// adminAccessGranted to true so that MainWindow knows
// the user has admin access.

void loginWindow::on_loginButton_clicked()
{
    if (ui->usernameInput->toPlainText() == "qtAdmin" &&
        ui->passwordInput->toPlainText() == "qtPW")
    {
        ui->errorMessage->setText("Admin access granted...\n Use 'temp' and 'pw' to login as guest");

        // updates global variable to be true so communicate to MainWindow that user has admin access
        adminAccessGranted = true;
    }
    else if (ui->usernameInput->toPlainText() == "temp" &&
             ui->passwordInput->toPlainText() == "pw")
    {
        ui->errorMessage->setText("Logged in as guest");
        adminAccessGranted = false;
    }
    else
    {
        if (!adminAccessGranted)
        {
            ui->errorMessage->setText("Incorrect login for admin access. \n(logged in as guest)");
        }
        else
        {
            ui->errorMessage->setText("Use 'temp' and 'pw' to go back to guest \n(logged in as admin)");
        }
    }
}

void loginWindow::on_closeWindow_clicked()
{
    this->close();
}
