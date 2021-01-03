#ifndef LOGIN_H
#define LOGIN_H

#include "gestion_clients_cf.h"
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog {
  Q_OBJECT

public:
  explicit Login(QWidget *parent = nullptr);
  ~Login();

private slots:
  int on_pushButton_clicked();

private:
  Ui::Login *ui;
  Gestion_Clients_CF *client;

  QString username;
  QString mdp;
};

#endif // LOGIN_H
