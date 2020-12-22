#include "menu.h"
#include "ui_menu.h"
#include "fichewindow.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButtonmachine_clicked()
{
     ma=new Machine(this);
     ma->show();
}

void menu::on_pushButtonfiche_clicked()
{
    fichewindow  sec;
    sec.setModal(true);
    sec.exec();
}
