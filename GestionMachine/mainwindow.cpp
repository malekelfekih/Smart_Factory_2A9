#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "machine.h"
#include "fichesuivi.h"
#include"statistiques.h"
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
     ui->tab_Fiche->setModel(F.afficher());
     ui->comboBoxchercher1->addItem("num_modele");
     ui->comboBoxchercher1->addItem("age");
     ui->comboBoxchercher1->addItem("num_serie_machine");
     ui->comboBoxchercher1->addItem("etat");
     ui->comboBoxetat->addItem("Bon etat");
     ui->comboBoxetat->addItem("Panne");
     ui->comboBoxetat->addItem("ne fonctionne plus");
     ui->comboBoxetat1->addItem("Bon etat");
     ui->comboBoxetat1->addItem("Panne");
     ui->comboBoxetat1->addItem("ne fonctionne plus");

     ui->comboBoxnummachine->setModel(F.afficher1());
     ui->comboBoxnummachine1->setModel(F.afficher1());

     ui->comboBoxnum->setModel(M.affichermachine());

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
     num_serie_machine=ui->comboBoxnummachine->currentText();
     QString description=ui->LEDes->text();
     QString date_derniere_m= date.toString("dd/MM/yyyy");
     qDebug()<<date_derniere_m;
    Fichesuivi F(num_modele,age,etat,date_derniere_m,num_serie_machine,description);
     QMessageBox msgBox;


if (F.verifvideint1(F.getnum_modele())==true&&F.verifvideint1(F.getage())==true&&F.verifvidestring1(F.getetat())==true&&F.verifvidestring1(F.getdescription())==true )
{bool test=F.ajouter();

      if(test)
       {  msgBox.setText("Ajout avec succes.");
         msgBox.exec();
         ui->tab_Fiche->setModel(F.afficher());
     }
      else
          msgBox.setText("Echec d'ajout");
          msgBox.exec();
          }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();

}

void MainWindow::on_pushButtonimprimer_clicked()
{  QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_Fiche->model()->rowCount();
    const int columnCount = ui->tab_Fiche->model()->columnCount();
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
        if (!ui->tab_Fiche->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_Fiche->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_Fiche->isColumnHidden(column)) {
                QString data =ui->tab_Fiche->model()->data(ui->tab_Fiche->model()->index(row, column)).toString().simplified();
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



void MainWindow::on_pushButtonmodifier_clicked()
{QString etat,num_serie_machine;
    int num_modele=ui->LEnum1->text().toInt();
     int age=ui->LEage1->text().toInt() ;
    etat=ui->comboBoxetat1->currentText();
     QDate date= ui->LEdate1->date();
     QString description=ui->LEDes1->text();
     QString date_derniere_m= date.toString("dd/MM/yyyy");
     qDebug()<<date_derniere_m;
     Fichesuivi F(num_modele,age,etat,date_derniere_m,num_serie_machine,description);
     QMessageBox msgBox ;
     bool test=F.verifiernum_modele1(num_modele);
     if (test&&F.verifvideint1(F.getage())==true&&F.verifvidestring1(F.getetat())==true&&F.verifvidestring1(F.getdate_derniere_m())==true&&F.verifvidestring1(F.getdescription())==true)
     { F.modifier();

       msgBox.setText(("modification avec succes"));
         ui->tab_Fiche->setModel(F.afficher());
     }
     else

         msgBox.setText("cette fiche n'existe pas");
        msgBox.exec();

}

void MainWindow::on_pushButtonsupprimer2_clicked()
{
    Fichesuivi F1;
    F1.setnum_serie_machine(ui->comboBoxnummachine1->currentText());

    QMessageBox msgBox;
    bool test=F1.supprimer(F1.getnum_serie_machine());

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
       ui->tab_Fiche->setModel(F.chercher1(choix,LErecherche1));


}


