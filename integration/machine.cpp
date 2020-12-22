#include "machine.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "mainwindow.h"




//Gestion de l'entite machine

Machine::Machine()
{
    num_serie="";
    capacite_production=0;
    puissance_moteur=0;
    nb_heure=0;
}



Machine:: Machine(QString num_serie,int capacite_production,int puissance_moteur,int nb_heure)
{   this->num_serie=num_serie;
    this->capacite_production=capacite_production;
    this->puissance_moteur=puissance_moteur;
    this->nb_heure=nb_heure;


}
QString Machine:: getnum_serie()
{
    return num_serie;
}
int Machine:: getcapacite_production()
{
    return capacite_production;
}
int Machine:: getpuissance_moteur()
{
    return puissance_moteur;
}
int Machine::getnb_heure()
{
    return nb_heure;
}
void Machine:: setnum_serie(QString num_serie)
{
    this->num_serie=num_serie;
}
void Machine:: setcapacite_production(int capacite_production)
{
    this->capacite_production=capacite_production;
}
void Machine:: setpuissance_moteur(int puissance_moteur)
{
    this->puissance_moteur=puissance_moteur;
}
void Machine:: setnb_heure(int nb_heure)
{
    this->nb_heure=nb_heure;
}
bool Machine::ajouter()
{

    QSqlQuery query;
    QString capacite_production_string= QString::number(capacite_production);
    QString puissance_moteur_string= QString::number(puissance_moteur);
    QString nb_heure_string= QString::number(nb_heure);


    query.prepare("INSERT INTO Machine(num_serie,capacite_production,puissance_moteur,nb_heure) "
                  "VALUES(:num_serie,:capacite_production,:puissance_moteur,:nb_heure)");
         query.bindValue(":num_serie",num_serie);
         query.bindValue(":capacite_production",capacite_production_string);
         query.bindValue(":puissance_moteur", puissance_moteur);
         query.bindValue(":nb_heure", nb_heure_string);
        return query.exec();

}

bool Machine::verifvidestring(QString N)
{ bool test=true;
    if (N.length()==0)
    {test=false;
    return test;}
    return test;

}

bool Machine::verifiernum_serie(QString num_serie)
{  QSqlQuery  query;
    bool test=false;
        query.prepare("Select * FROM MACHINE where num_serie=:num_serie");
         query.bindValue(":num_serie",num_serie);
    if(query.exec()&&query.next())
    {     test=true;
         return test;
    }
    return test;
}

bool Machine::verifiernum_serie_machine(QString num_serie)
{  QSqlQuery  query;
    bool test=false;
        query.prepare("Select num_modele FROM FICHE where num_serie_machine=:num_serie_machine and etat='ne fonctionne plus'");
         query.bindValue(":num_serie_machine",num_serie);
    if(query.exec()&&query.next())
    {     test=true;
         return test;
    }
    return test;
}

bool Machine::verifvideint(int N)
{
    bool test=true;
        if (N==0)
        {test=false;
        return test;}
        return test;
}


QSqlQueryModel* Machine ::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM machine");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_serie"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite_production"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("puissance_moteur"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_heure"));


  return  model;
}

bool Machine:: supprimer(QString num_serie)
{
    QSqlQuery query;
         query.prepare(" Delete from machine where num_serie=:num_serie");

         query.bindValue(0, num_serie);

        return query.exec();


}


QSqlQueryModel *  Machine::chercher(int test,QString text)
{

    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)
       { query.prepare("SELECT * FROM MACHINE where NUM_SERIE like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT * FROM MACHINE where CAPACITE_PRODUCTION like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(test==2)
           {
            query.prepare("SELECT * FROM MACHINE where PUISSANCE_MOTEUR like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==3)
           {
            query.prepare("SELECT * FROM MACHINE where NB_HEURE like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }

         return model;


}

QSqlQueryModel* Machine ::affichermachine()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT num_serie FROM MACHINE");
    return model;
}

QSqlQueryModel *Machine::consulternb()
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT num_serie,nb_heure FROM machine");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_serie"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_heure"));
     return  model;
}



