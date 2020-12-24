#include "machinefiche.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "mainwindow.h"


Machinefiche::Machinefiche()
{
    num_serie_machine="" ;
    num_modele_fiche=0;
}

Machinefiche::Machinefiche(QString num_serie_machine, int num_modele_machine)
{
    this->num_serie_machine=num_serie_machine;
    this->num_modele_fiche=num_modele_machine;
}

QString Machinefiche :: getnum_serie()
{return num_serie_machine ; }

QSqlQueryModel *Machinefiche::afficherserie()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT num_serie FROM MACHINE");
    return model;
}


QSqlQueryModel *Machinefiche::affichermodele()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT num_modele FROM FICHE");
    return model;
}

QSqlQueryModel *Machinefiche::affichermachinefiche()
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM fiche F LEFT JOIN machine_fiche MF ON F.num_modele= MF.num_modele_fiche");
    // model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_serie_machine"));
    // model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_modele_fiche"));



     return  model;
}

bool Machinefiche::ajouter()
{

    QSqlQuery query;
    QString num_modele_fiche_string= QString::number(num_modele_fiche);


    query.prepare("INSERT INTO MACHINE_FICHE(num_serie_machine,num_modele_fiche) "
                  "VALUES(:num_serie_machine,:num_modele_fiche)");

         query.bindValue(":num_serie_machine",num_serie_machine);
         query.bindValue(":num_modele_fiche",num_modele_fiche_string);

        return query.exec();

}

bool Machinefiche::verifiernum_serie(QString num_serie_machine)
{
    QSqlQuery  query;
        bool test=false;
            query.prepare("Select * FROM MACHINE_FICHE where num_serie_machine");

             query.bindValue(":num_serie_machine",num_serie_machine);
        if(query.exec()&&query.next())
        {     test=true;
             return test;
        }
        return test;
}



QSqlQueryModel *Machinefiche::chercher1(int test,QString text)
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)
       { qDebug()<<"hello";
            query.prepare("SELECT* FROM fiche F LEFT JOIN machine_fiche MF ON F.num_modele= MF.num_modele_fiche where NUM_MODELE_FICHE  like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT* FROM machine M LEFT JOIN machine_fiche MF ON M.num_serie= MF.num_serie_machine where NUM_SERIE_MACHINE  like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }

       return model;

}
