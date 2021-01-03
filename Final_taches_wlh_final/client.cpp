#include "client.h"
#include "cf.h"
#include "gestion_clients_cf.h"
#include "ui_gestion_clients_cf.h"
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPrinter>
#include <QSqlDatabase>
#include <Qt>
#include <QtSql>

client::client() {
  this->cin = "";
  this->hbd = "";
  this->mail = "";
  this->nom = "";
  this->num = "";
  this->prenom = "";
}

client::client(QString nom, QString prenom, QString cin, QString hbd,
               QString num, QString mail, QString operateur) {
  this->cin = cin;
  this->hbd = hbd;
  this->mail = mail;
  this->nom = nom;
  this->num = num;
  this->prenom = prenom;
  this->operateur = operateur;
}

void client::setnom(QString nom) { this->nom = nom; }
void client::setprenom(QString prenom) { this->prenom = prenom; }
void client::setcin(QString cin) { this->cin = cin; }
void client::sethbd(QString hbd) { this->hbd = hbd; }
void client::setmail(QString mail) { this->mail = mail; }
void client::setnum(QString num) { this->num = num; }

bool client::ajouter() {
  cf carteF;
  QSqlQuery query1, query;
  query.prepare("INSERT INTO client "
                "(cin,name,prenom,mail,phone,hbd,operateur) "
                "Values "
                "(:cin,:nom,:prenom,:mail,:phone,:hbd,:operateur) ");
  query.bindValue(":cin", cin);
  query.bindValue(":nom", nom);
  query.bindValue(":prenom", prenom);
  query.bindValue(":mail", mail);
  query.bindValue(":phone", num);
  query.bindValue(":hbd", hbd);
  query.bindValue(":operateur", operateur);
  return (query.exec());
}

QSqlQueryModel *client::afficher() {
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery(
      "select cin,name,prenom,mail,phone,hbd,operateur FROM client ;");
  return model;
}

bool client::supprimer(QString cin) {
  QSqlQuery query;
  query.prepare(" Delete from client where cin=:cin");
  query.bindValue(0, cin);
  cf carteF;
  bool test = carteF.supprimer(cin);
  return (query.exec() && test);
}

QSqlQueryModel *client::chercher2(QString text) {
  if (text == "") {
    QMessageBox::critical(nullptr, QObject::tr("Search"),
                          QObject::tr("Empty Search Field .\n"
                                      "Click Cancel to exit."),
                          QMessageBox::Cancel);
  }
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();
  query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM cf where "
                "cin like '" +
                text + "'");
  query.exec();
  model->setQuery(query);

  return model;
}

QSqlQueryModel *client::chercher(int test, QString text) {
  if (text == "") {
    QMessageBox::critical(nullptr, QObject::tr("Search"),
                          QObject::tr("Empty Search Field .\n"
                                      "Click Cancel to exit."),
                          QMessageBox::Cancel);
  }
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();
  if (test == 0) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where name like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  if (test == 1) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where prenom like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  if (test == 2) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where cin like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  if (test == 3) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where mail like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  if (test == 4) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where hbd like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  if (test == 5) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where phone like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  if (test == 6) {
    query.prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur FROM client "
                  "where operateur like '" +
                  text + "'");
    query.exec();
    model->setQuery(query);
  }

  return model;
}

bool client::verifier_cin_client(QString cin) {
  QSqlQuery query;
  bool test = false;
  query.prepare("Select cin FROM client where cin = '" + cin + "' ");
  if (query.exec() && query.next()) {
    test = true;
    return test;
  }
  return test;
}

bool client::update_client(QString nom, QString prenom, QString cin,
                           QString mail, QString hbd, QString num,
                           QString operateur) {
  if (num[0] == "9")
    operateur = "Telecom";
  if (num[0] == "2")
    operateur = "Ooredoo";
  if (num[0] == "5")
    operateur = "Orange";
  QSqlQuery query;
  query.prepare(
      "update client set name= :nom , prenom= :prenom , mail= :mail, "
      "phone= :phone , hbd= :hbd , operateur = :operateur where cin= :cin ");
  query.bindValue(":cin", cin);
  query.bindValue(":nom", nom);
  query.bindValue(":prenom", prenom);
  query.bindValue(":mail", mail);
  query.bindValue(":phone", num);
  query.bindValue(":hbd", hbd);
  query.bindValue(":operateur", operateur);
  return query.exec();
}

QSqlQueryModel *client::display(QSqlDatabase mydb) {
  QSqlQueryModel *modal = new QSqlQueryModel();
  QMessageBox msg;
  QPixmap icon(":/resc/resc/clients.ico");
  msg.setIconPixmap(icon);
  msg.setWindowTitle("Load");
  QSqlQuery *qry = new QSqlQuery(mydb);

  qry->prepare("SELECT cin,name,prenom,mail,phone,hbd,operateur "
               "FROM client");
  if (qry->exec())
    msg.setText("LOADED");
  else
    msg.setText("LOAD Error");
  msg.exec();

  modal->setQuery(*qry);
  return modal;
}

QSqlQueryModel *client::triUP(int test) {
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (test == 0) {
    query.prepare(" SELECT * FROM client ORDER BY name asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 1) {
    query.prepare(" SELECT * FROM client ORDER BY prenom asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 2) {
    query.prepare(" SELECT * FROM client ORDER BY cin asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 3) {
    query.prepare(" SELECT * FROM client ORDER BY mail asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 4) {
    query.prepare(" SELECT * FROM client ORDER BY phone asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 5) {
    query.prepare(" SELECT * FROM client ORDER BY hbd asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 6) {
    query.prepare(" SELECT * FROM client ORDER BY operateur asc; ");
    query.exec();
    model->setQuery(query);
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de naissance"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Operateur"));

  return model;
}

QSqlQueryModel *client::triDOWN(int test) {
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (test == 0) {
    query.prepare(" SELECT * FROM client ORDER BY name desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 1) {
    query.prepare(" SELECT * FROM client ORDER BY prenom desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 2) {
    query.prepare(" SELECT * FROM client ORDER BY cin desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 3) {
    query.prepare(" SELECT * FROM client ORDER BY mail desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 4) {
    query.prepare(" SELECT * FROM client ORDER BY phone desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 5) {
    query.prepare(" SELECT * FROM client ORDER BY hbd desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 6) {
    query.prepare(" SELECT * FROM client ORDER BY operateur desc; ");
    query.exec();
    model->setQuery(query);
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de naissance"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Operateur"));

  return model;
}

void client::create_pdf(QString description, QString objet, QString title) {
  QPdfWriter pdf("C:/Users/hp/Desktop/Reclamation.pdf");
  QPainter painter(&pdf);

  painter.setPen(Qt::red);
  painter.drawText(100, 100, "Objet :");
  painter.setPen(Qt::black);
  painter.drawText(1000, 100, objet);

  painter.setPen(Qt::red);
  painter.drawText(100, 350, "Description :");
  painter.setPen(Qt::black);
  painter.drawText(1000, 350, description);

  const QString classesRoot = "HKEY_CLASSES_ROOT";

  // get ID of .pdf extension
  QSettings pdfSettings(classesRoot + "\\.pdf", QSettings::NativeFormat);
  QString pdfId = pdfSettings.value("Default").toString();

  // get path to default program that associated with PDF files
  QString printPath =
      QSettings(classesRoot + "\\" + pdfId + "\\shell\\print\\command",
                QSettings::NativeFormat)
          .value("Default")
          .toString();
  QString openPath =
      QSettings(classesRoot + "\\" + pdfId + "\\shell\\open\\command",
                QSettings::NativeFormat)
          .value("Default")
          .toString();

  // open .pdf file
  QProcess::startDetached(openPath.arg("C:/Users/hp/Desktop/Reclamation.pdf"));

  // print .pdf file
  QProcess printProcess;
  printProcess.start(printPath.arg("C:/Users/hp/Desktop/Reclamation.pdf"));
  printProcess.waitForFinished(-1);
}

int client::calculer(QString operateur) {
  QSqlQuery query;
  query.prepare("select * from client "
                "where operateur = :operateur");
  query.bindValue(":operateur", operateur);

  query.exec();
  int total = 0;
  while (query.next()) {
    total++;
  }

  return total;
}
