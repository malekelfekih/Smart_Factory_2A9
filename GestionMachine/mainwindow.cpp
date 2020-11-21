#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "machine.h"
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_Machine->setModel(M.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonajouter_clicked()
{   QString num_serie=ui->LEnum->text();
    int capacite_production=ui->LEcapacite->text().toInt() ;
    int puissance_moteur=ui->LEpuissance->text().toInt();
    QString nb_heure=ui->LEnb->text();


   Machine M(num_serie,capacite_production,puissance_moteur,nb_heure);
   bool test=M.ajouter();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tab_Machine->setModel(M.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();

}

void MainWindow::on_pushButtonsupprimer_clicked()
{
    Machine M1; M1.setnum_serie(ui->LEnumsup->text());
        bool test=M1.supprimer(M1.getnum_serie());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->tab_Machine->setModel(M.afficher());

        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}
