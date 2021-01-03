#include "gestion_clients_cf.h"
#include "arduino.h"
#include "cf.h"
#include "client.h"
#include "connection.h"
#include "login.h"
#include "stat.h"
#include "ui_gestion_clients_cf.h"
#include "ui_stat.h"
#include <QSerialPort>
#include <QSerialPortInfo>

Gestion_Clients_CF::Gestion_Clients_CF(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Gestion_Clients_CF) {
  ui->setupUi(this);
  setWindowTitle("Clients");

  setWindowIcon(QIcon(":/resc/resc/clients.ico"));

  scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(scene);
  QLabel *processLabel = new QLabel();
  QMovie *movie = new QMovie(":/resc/resc/welcome.gif");
  processLabel->setGeometry(160, 80, 266, 200);
  processLabel->setMovie(movie);
  movie->start();
  proxy = scene->addWidget(processLabel);

  player = new QMediaPlayer(this);
  player->setMedia(QUrl("qrc:/resc/resc/Welcome.mp3"));
  player->setVolume(10);
  player->play();
}

Gestion_Clients_CF::~Gestion_Clients_CF() { delete ui; }

void Gestion_Clients_CF::on_add_clicked() {
  QString nom = ui->nom->text();
  QString prenom = ui->prenom->text();
  QString cin = ui->cin->text();
  QString hbd = ui->hbd->text();
  QString mail = ui->mail->text();
  QString num = ui->num_phone->text();

  if (nom == "" || prenom == "" || cin == "" || mail == "" || num == "") {
    QMessageBox::critical(nullptr, QObject::tr("Add"),
                          QObject::tr("clientty Fields .\n"
                                      "Click Cancel to exit."),
                          QMessageBox::Cancel);
    return;
  }
  if (cin.length() != 8 || num.length() != 8) {
    QMessageBox::information(
        nullptr, QObject::tr("Add"),
        QObject::tr("CIN of Phone Number invalid length (8) .\n"
                    "Click Cancel to exit."),
        QMessageBox::Cancel);
    return;
  }
  bool test2 = false;
  for (int i = 0; i < mail.length(); i++) {
    if (mail[i] == "@")
      test2 = true;
  }
  if (test2 == false) {
    QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Invalid mail .\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    return;
  }

  if (num[0] == "9" || num[0] == "2" || num[0] == "2")
    test2 = true;

  if (num[0] == "9")
    operateur = "Telecom";
  if (num[0] == "2")
    operateur = "Ooredoo";
  if (num[0] == "5")
    operateur = "Orange";

  if (test2 == false) {
    QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Invalid Phone Number .\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    return;
  }

  client e(nom, prenom, cin, hbd, num, mail, operateur);
  QMessageBox msgBox;
  bool test = e.ajouter();
  if (test) {
    QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("User Added.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    QSqlQueryModel *model = new QSqlQueryModel();
    model = E.afficher();
    ui->tableView->setModel(model);
    ui->cin_2->setModel(model);
    ui->crit_delet->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Operateur"));
    cf c0("", 0);
    QString ID = c0.generateID();
    int solde = 0;
    cf c(ID, solde);
    test = c.ajouter(cin);
  } else {
    QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Error.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
  }
}

void Gestion_Clients_CF::Gestion_Clients_CF::on_stats_clicked() {
  int res;
  Stat w(this);
  w.setWindowTitle("Statistiques des operateurs");

  res = w.exec();
  if (res == QDialog::Rejected)
    return;
}

void Gestion_Clients_CF::Gestion_Clients_CF::on_display_clicked() {
  QSqlQueryModel *model = new QSqlQueryModel();
  model = E.display(mydb);
  ui->tableView->setModel(model);
  ui->cin_2->setModel(model);
  ui->crit_delet->setModel(model);
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de naissance"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Operateur"));
}

void Gestion_Clients_CF::on_tri_clicked() {
  int choix;
  cf carteF;
  choix = ui->critere->currentIndex();
  qDebug() << choix;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (ui->up->isChecked())
    model = E.triUP(choix);
  else if (ui->down->isChecked())
    model = E.triDOWN(choix);
  else
    model = E.afficher();
  ui->tableView->setModel(model);
  ui->cin_2->setModel(model);
  ui->crit_delet->setModel(model);
}

void Gestion_Clients_CF::Gestion_Clients_CF::on_search_clicked() {
  int choix;
  choix = ui->critere->currentIndex();
  QString crit = ui->crit->text();
  QString found2;

  if (crit == "") {
    QMessageBox::critical(nullptr, QObject::tr("Search"),
                          QObject::tr("Empty Search Field .\n"
                                      "Click Cancel to exit."),
                          QMessageBox::Cancel);
  } else {

    QAbstractItemModel *model = ui->tableView->model();
    int found = 0;
    QSqlQueryModel *model2 = new QSqlQueryModel();
    for (int i = 0; i < model->rowCount(); i++) {
      for (int j = 0; j < model->columnCount(); j++) {
        QString test = ui->tableView->model()->index(i, j).data().toString();
        if (crit == test) {
          found = j;
          found2 = QString::number(found);
          qDebug() << "found = " + found2;
          if (found == 0) {
            QString test2 =
                ui->tableView->model()->index(found, i).data().toString();

            model2 = E.chercher2(test2);
          }
          if (found == 1) {
            QString test2 =
                ui->tableView->model()->index(found - 1, i).data().toString();

            model2 = E.chercher2(test2);
          }
          if (found == 2) {
            QString test2 =
                ui->tableView->model()->index(found - 2, i).data().toString();

            model2 = E.chercher2(test2);
          }
          if (found == 3) {
            QString test2 =
                ui->tableView->model()->index(found - 3, i).data().toString();

            model2 = E.chercher2(test2);
          }
          if (found == 4) {
            QString test2 =
                ui->tableView->model()->index(found - 4, i).data().toString();

            model2 = E.chercher2(test2);
          }
          if (found == 5) {
            QString test2 =
                ui->tableView->model()->index(found - 5, i).data().toString();

            model2 = E.chercher2(test2);
          }
          if (found == 6) {
            QString test2 =
                ui->tableView->model()->index(found - 6, i).data().toString();

            model2 = E.chercher2(test2);
          }
        }
      }
    }

    QSqlQueryModel *model1 = new QSqlQueryModel();

    model1 = E.chercher(choix, crit);

    ui->tableView->setModel(model1);
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de naissance"));
    model1->setHeaderData(6, Qt::Horizontal, QObject::tr("Operateur"));

    ui->tableView_2->setModel(model2);
    model2->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model2->setHeaderData(1, Qt::Horizontal, QObject::tr("Solde"));
    model2->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
  }
}

void Gestion_Clients_CF::Gestion_Clients_CF::on_pushButton_5_clicked() {
  // modifier
  QString nom = ui->nom_2->text();
  QString prenom = ui->prenom_2->text();
  QString cin = ui->cin_2->currentText();
  QString mail = ui->mail_2->text();
  QString hbd = ui->hbd_2->text();
  QString num = ui->num_phone_2->text();

  if (num[0] == "9")
    operateur = "Telecom";
  if (num[0] == "2")
    operateur = "Ooredoo";
  if (num[0] == "5")
    operateur = "Orange";

  // QString ID =

  if (nom == "" || prenom == "" || cin == "" || mail == "" || num == "" ||
      operateur == "") {
    QMessageBox::critical(nullptr, QObject::tr("Update"),
                          QObject::tr("Empty Fields .\n"
                                      "Click Cancel to exit."),
                          QMessageBox::Cancel);
    return;
  }
  if (cin.length() != 8 || num.length() != 8) {
    QMessageBox::information(
        nullptr, QObject::tr("Update"),
        QObject::tr("CIN of Phone Number invalid length (8) .\n"
                    "Click Cancel to exit."),
        QMessageBox::Cancel);
    return;
  }
  bool test2 = false;
  for (int i = 0; i < mail.length(); i++) {
    if (mail[i] == "@")
      test2 = true;
  }
  if (test2 == false) {
    QMessageBox::information(nullptr, QObject::tr("Update"),
                             QObject::tr("Invalid mail .\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    return;
  }

  client E;
  E.setcin(cin);
  if (E.verifier_cin_client(cin) == true) {
    if (E.update_client(nom, prenom, cin, mail, hbd, num, operateur)) {
      QMessageBox::information(nullptr, QObject::tr("Updated"),
                               QObject::tr("CIN found.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);
      E.afficher();
    } else
      QMessageBox::information(nullptr, QObject::tr("Update Failed"),
                               QObject::tr("Error.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);
  } else
    QMessageBox::information(nullptr, QObject::tr("Update Failed"),
                             QObject::tr("CIN not found.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
  on_display_clicked();
}

void Gestion_Clients_CF::Gestion_Clients_CF::on_delete_2_clicked() {
  client e;
  e.setcin(ui->crit_delet->currentText());
  QString cin = e.getcin();
  QMessageBox msgBox;
  bool test = e.verifier_cin_client(cin);
  if (test) {
    e.supprimer(e.getcin());
    QMessageBox::information(nullptr, QObject::tr("Deleted"),
                             QObject::tr("CIN found.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    ui->tableView->setModel(e.afficher());
  } else
    QMessageBox::information(nullptr, QObject::tr("Delete Failed"),
                             QObject::tr("CIN not found.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
  on_display_clicked();
}

void Gestion_Clients_CF::on_pushButton_clicked() {
  // imprimer
  QString description = ui->description->toPlainText();
  QString objet = ui->objet->text();
  QString title = "Réclamation.pdf";
  E.create_pdf(description, objet, title);
}

void Gestion_Clients_CF::on_pushButton_2_clicked() {
  // afficher CF
  QSqlQueryModel *model = new QSqlQueryModel();
  model = carteF.displayCF(mydb);
  ui->tableView_2->setModel(model);
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Solde"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
}
