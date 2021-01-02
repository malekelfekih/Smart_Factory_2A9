#include "authentifier.h"
#include "ui_authentifier.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "admin.h"

authentifier::authentifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentifier)
{
    ui->setupUi(this);
}

authentifier::~authentifier()
{
    delete ui;
}


