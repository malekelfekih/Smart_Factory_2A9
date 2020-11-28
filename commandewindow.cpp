#include "commandewindow.h"
#include "ui_commandewindow.h"
#include <commandef.h>
#include <QMessageBox>
#include <QIntValidator>
#include<QDialog>

Commande::Commande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Commande)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_commande->setModel(C.afficher());

}




Commande::~Commande()
{
    delete ui;
}



void Commande::on_bouton_ajouter_clicked()
{
    int id =ui->id->text().toInt();
     float montant =ui->montant->text().toFloat();
    QString type=ui->type->text();
     QString date=ui->date->text();
    QString mode_paiment=ui->mode_paiment->text();

     commande C(id,montant,type,date,mode_paiment);

   bool test=C.ajouter();
   QMessageBox msgBox;

   if(test)
     {  msgBox.setText("Ajout avec succes.");
       ui->tab_commande->setModel(C.afficher());
   }
   else
       msgBox.setText("Echec d'ajout");
       msgBox.exec();
}
