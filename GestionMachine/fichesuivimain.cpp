#include "fichesuivimain.h"
#include "ui_fichesuivimain.h"
#include "fiche_suivi.h"
#include <QMessageBox>

Fichesuivimain::Fichesuivimain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fichesuivimain)
{
    ui->setupUi(this);
    ui->tab_Fiche->setModel(F.afficher());
}

Fichesuivimain::~Fichesuivimain()
{
    delete ui;
}

void Fichesuivimain::on_pushButtonajouter1_clicked()
{
    int num_modele=ui->LEnum->text().toInt();
    int age=ui->LEage->text().toInt() ;
    QString etat=ui->LEetat->text();
    QString date=ui->LEdate->text();
   Fiche_suivi F(num_modele,age,etat,date);
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
