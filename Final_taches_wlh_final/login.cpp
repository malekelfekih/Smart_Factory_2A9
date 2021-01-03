#include "login.h"
#include "gestion_clients_cf.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
  ui->setupUi(this);
}

Login::~Login() { delete ui; }

int Login::on_pushButton_clicked() {
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
      client = new Gestion_Clients_CF(this);
      client->show();
      return true;
    }
    if (count < 1) {
      QMessageBox::information(this, tr("Log In"), tr("Error"));
      return false;
    }
  }
}

/*Login::Login() {
  this->username = "";
  this->mdp = "";
}
Login::Login(QString, QString) {
  this->username = username;
  this->mdp = mdp;
}*/
