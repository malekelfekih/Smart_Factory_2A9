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






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

