#include "fichewindow.h"
#include "ui_fichewindow.h"
#include "fichesuivi.h"
#include <QMessageBox>
#include <QDebug>
#include <QDate>

fichewindow::fichewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fichewindow)
{
    ui->setupUi(this);
    ui->tab_Fiche->setModel(F.afficher());

}


fichewindow::~fichewindow()
{
    delete ui;
}

void fichewindow::on_pushButtonajouter1_clicked()
{
       int num_modele=ui->LEnum->text().toInt();
       int age=ui->LEage->text().toInt() ;
        QString etat=ui->LEetat->text();
        QDate date= ui->LEdate->date();
        QString date_derniere_m= date.toString("dd/MM/yy");
        qDebug()<<date_derniere_m;
       Fichesuivi F(num_modele,age,etat,date_derniere_m);
       bool test=F.ajouter();
        QMessageBox msgBox;



        if(test)
          {  msgBox.setText("Ajout avec succes.");
            ui->tab_Fiche->setModel(F.afficher());
        }
        else
            msgBox.setText("Echec d'ajout");
            msgBox.exec();
}


void fichewindow::on_pushButtonmodifier_clicked()
{
       int num_modele=ui->LEnum1->text().toInt();
        int age=ui->LEage1->text().toInt() ;
        QString etat=ui->LEetat1->text();
        QDate date= ui->LEdate1->date();
        QString date_derniere_m= date.toString("dd/MM/yy");
        qDebug()<<date_derniere_m;

        Fichesuivi F(num_modele,age,etat,date_derniere_m);
        bool test=F.modifier();
        QMessageBox msgBox ;
        if(test)
        {
            msgBox.setText(("modification avec succes"));
            ui->tab_Fiche->setModel(F.afficher());

        }
        else
        {
            msgBox.setText("cette fiche n'existe pas");
           msgBox.exec();
        }

}



//supprimer:

void fichewindow::on_pushButton_2_clicked()
{
        Fichesuivi F1;
        F1.setnum_modele(ui->LEnum2->text().toInt());
        F1.setetat(ui->LEetat2->text());
        bool test=F1.supprimer(F1.getnum_modele(),F1.getetat());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->tab_Fiche->setModel(F.afficher());

        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}


