#include "cf.h"
#include "client.h"
#include "gestion_clients_cf.h"
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPrinter>
#include <QSqlDatabase>
#include <Qt>
#include <QtSql>

cf::cf() {
  this->ID = "";
  this->solde = 0;
}

cf::cf(QString ID, int solde) {
  this->ID = ID;
  this->solde = solde;
}

QString cf::generateID() {
  const QString possibleCharacters(
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  const int randomStringLength =
      8; // assuming you want random strings of 8 characters

  QString randomString;
  for (int i = 0; i < randomStringLength; ++i) {
    int index = qrand() % possibleCharacters.length();
    QChar nextChar = possibleCharacters.at(index);
    randomString.append(nextChar);
  }
  return randomString;
}

bool cf::ajouter(QString cin) {
  QSqlQuery query1;
  QString ID = generateID();
  int solde = 0;
  query1.prepare("INSERT INTO cf (cf_id,solde,cin) Values (:id,:solde,:cin) ");
  query1.bindValue(":cin", cin);
  query1.bindValue(":id", ID);
  query1.bindValue(":solde", solde);

  return (query1.exec());
}

QSqlQueryModel *cf::displayCF(QSqlDatabase mydb) {
  QSqlQueryModel *modal = new QSqlQueryModel();
  QMessageBox msg;
  QPixmap icon(":/resc/resc/clients.ico");
  msg.setIconPixmap(icon);
  msg.setWindowTitle("Load");
  QSqlQuery *qry = new QSqlQuery(mydb);

  qry->prepare("SELECT * FROM cf");
  if (qry->exec())
    msg.setText("LOADED");
  else
    msg.setText("LOAD Error");
  msg.exec();

  modal->setQuery(*qry);
  return modal;
}

bool cf::supprimer(QString cin) {
  QSqlQuery query;
  query.prepare(" Delete from cf where cin=:cin");
  query.bindValue(0, cin);
  return query.exec();
}

QSqlQueryModel *cf::triUP(int test) {
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (test == 7) {
    query.prepare(" SELECT * FROM cf ORDER BY cf_id asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 8) {
    query.prepare(" SELECT * FROM cf ORDER BY solde asc; ");
    query.exec();
    model->setQuery(query);
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Solde"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));

  return model;
}

QSqlQueryModel *cf::triDOWN(int test) {
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (test == 7) {
    query.prepare(" SELECT * FROM cf ORDER BY cf_id desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 8) {
    query.prepare(" SELECT * FROM cf ORDER BY solde desc; ");
    query.exec();
    model->setQuery(query);
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Solde"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));

  return model;
}
