#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "commande.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_code->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_num->setValidator(new QIntValidator(0, 9999999, this));
    ui->comboBoxchercher->addItem("15");
    ui->comboBoxchercher->addItem("200");
    ui->comboBoxchercher_2->addItem("15");
    ui->comboBoxchercher_2->addItem("200");

    ui->comboBox->addItem("identifiant");
    ui->comboBox->addItem("produits");
    ui->comboBox->addItem("date_commande");
    ui->comboBox->addItem("mode_paiment");
    ui->comboBox->addItem("montant");
    ui->comboBox->addItem("code_fournisseur");



    ui->id->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_fournisseur->setModel(F.afficher());
    ui->tab_commande->setModel(c.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bouton_ajouter_clicked()
{
    int code =ui->le_code->text().toInt();
    QString nom=ui->le_nom->text();
    QString adresse=ui->adresse->text();
    int num_tel =ui->le_num->text().toInt();
    QString service=ui->le_service->text();
    QString debut_contrat=ui->dbc->text();
    QString fin_contrat=ui->fnc->text();
    QString courriel=ui->le_courriel->text();



   Fournisseur F(code,nom,adresse,num_tel,service,debut_contrat,fin_contrat,courriel);
   bool test=F.ajouter();
   QMessageBox msgBox;

   if(test)
     {  msgBox.setText("Ajout avec succes.");
       ui->tab_fournisseur->setModel(F.afficher());
   }
   else
       msgBox.setText("Echec d'ajout");
       msgBox.exec();
}



void MainWindow::on_bouton_supprimer_clicked()
{
    Fournisseur F1;
    F1.setcode(ui->le_codesupp->text().toInt());
    bool test=F1.supprimer(F1.getcode());
    QMessageBox msgBox;

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
    float montant =ui->montant->text().toFloat();
    QString produits=ui->produits->text();
    QString date_commande=ui->date->text();
    QString mode_paiment=ui->mode->text();
   int code_fournisseur=ui->comboBoxchercher->currentText().toInt();

   Commande c(id,produits,date_commande,mode_paiment,montant, code_fournisseur);
   bool test=c.ajouter();
   QMessageBox msgBox;

   if(test)
     {  msgBox.setText("Ajout avec succes.");
       ui->tab_commande->setModel(c.afficher());
   }
   else
       msgBox.setText("Echec d'ajout");
       msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Commande c1;
    c1.setid(ui->id_supp->text().toInt());
    bool test=c1.supprimer(c1.getid());
    QMessageBox msgBox;

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
            QString service=ui->service_m->text();
            QString debut_contrat=ui->dbc_m->text();
            QString Fin_contrat=ui->fnc_m->text();
            QString courriel=ui->courriel_m->text();

        Fournisseur F(code,nom,adresse,num_tel,service,debut_contrat,Fin_contrat,courriel);
            bool test=F.modifier();

    QMessageBox msgBox ;
            if(test)
            {
                msgBox.setText(("modification avec succes"));
                ui->tab_fournisseur->setModel(F.afficher());

            }
            else
            {
                msgBox.setText("ce fournisseur n'existe pas");
               msgBox.exec();
            }



}

void MainWindow::on_pb_modifier_2_clicked()//modifier commande
{
    int id =ui->id_m->text().toInt();
    float montant =ui->montant_m->text().toFloat();
    QString mode_paiment=ui->mode_m->text();
    QString date_commande=ui->date_m->text();
    QString produits=ui->produits_m->text();
 int code_fournisseur=ui->comboBoxchercher_2->currentText().toInt();

 Commande c(id,produits,date_commande,mode_paiment,montant, code_fournisseur);
     bool test=c.modifier();

QMessageBox msgBox ;
     if(test)
     {
         msgBox.setText(("modification avec succes"));
         ui->tab_commande->setModel(c.afficher());

     }
     else
     {
         msgBox.setText("cette commande n'existe pas");
        msgBox.exec();
     }

}

void MainWindow::on_pb_chercher_clicked()
{

        int choix;
          choix=ui->comboBox->currentIndex();
          QString LErecherche=ui->LErecherche->text();

             ui->tab_commande->setModel(c.recherche(LErecherche,choix));


}
