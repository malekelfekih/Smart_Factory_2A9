#include "fichewindow.h"
#include "ui_fichewindow.h"
#include "fichesuivi.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include<QIntValidator>
#include<QPainter>
#include<QPrinter>
#include<QPdfWriter>
#include<QFileInfo>
#include<QFileDialog>



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


}


void fichewindow::on_pushButtonmodifier_clicked()
{


}



//supprimer:

void fichewindow::on_pushButton_2_clicked()
{

}




void fichewindow::on_pushButtonimprimer_clicked()
{

}
