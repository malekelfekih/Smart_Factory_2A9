#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "machine.h"
#include "fichesuivi.h"
#include "statistiques.h"
#include "machinefiche.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include<QIntValidator>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include<QTextDocument>
#include<QPdfWriter>
#include<QFileInfo>
#include<QFileDialog>
#include<QPrintDialog>
#include<QDebug>
#include "demande.h"
#include "employee.h"

#include <QTextLength>
#include <QColor>
#include<QModelIndex>
#include <QSqlQueryModel>
#include <QStaticStringData>

#include "cf.h"
#include "client.h"

#include "admin.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->tab_Machine->setModel(M.afficher());
    ui->comboBoxchercher->addItem("num_serie");
    ui->comboBoxchercher->addItem("CAPACITE_PRODUCTION");
    ui->comboBoxchercher->addItem("PUISSANCE_MOTEUR");
    ui->comboBoxchercher->addItem("NB_HEURE");
     ui->tab_Fiche->setModel(FS.afficher());
     ui->comboBoxchercher1->addItem("num_modele");
     ui->comboBoxchercher1->addItem("age");
     ui->comboBoxchercher1->addItem("etat");
     ui->comboBoxetat->addItem("Bon etat");
     ui->comboBoxetat->addItem("Panne");
     ui->comboBoxetat->addItem("ne fonctionne plus");
     ui->comboBoxetat1->addItem("Bon etat");
     ui->comboBoxetat1->addItem("Panne");
     ui->comboBoxetat1->addItem("ne fonctionne plus");


     ui->comboBoxnum->setModel(M.affichermachine());

     ui->comboBoxnummodele->setModel(FS.afficher1());

    ui->machinefiche->setModel(MF.affichermachinefiche());
     ui->comboBoxnumfiche->setModel(MF.affichermodele());
     ui->comboBoxnummachine->setModel(MF.afficherserie());

     ui->comboBoxchercher11->addItem("num_modele_fiche");
     ui->comboBoxchercher11->addItem("num_serie_machine");

     //*******Fournisseur**************
     ui->le_code->setValidator(new QIntValidator(0, 9999999, this));
     ui->le_num->setValidator(new QIntValidator(0, 9999999, this));
    ui->comboBoxchercher_2->setModel(c.afficherfournisseur());
     ui->comboBoxchercher_3->setModel(c.afficherfournisseur());

     ui->comboBox_id->setModel(c.afficherid());
       ui->comboBox_code->setModel(F.affichercode());


     ui->comboBox_p->addItem("matieres premieres");
     ui->comboBox_p->addItem("machines");
     ui->comboBox_pm->addItem("matieres premieres");
     ui->comboBox_pm->addItem("machines");

     ui->comboBox_s->addItem("matieres premieres");
     ui->comboBox_s->addItem("machines");
     ui->comboBox_sm->addItem("matieres premieres");
     ui->comboBox_sm->addItem("machines");

     ui->comboBox_m->addItem("cheque");
     ui->comboBox_m->addItem("especes");
     ui->comboBox_mpm->addItem("cheque");
     ui->comboBox_mpm->addItem("especes");



     ui->comboBox->addItem("identifiant");
     ui->comboBox->addItem("produits");
     ui->comboBox->addItem("date_commande");
     ui->comboBox->addItem("mode_paiment");
     ui->comboBox->addItem("montant");
     ui->comboBox->addItem("code_fournisseur");



     ui->comboBox_2->addItem("code");
     ui->comboBox_2->addItem("nom");
     ui->comboBox_2->addItem("adresse");
     ui->comboBox_2->addItem("num_tel");
     ui->comboBox_2->addItem("service");
     ui->comboBox_2->addItem("debut_contrat");
     ui->comboBox_2->addItem("Fin_contrat");
     ui->comboBox_2->addItem("courriel");

     ui->id->setValidator(new QIntValidator(0,999999999,this));
     ui->tab_fournisseur->setModel(F.afficher());
     ui->tab_commande->setModel(c.afficher());

     //**************employes

     ui->le_id->setValidator(new QIntValidator(10,999999,this));
      ui->le_cin->setValidator(new QIntValidator(10000000,99999999,this));
      ui->le_tel->setValidator(new QIntValidator(10,99999999,this));
      ui->le_salaire->setValidator(new QIntValidator(10,99999,this));
      ui->line_id->setValidator(new QIntValidator(10,999999,this));

      ui->comboBox_id2->setModel(E.afficher1());
      ui->comboBox_id_em->setModel(d.afficher2());
      ui->comboBox_id3->setModel(d.afficher3());
      ui->comboBox_id4->setModel(d.afficher4());



      ui->table_employee_2->setModel(E.afficher());
      ui->liste_demande->setModel(d.afficher_demande());



      ui->table_conges->setModel(d.afficher_demande());

      //***************************client
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

     //**********Arduino
        int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//*******************************machine

void MainWindow::on_pushButtonajouter_clicked()
{   QString num_serie=ui->LEnum->text();
    int capacite_production=ui->LEcapacite->text().toInt() ;
    int puissance_moteur=ui->LEpuissance->text().toInt();
    int nb_heure=ui->LEnb->text().toInt();


   Machine M(num_serie,capacite_production,puissance_moteur,nb_heure);

    QMessageBox msgBox;
 if (M.verifvidestring(M.getnum_serie())==true&&M.verifvideint(M.getcapacite_production())==true&&M.verifvideint(M.getpuissance_moteur())==true&&M.verifvideint(M.getnb_heure())==true)
    {bool test=M.ajouter();
     if(test)
      {  msgBox.setText("Ajout avec succes.");
         msgBox.exec();
        ui->tab_Machine->setModel(M.afficher());
    }
     else
         {msgBox.setText("Echec d'ajout");
         msgBox.exec();
     }}
    else
        {msgBox.setText("Echec d'ajout");
        msgBox.exec();
     }
 ui->comboBoxnummachine->setModel(M.afficher());
 ui->comboBoxnum->setModel(M.afficher());

}


void MainWindow::on_pushButtonsupprimer_clicked()
{
    Machine M1;
    M1.setnum_serie(ui->comboBoxnum->currentText());
    QString num_serie;
    QMessageBox msgBox;
    bool test=M1.supprimer(M1.getnum_serie());
        if(test)
           {
            msgBox.setText("Suppression avec succes");
            ui->tab_Machine->setModel(M1.afficher());
        }
        else
         msgBox.setText("Echec de suppression");
            msgBox.exec();



}



void MainWindow::on_pushButtonrecherche_clicked()
{
    int choix;
      choix=ui->comboBoxchercher->currentIndex();
      QString LErecherche=ui->LErecherche->text();

         ui->tab_Machine->setModel(M.chercher(choix,LErecherche));

}

//consulter
void MainWindow::on_pushButton_2_clicked()
{
  ui->tab_Machine->setModel(M.consulternb());
}

//*******************************fiche

void MainWindow::on_pushButtonajouter1_clicked()
{   QString num_serie_machine,etat;
    int num_modele=ui->LEnum_2->text().toInt();
    int age=ui->LEage->text().toInt() ;
     etat=ui->comboBoxetat->currentText();
     QDate date= ui->LEdate->date();
     QString description=ui->LEDes->text();
     QString date_derniere_m= date.toString("dd/MM/yyyy");
     qDebug()<<date_derniere_m;
    Fichesuivi FS(num_modele,age,etat,date_derniere_m,description);
     QMessageBox msgBox;


if (FS.verifvideint1(FS.getnum_modele())==true&&FS.verifvideint1(FS.getage())==true&&FS.verifvidestring1(FS.getetat())==true&&FS.verifvidestring1(FS.getdescription())==true )
{bool test=FS.ajouter();

      if(test)
       {  msgBox.setText("Ajout avec succes.");
         msgBox.exec();
         ui->tab_Fiche->setModel(FS.afficher());
     }
      else
          msgBox.setText("Echec d'ajout");
          msgBox.exec();
          }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();


         ui->comboBoxnumfiche->setModel(FS.afficher());
         ui->comboBoxnummodele->setModel(FS.afficher());


}





void MainWindow::on_pushButtonmodifier_clicked()
{QString etat,num_serie_machine;
    int num_modele=ui->LEnum1->text().toInt();
     int age=ui->LEage1->text().toInt() ;
    etat=ui->comboBoxetat1->currentText();

     QString description=ui->LEDes1->text();
     QDate date= ui->LEdate1->date();
     QString date_derniere_m= date.toString("dd/MM/yyyy");
     qDebug()<<date_derniere_m;
     Fichesuivi FS(num_modele,age,etat,date_derniere_m,description);
     QMessageBox msgBox ;
     bool test=FS.verifiernum_modele1(num_modele);
     if (test&&FS.verifvideint1(FS.getage())==true&&FS.verifvidestring1(FS.getetat())==true&&FS.verifvidestring1(FS.getdate_derniere_m())==true&&FS.verifvidestring1(FS.getdescription())==true)
     { FS.modifier();

       msgBox.setText(("modification avec succes"));
         ui->tab_Fiche->setModel(FS.afficher());
     }
     else

         msgBox.setText("cette fiche n'existe pas");
        msgBox.exec();

}

void MainWindow::on_pushButtonsupprimer2_clicked()
{
    Fichesuivi F1;
    QString num_modele=ui->comboBoxnummodele->currentText() ;
    F1.setnum_modele(ui->comboBoxnummodele->currentText().toInt());

    QMessageBox msgBox;
    bool test=F1.supprimer(F1.getnum_modele());

    if(test)
       {
        msgBox.setText("Suppression avec succes.");
        ui->tab_Fiche->setModel(F1.afficher());

       }
    else
       msgBox.setText("Echec de suppression");
        msgBox.exec();



}


//statistiques
void MainWindow::on_pushButton_clicked()
{
    s=new Statistiques(this);
    s->show();
}

void MainWindow::on_pushButtonrecherche1_clicked()
{
    int choix;
      choix=ui->comboBoxchercher1->currentIndex();
      QString LErecherche1=ui->LErecherche1->text();
       ui->tab_Fiche->setModel(FS.chercher1(choix,LErecherche1));


}

//****************************machine ,fiche


void MainWindow::on_pushButtonajoutermf_clicked()
{
    QString num_serie_machine=ui->comboBoxnummachine->currentText();
    int num_modele_fiche=ui->comboBoxnumfiche->currentText().toInt();
    Machinefiche MF( num_serie_machine, num_modele_fiche);
    QMessageBox msgBox;


       bool test=MF.ajouter();
          if(test)
           {  msgBox.setText("Ajout avec succes.");
             msgBox.exec();
             ui->machinefiche->setModel(MF.affichermachinefiche());
          }

          else
              msgBox.setText("Echec d'ajout");
              msgBox.exec();


}


void MainWindow::on_pushButtonimprimer_clicked()
{  QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->machinefiche->model()->rowCount();
    const int columnCount = ui->machinefiche->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - COMmANDE LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> ****La fiche de suivi **** "+TT+"</strong></h1>"
        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->machinefiche->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->machinefiche->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->machinefiche->isColumnHidden(column)) {
                QString data =ui->machinefiche->model()->data(ui->machinefiche->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}
void MainWindow::on_pushButtonrecherche1_2_clicked()
{
    int choix;
      choix=ui->comboBoxchercher11->currentIndex();
      QString LEcherche11=ui->LEchercher11->text();
       ui->machinefiche->setModel(MF.chercher1(choix,LEcherche11));
}
//***************************Fournisseur*****************************************
void MainWindow::on_bouton_ajouter_clicked()
{

    int code =ui->le_code->text().toInt();
    QString nom=ui->le_nom->text();
    QString adresse=ui->adresse->text();
    int num_tel =ui->le_num->text().toInt();
    QString service=ui->comboBox_s->currentText();
    QString courriel=ui->le_courriel->text();
    QDate date=ui->date_dbc->date();
    QString debut_contrat= date.toString("dd/MM/yyyy");
    qDebug()<<debut_contrat;
    QDate date1=ui->date_fnc->date();
    QString Fin_contrat= date1.toString("dd/MM/yyyy");
    qDebug()<<Fin_contrat;


   Fournisseur F(code,nom,adresse,num_tel,service,debut_contrat,Fin_contrat,courriel);
  QMessageBox msgBox;

   if(F.verifvidestring(F.getnom())==true&&F.verifvidestring(F.getadresse())==true&&F.verifvidestring(F.getcourriel())==true&&F.verifint(F.getcode())==true&&F.verifint(F.getnum())==true)
   {
       bool test=F.ajouter();
     if(test)
       {  msgBox.setText("Ajout avec succes.");
         ui->tab_fournisseur->setModel(F.afficher());
     }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
   }

   else

      msgBox.setText("Echec d'ajout");
       msgBox.exec();


}


void MainWindow::on_bouton_supprimer_clicked()
{
    Fournisseur F1;
    F1.setcode(ui->comboBox_code->currentText().toInt());

    QMessageBox msgBox;
  bool test=F1.supprimer(F1.getcode());
    if(test)
      {  msgBox.setText("Suppression avec succes.");
        ui->tab_fournisseur->setModel(F.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}


void MainWindow::on_pb_ajouter_clicked()
{

    int id =ui->id->text().toInt();
    QString montant =ui->montant->text();
    QString produits=ui->comboBox_p->currentText();
    QDate date=ui->date->date();
    QString date_commande= date.toString("dd/MM/yyyy");
    qDebug()<<date_commande;
    QString mode_paiment=ui->comboBox_m->currentText();
   int code_fournisseur=ui->comboBoxchercher_2->currentText().toInt();
     qDebug()<<id;
     qDebug()<<montant;
     qDebug()<<code_fournisseur;
   Commande c(id,produits,date_commande,mode_paiment,montant, code_fournisseur);
    QMessageBox msgBox;

if(c.verifvidestring(c.getdate_commande())==true&&c.verifvidestring(c.getmontant())==true&&c.verifint(c.getid())==true)
  {
        bool test=c.ajouter();


   if(test==true)
     {  msgBox.setText("Ajout avec succes.");

       ui->tab_commande->setModel(c.afficher());
   }

   else

       msgBox.setText("Echec d'ajout");
       msgBox.exec();

}

else

   msgBox.setText("Echec d'ajout");
    msgBox.exec();

     ui->comboBox_id->setModel(c.afficher());
}

void MainWindow::on_pb_supprimer_clicked()
{
    Commande c1;
    c1.setid(ui->comboBox_id->currentText().toInt());
    int id;
      QMessageBox msgBox;

      bool test=c1.supprimer(c1.getid());
  if(test)
      {  msgBox.setText("Suppression avec succes.");
        ui->tab_commande->setModel(c.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();


}

void MainWindow::on_pb_modifier_clicked()//modifier fournisseur
{
           int num_tel=ui->num_m->text().toInt();
            int code=ui->code_m->text().toInt() ;
            QString adresse=ui->adresse_m->text();

            QString nom=ui->nom_m->text();
            QString service=ui->comboBox_sm->currentText();
            QDate date=ui->datedbc_m->date();
            QString debut_contrat= date.toString("dd/MM/yyyy");
            qDebug()<<debut_contrat;
            QDate date1=ui->datefnc_m->date();
            QString Fin_contrat= date1.toString("dd/MM/yyyy");
            qDebug()<<Fin_contrat;
            QString courriel=ui->courriel_m->text();

        Fournisseur F(code,nom,adresse,num_tel,service,debut_contrat,Fin_contrat,courriel);
        QMessageBox msgBox ;


        bool test=F.verifcode(code);
        if(test&&F.verifvidestring(F.getnom())==true&&F.verifvidestring(F.getadresse())==true&&F.verifvidestring(F.getcourriel())==true&&F.verifint(F.getcode())==true&&F.verifint(F.getnum())==true)

         {
            F.modifier();
            msgBox.setText(("modification avec succes"));
            ui->tab_fournisseur->setModel(F.afficher());
         }

            else

                msgBox.setText("ce fournisseur n'existe pas");
               msgBox.exec();

}


void MainWindow::on_pb_modifier_2_clicked()//modifier commande
{
    int id =ui->id_m->text().toInt();
    QString montant =ui->montant_m->text();
    QString mode_paiment=ui->comboBox_mpm->currentText();
    QDate date=ui->date_m->date();
    QString date_commande= date.toString("dd/MM/yyyy");
    qDebug()<<date_commande;
    QString produits=ui->comboBox_pm->currentText();
    int code_fournisseur=ui->comboBoxchercher_3->currentText().toInt();

 Commande c(id,produits,date_commande,mode_paiment,montant, code_fournisseur);
    QMessageBox msgBox ;
     bool test=c.verifid(id);
     if(test&&c.verifvidestring(c.getdate_commande())==true&&c.verifvidestring(c.getmontant())==true&&c.verifint(c.getid())==true)
     {
         c.modifier();
         msgBox.setText(("modification avec succes"));
         ui->tab_commande->setModel(c.afficher());


     }
     else

         msgBox.setText("cette commande n'existe pas");
         msgBox.exec();


}

void MainWindow::on_pb_chercher_clicked()
{

        int choix;
          choix=ui->comboBox->currentIndex();
          QString LErecherche=ui->LErecherche->text();

             ui->tab_commande->setModel(c.recherche(LErecherche,choix));


}

void MainWindow::on_pb_chercher_2_clicked()
{
    int choix1;
      choix1=ui->comboBox_2->currentIndex();
      QString LErecherche1=ui->LErecherche_2->text();

         ui->tab_fournisseur->setModel(F.recherche(LErecherche1,choix1));
}


void MainWindow::on_pb_imprimer_clicked()
{
      QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_commande->model()->rowCount();
        const int columnCount = ui->tab_commande->model()->columnCount();
        QString TT = QDate::currentDate().toString("yyyy/MM/dd");
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>ERP - COMmANDE LIST<title>\n "
            << "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> ***La liste des commandes *** "+TT+"</strong></h1>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tab_commande->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_commande->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_commande->isColumnHidden(column)) {
                    QString data =ui->tab_commande->model()->data(ui->tab_commande->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;

}
//**********************************employes*********************************

void MainWindow::on_ajouter_2_clicked()
{


   // QString id_string = QString :: number(id);

    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();

    QString adresse=ui->le_adresse->text();
    QString type_de_contarct=ui->le_type_contract->currentText();
    QString operateur;
      int id=ui->le_id->text().toInt();
 //   int id_string=ui->comboBox_id1->currentText();
    int cin=ui->le_cin->text().toInt();
    int num_telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString date_naissance=ui->line_naisance->text();
    QString date_embauche=ui->line_embauche->text();
    QString cin_string = QString :: number(cin);
    QString num_telephone_string = QString :: number(num_telephone);
   QString id_string = QString :: number(id);


    if (num_telephone_string[0] == "9")
        operateur = "Telecom";
      if (num_telephone_string[0] == "2")
        operateur = "Ooredoo";
      if (num_telephone_string[0] == "5")
        operateur = "Orange";

     //this->E.getDate_naissance().toString("yyyy.MM.dd");

  /* QString date_naissance_a= date_naissance.toString("dd/MM/yyyy");
    QString date_embauche_b= date_embauche.toString("dd/MM/yyyy");*/
   bool test2=false;
   for(int i=0 ; i<email.length();i++)
   {
       if(email[i]=="@")
           test2=true;

   }
   if(test2==false)
   {
       QMessageBox::information(nullptr, QObject::tr("ajout"),
                   QObject::tr("mail non valider.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       return;
   }



  bool test3=false;
  for(int i=0 ; i<cin_string.length();i++)
  {
     if(cin_string.length()==8 )
     {
        test3=true;
     }
     if(test3==false)
     {
         QMessageBox::information(nullptr, QObject::tr("ajout"),
                     QObject::tr("cin  non valider.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         return;
     }
  }



     bool test4=false;
     for(int i=0 ; i<num_telephone_string.length();i++)
     {
        if(num_telephone_string.length()==8 )
        {
           test4=true;
        }
        if(test4==false)
        {
            QMessageBox::information(nullptr, QObject::tr("ajout"),
                        QObject::tr("numéro de téléphone  non valider.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            return;
        }
     }




        bool test5=false;
        for(int i=0 ; i<id_string.length();i++)
        {
           if(id_string.length()==6 || id_string=="" )
           {
              test5=true;
           }
           if(test5==false)
           {
               QMessageBox::information(nullptr, QObject::tr("ajout"),
                           QObject::tr("identifiant  non valider.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               return;
           }
      }
     /* bool test6=false;
        for(int i=0 ; i<date_naissance.length();i++)
        {
           if(date_naissance[i] =="  /  /    ")
           {
              test6=true;
           }
           if(test6==false)
           {
               QMessageBox::information(nullptr, QObject::tr("ajout"),
                           QObject::tr("date de naissnace  non valider.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               return;
           }
      }*/

 EMPLOYEE E (nom, prenom , email ,  adresse, type_de_contarct, operateur, date_naissance, date_embauche ,id ,cin ,num_telephone, salaire  );

bool test=E.ajouter();
if(test)


{

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("add successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->table_employee_2->setModel(E.afficher());
     ui->comboBox_id2->setModel(E.afficher1());
     ui->comboBox_id_em->setModel(d.afficher2());

}
else

    QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("add failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}







/*void MainWindow::on_modifier_clicked()
{


    EMPLOYEE *E=new EMPLOYEE();

    E->setNom(ui->le_nom->text());
    E->setPrenom(ui->le_prenom->text());

    E->setAdresse(ui->le_adresse->text());
    E->setEmail(ui->le_email->text());
    E->setType_de_contract(ui->le_type_contract->currentText());


    E->setID(ui->le_id->text().toInt());
    E->setCIN(ui->le_cin->text().toInt());
    E->setNum_telephone(ui->le_tel->text().toInt());
    E->setSalaire(ui->le_salaire->text().toInt());


    E->setDate_naissance(ui->le_naissance->date());
    E->setDate_naissance(ui->le_embauche->date());


   EMPLOYEE E1 ; E1.setID(ui->le_identifiant_2->text().toInt());
     bool test=E1.modifier(E1.getID());
     QMessageBox msgBox;
     if(test)*/





  /*  bool test=E->modifier();

    QMessageBox msgBox;
    if(test)

    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("edit successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_employee_2->setModel(E->afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("edit failed.\n"

                                "Click Cancel to exit."), QMessageBox::Cancel);

}*/





void MainWindow::on_supprimer_2_clicked()
{
    EMPLOYEE E1 ; //E1.setID(ui->le_identifiant_2->text().toInt());
    E1.setID(ui->comboBox_id2->currentText().toInt());
    bool test=E1.supprimer(E1.getID());
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_employee_2->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}



void MainWindow::on_chercher_clicked()
{
    int choix;
    choix=ui->comboBox_rech->currentIndex();
     QString rech=ui->line_recherche->text();
    ui->table_employee_2->setModel(E.recherche(choix,rech));




}




void MainWindow::on_trier_clicked()
{
    int choix ;
    choix=ui->comboBox_rech_2->currentIndex();
    QSqlQueryModel * model =new QSqlQueryModel();

//ui->table_employee_2->sortByColumn(0,Qt::AscendingOrder);
//ui->table_employee_2->setModel(E.afficher());

  if(ui->radioButton_up->isChecked())
  model = E.trierup(choix);
  //ui->table_employee_2->setModel(E.afficher());

 else if(ui->radioButton_down->isChecked())
    model=E.trier_down(choix);
   // ui->table_employee_2->setModel(E.afficher());
  else
      model=E.afficher();

   ui->table_employee_2->setModel(model);


}



void MainWindow::on_envoyer_clicked()

{

QString identifiant=ui->line_id->text();
QString date_debut=ui->line_date_debut->text();
QString date_fin=ui->line_date_fin->text();
QString type_de_conge=ui->comboBox_type_conge->currentText();
QString etats;
int id=ui->comboBox_id_em->currentText().toInt();
demande d ( identifiant , date_debut , date_fin  ,etats, id,type_de_conge  );

QMessageBox msgBox;
 bool test=d. ajouter_demande();
 if (test)
 {     msgBox.setText("Envoie avec succes");
     ui->table_conges->setModel(d.afficher_demande());
      ui->comboBox_id3->setModel(d.afficher3());
        ui->comboBox_id4->setModel(d.afficher4());
     // ui->comboBox_id_em->setModel(d.afficher2());


 }
 else
     msgBox.setText("erreur d'envoie");
 msgBox.exec();

}

/*bool test1=false;
for(int i=0 ; i<date_debut.length();i++)
{
    if(date_debut[i]=="/ / / ")
        test1=true;

}
if(test1==false)
{
    QMessageBox::information(nullptr, QObject::tr("ajout"),
                QObject::tr("date_debut non valider.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}*/


 /*demande d ( identifiant , date_debut ,date_fin ,type_de_conge );


bool test=d.ajouter_demande();
if(test  )

{

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("add successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->table_conges->setModel(d.afficher_demande());

//if(identifiant.length()!=8)
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("add failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);





}*/















void MainWindow::on_mise_a_jour_clicked()
{


       //demande d1 ; d1.setIdentifiant(ui->le_identifiant_2->text().toInt());
     bool test=d.afficher_demande();
     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("la demande a été mise à jours .\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

           ui->liste_demande->setModel(d.afficher_demande());
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                     QObject::tr("la demande n'est pas mise à jours .\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);



}

/*void MainWindow::on_mise_a_jours_clicked()
{
    ui->liste_demande->setModel(d.afficher_demande());


    bool test=d.afficher_demande();
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("votre demande est accepter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_employee_2->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("votre demande n'est pas mise à jours .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
*/


void MainWindow::on_accepter_clicked()
{

   demande d1 ;
  // ui->comboBox_id4->setModel(d.afficher4());

    d1.setEtats(ui->comboBox_id4->currentText());
    bool test=d1.accepter(d1.getIdentifiant());

     QMessageBox msgBox ;


     if (test)
     {

       msgBox.setText(("modification avec succes"));

        ui->liste_demande->setModel(d.afficher_demande());
     }
     else

         msgBox.setText("non");
        msgBox.exec();

/*
if(test)
{

QString e ;

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("la demande est accepter.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     //ui->table_employee_2->setModel(E.afficher());
//e = d.getEtats();
//e = "Accepté";
//d.setEtats(e);

         //  d.getEtats() = d.etats_string(e);
            ui->liste_demande->setModel(d.afficher_demande());
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("erreur .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);*/



  }


void MainWindow::on_refuser_clicked()
{
    ui->liste_demande->setModel(d.afficher_demande());
    QMessageBox::information(nullptr, QObject::tr(" not ok"),
                QObject::tr("la demande est refuser.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->liste_demande->setModel(d.afficher_demande());

}





void MainWindow::on_supprimer_demande_clicked()
{
    demande d1 ;
    d1.setIdentifiant(ui->comboBox_id3->currentText());
    bool test=d1.supprimer_demande(d1.getIdentifiant());
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_conges->setModel(d.afficher_demande());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


/*
    EMPLOYEE E1 ; //E1.setID(ui->le_identifiant_2->text().toInt());
    E1.setID(ui->comboBox_sup_dem->currentText().toInt());
    bool test=E1.supprimer(E1.getID());
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_employee_2->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


*/



void MainWindow::on_recherche_demande_clicked()
{
    int choice;
    choice=ui->combo_re->currentIndex();

    QString re=ui->lineEdit_4->text();
   ui->table_conges->setModel(d.chercher_demande(choice,re));


}

void MainWindow::on_trier_les_demandes_clicked()
{
    int choix ;
    choix=ui->combobox_tri2->currentIndex();
    QSqlQueryModel * model =new QSqlQueryModel();

//ui->table_employee_2->sortByColumn(0,Qt::AscendingOrder);
//ui->table_employee_2->setModel(E.afficher());

  if(ui->up->isChecked())
  model = d.trier_up_demande(choix);
  //ui->table_employee_2->setModel(E.afficher());

 else if(ui->down->isChecked())
    model=d.trier_down_demande(choix);
   // ui->table_employee_2->setModel(E.afficher());
  else
      model=d.afficher_demande();

   ui->table_conges->setModel(model);

}


/*void MainWindow::on_stat_clicked()
{
    QSqlQuery query ;
    QSqlQueryModel * model =new QSqlQueryModel();
    stats s;
    model =s.returnNumber();
    ui->table_employee_2->setModel(model);
    QString nbr_employe=
    QString :: number(ui->table_employee_2->model()->index(0,0).data().toInt());
    model =E.afficher();
    ui->table_employee_2->setModel(model);
    QMessageBox msgbox;
    msgbox.setText("le nombre actuel des employes est " +nbr_employe +
                   "employes in the systm .");
    msgbox.exec();

}*/






void MainWindow::on_modifier_clicked()
{
   // click->play();

    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();

    QString adresse=ui->le_adresse->text();
    QString type_de_contarct=ui->le_type_contract->currentText();
    QString operateur;
      int id=ui->le_id->text().toInt();
 //   int id_string=ui->comboBox_id1->currentText();
    int cin=ui->le_cin->text().toInt();
    int num_telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString date_naissance=ui->line_naisance->text();
    QString date_embauche=ui->line_embauche->text();
    QString cin_string = QString :: number(cin);
    QString num_telephone_string = QString :: number(num_telephone);
   QString id_string = QString :: number(id);

  //EMPLOYEE E(QString nom, QString prenom ,QString email , QString adresse ,QString type_de_contract,QString operateur, QString date_naissance , QString date_embauche, int  id , int cin , int  num_telephone ,int salaire);


QMessageBox msgBox;



      bool test=E.modifier(nom, prenom , email ,  adresse, type_de_contarct , date_naissance ,date_embauche ,id ,cin ,num_telephone, salaire );

      if(test)
    {

        msgBox.setText("Modification avec succes !");
        ui->table_employee_2->setModel(E.afficher());


      }
      else
      {
          msgBox.setText("Modification échouée !");
  msgBox.exec();
      }
}


void MainWindow::on_modif_demande_clicked()
{
    QString identifiant=ui->line_id->text();
    QString date_debut=ui->line_date_debut->text();
     QString date_fin=ui->line_date_fin->text();
     QString type_de_conge=ui->comboBox_type_conge->currentText();

    // int id=ui->comboBox_id_em->currentText().toInt();


QMessageBox msgBox;



      bool test=d.modifier_demande(identifiant, date_debut , date_fin ,  type_de_conge );

      if(test)
    {

        msgBox.setText("Modification avec succes !");
         ui->table_conges->setModel(d.afficher_demande());
        // ui->comboBox_type_conge->setModel(d.afficher_demande());


      }
      else
      {
          msgBox.setText("Modification échouée !");
  msgBox.exec();
      }




}



void MainWindow::on_stat_clicked()
{
    /*int res;
    statistiques w(this);
    w.setWindowTitle("Statistiques des operateurs");

    res = w.exec();
    qDebug() << res;
    if (res == QDialog::Rejected)
      return;*/

}



//**************************************Arduino autoriser accés*************************
void MainWindow::update_label()
{

   data=A.read_from_arduino();

    if(data=="1")

      {  ui->label_57->setText("ON");
       }
}


void MainWindow::on_Demander_clicked()
{
  A.write_to_arduino("0");
  x++;
 QString x_string=QString::number(x);

    ui->label_54->setText(x_string);
       ui->label_57->setText("OFF");
       A.write_to_arduino("3");

}



//****************************client
void MainWindow::MainWindow::on_add_clicked() {
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

  client CL(nom, prenom, cin, hbd, num, mail, operateur);
  QMessageBox msgBox;
  bool test = CL.ajouter();
  if (test) {
    QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("User Added.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    QSqlQueryModel *model = new QSqlQueryModel();
    model = CL.afficher();
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

void MainWindow::MainWindow::on_stats_clicked() {
  /*int res;
  Stat w(this);
  w.setWindowTitle("Statistiques des operateurs");

  res = w.exec();
  if (res == QDialog::Rejected)
    return;*/
}

void MainWindow::MainWindow::on_display_clicked() {
  QSqlQueryModel *model = new QSqlQueryModel();
  model = CL.display(mydb);
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

void MainWindow::MainWindow::on_tri_clicked() {

    int choix;
      cf carteF;
      choix = ui->critere->currentIndex();
      qDebug() << choix;
      QSqlQueryModel *model = new QSqlQueryModel();

      if (ui->up->isChecked())
        model = CL.triUP(choix);
      else if (ui->down->isChecked())
        model = CL.triDOWN(choix);
      else
        model = CL.afficher();
      ui->tableView->setModel(model);
      ui->cin_2->setModel(model);
      ui->crit_delet->setModel(model);
}

void MainWindow::MainWindow::on_search_clicked() {
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

            model2 = CL.chercher2(test2);
          }
          if (found == 1) {
            QString test2 =
                ui->tableView->model()->index(found - 1, i).data().toString();

            model2 = CL.chercher2(test2);
          }
          if (found == 2) {
            QString test2 =
                ui->tableView->model()->index(found - 2, i).data().toString();

            model2 = CL.chercher2(test2);
          }
          if (found == 3) {
            QString test2 =
                ui->tableView->model()->index(found - 3, i).data().toString();

            model2 = CL.chercher2(test2);
          }
          if (found == 4) {
            QString test2 =
                ui->tableView->model()->index(found - 4, i).data().toString();

            model2 =CL.chercher2(test2);
          }
          if (found == 5) {
            QString test2 =
                ui->tableView->model()->index(found - 5, i).data().toString();

            model2 = CL.chercher2(test2);
          }
          if (found == 6) {
            QString test2 =
                ui->tableView->model()->index(found - 6, i).data().toString();

            model2 = CL.chercher2(test2);
          }
        }
      }
    }

    QSqlQueryModel *model1 = new QSqlQueryModel();

    model1 = CL.chercher(choix, crit);

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

void MainWindow::MainWindow::on_pushButton_5_clicked() {
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

  client CL;
  CL.setcin(cin);
  if (CL.verifier_cin_client(cin) == true) {
    if (CL.update_client(nom, prenom, cin, mail, hbd, num, operateur)) {
      QMessageBox::information(nullptr, QObject::tr("Updated"),
                               QObject::tr("CIN found.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);
      CL.afficher();
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

void MainWindow::MainWindow::on_delete_2_clicked() {
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

void MainWindow::on_pushButton_4_clicked()
{
  // imprimer
  QString description = ui->description->toPlainText();
  QString objet = ui->objet->text();
  QString title = "reclamation.pdf";
  CL.create_pdf(description, objet, title);
}

void MainWindow::on_pushButton_3_clicked()
{
  // afficher CF
  QSqlQueryModel *model = new QSqlQueryModel();
  model = carteF.displayCF(mydb);
  ui->tableView_2->setModel(model);
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Solde"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
}

//************************login

void MainWindow::on_pushButton_6_clicked()
{
    QString RecupRole;
    QString Username, Password , role;
   Username =ui->username->text();
    Password=ui->password->text();
 Admin A1(Username,Password,role);

 bool test=A1.Login();
RecupRole=A1.afficherRole();

 if(test)
 {

     //ui->label_3->setText("[+]Valid username or password ");

     if(RecupRole=="machine")
     {

        //  ui->label_3->setText("[+]Valid username and password ");
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->MachineFiche_2->setDisabled(false);
        ui->tabWidget_3->setDisabled(true);
        ui->tabWidget_6->setDisabled(true);
        ui->tabMain->setDisabled(true);

        }

     if(RecupRole=="fournisseur")
     {

        //  ui->label_3->setText("[+]Valid username and password ");
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->MachineFiche_2->setDisabled(true);
        ui->tabWidget_3->setDisabled(false);
        ui->tabWidget_6->setDisabled(true);
        ui->tabMain->setDisabled(true);

        }

     if(RecupRole=="employee")
     {

        //  ui->label_3->setText("[+]Valid username and password ");
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->MachineFiche_2->setDisabled(true);
        ui->tabWidget_3->setDisabled(true);
        ui->tabWidget_6->setDisabled(false);
        ui->tabMain->setDisabled(true);

        }


     if(RecupRole=="client")
     {

        //  ui->label_3->setText("[+]Valid username and password ");
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->MachineFiche_2->setDisabled(true);
        ui->tabWidget_3->setDisabled(true);
        ui->tabWidget_6->setDisabled(true);
        ui->tabMain->setDisabled(false);


        }


 }}
