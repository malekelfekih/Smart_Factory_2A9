#include "mainwindow.h"
#include "fichewindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.ouvrirConnexion();
    MainWindow w;

    /*int res;
    login w2;
    w2.setWindowTitle("Log In");
    res = w2.exec();*/

         if(test)
         {

             w.show();
             /*QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Cancel);*/

             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}


