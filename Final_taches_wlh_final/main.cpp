#include "connection.h"
#include "gestion_clients_cf.h"
#include "login.h"
#include <QApplication>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QtSql>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  connection c;
  bool test = c.openConn();

  int res;
  Login w2;
  w2.setWindowTitle("Log In");
  res = w2.exec();

  Gestion_Clients_CF w;

  if (test) {
    w.show();
  } else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                          QObject::tr("connection failed.\n"
                                      "Click Cancel to exit."),
                          QMessageBox::Cancel);

  return a.exec();
}
