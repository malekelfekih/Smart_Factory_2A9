#include "connection.h"
#include <QDebug>
#include <QSqlDatabase>

connection::connection() {}

bool connection::openConn() {
  bool test = false;
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

  db.setHostName("127.0.0.1");
  db.setDatabaseName("Source_Projet2A");
  db.setUserName("dhia3");      // inserer nom de l'utilisateur
  db.setPassword("dh14326410"); // inserer mot de passe de cet utilisateur

  if (db.open())
    test = true;

  return test;
}

void connection::closeConn(QSqlDatabase mydb) {
  mydb.close();
  mydb.removeDatabase(QSqlDatabase::defaultConnection);
}
