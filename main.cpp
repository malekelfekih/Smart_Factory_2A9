#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include "connection.h"
#include "authentifier.h"
#include "demande.h"
#include "ui_demande.h"
#include "arduino.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    /*arduino ard ;
    ard.setWindowTitle("Temperature Sensor Reading");
    ard.setFixedSize(400,112);
    ard.show();*/
    bool test=c.createconnect();//etablir la connection
     MainWindow w;
// Acceuil w;

    if(test)
    {w.show();
       // d.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}






