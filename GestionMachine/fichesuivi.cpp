#include "fichesuivi.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
//Gestion de l'entite fiche de suivi

Fichesuivi::Fichesuivi()
{
    num_modele=0;
    age=0;
    etat="";
    date_derniere_m="";
}

Fichesuivi::Fichesuivi(int num_modele,int age,QString etat,QString date_derniere_m)
{
    this->num_modele=num_modele;
    this->age=age;
    this->etat=etat;
    this->date_derniere_m=date_derniere_m;
}


int Fichesuivi :: getnum_modele()
{return num_modele; }

int Fichesuivi:: getage()
{return age;}

QString Fichesuivi:: getetat()
{return etat;}

QString Fichesuivi:: getdate_derniere_m()
{return date_derniere_m;}

void Fichesuivi:: setnum_modele(int num_modele)
{this->num_modele=num_modele;}
void Fichesuivi:: setage(int age)
{this->age=age;}
void Fichesuivi:: setetat(QString etat)
{this->etat=etat;}
void Fichesuivi:: setdate_derniere_m(QString date_derniere_m)
{this->date_derniere_m=date_derniere_m;}

bool Fichesuivi::ajouter()
{

    QSqlQuery query;
    QString num_modele_string= QString::number(num_modele);
    QString age_string= QString::number(age);
   // QDate date_derniere_m =QDate::fromString(date_derniere_m,"dd/MM/yy");
    qDebug()<<"*****"<< date_derniere_m;


    query.prepare("INSERT INTO Fiche(num_modele,age,etat,date_m) "
                  "VALUES(:num_modele,:age,:etat,:date_m)");
         query.bindValue(":num_modele",num_modele_string);
         query.bindValue(":age",age_string);
         query.bindValue(":etat", etat);
         query.bindValue(":date_m", date_derniere_m);
        return query.exec();

}


QSqlQueryModel* Fichesuivi ::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM fiche");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_modele"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_derniere_m"));


  return  model;
}

bool Fichesuivi:: modifier()
{
    QSqlQuery query;
    QString num_modele_string= QString::number(num_modele);
    QString age_string= QString::number(age);
   // QDate date_derniere_m =QDate::fromString(date_derniere_m,"dd/MM/yy");
    qDebug()<<"*****"<< date_derniere_m;

    query.prepare("UPDATE Fiche SET age=:age,etat=:etat,date_m=:date_m where num_modele=:num_modele ");
    query.bindValue(":num_modele",num_modele_string);
    query.bindValue(":age",age_string);
    query.bindValue(":etat", etat);
    query.bindValue(":date_m", date_derniere_m);
       return    query.exec();
}


bool Fichesuivi:: supprimer(int num_modele,QString etat)
{
    QSqlQuery query;
         query.prepare(" Delete from fiche where num_modele=:num_modele");
         query.bindValue(0, num_modele);
         query.prepare(" Delete from fiche where etat=:etat");
         query.bindValue(0, etat);

        return query.exec();


}

