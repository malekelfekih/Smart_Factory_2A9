#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QWidget>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    // Log In
    QString username = ui->username->text();
    QString password = ui->password->text();
    QSqlQuery qry;
    if (qry.exec("SELECT * FROM login WHERE username = '" + username +
                 "' and password = '" + password + "' ")) {
      int count = 0;
      while (qry.next()) {
        count++;
      }
      if (count == 1) {
        QMessageBox::information(this, tr("Log In"), tr("Logged In"));
        hide();
        client = new MainWindow(this);
        client->show();
        //return true;
      }
      if (count < 1) {
        QMessageBox::information(this, tr("Log In"), tr("Error"));
        //return false;
      }}
}
