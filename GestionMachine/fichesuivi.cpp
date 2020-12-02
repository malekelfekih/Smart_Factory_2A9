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
    num_serie_machine="";
    description="";
}

Fichesuivi::Fichesuivi(int num_modele,int age,QString etat,QString date_derniere_m,QString num_serie_machine,QString description)
{
    this->num_modele=num_modele;
    this->age=age;
    this->etat=etat;
    this->date_derniere_m=date_derniere_m;
    this->num_serie_machine=num_serie_machine;
    this->description=description;
}


int Fichesuivi :: getnum_modele()
{return num_modele; }

int Fichesuivi:: getage()
{return age;}

QString Fichesuivi:: getetat()
{return etat;}

QString Fichesuivi:: getdate_derniere_m()
{return date_derniere_m;}

QString Fichesuivi::getnum_serie_machine()
{return num_serie_machine;}

QString Fichesuivi::getdescription()
{return description;}

void Fichesuivi:: setnum_modele(int num_modele)
{this->num_modele=num_modele;}

void Fichesuivi:: setage(int age)
{this->age=age;}

void Fichesuivi:: setetat(QString etat)
{this->etat=etat;}

void Fichesuivi:: setdate_derniere_m(QString date_derniere_m)
{this->date_derniere_m=date_derniere_m;}

void Fichesuivi:: setnum_serie_machine(QString num_serie_machine)
{this->num_serie_machine=num_serie_machine;}

void Fichesuivi:: setdescription(QString description)
{this->description=description; }

bool Fichesuivi::ajouter()
{

    QSqlQuery query;
    QString num_modele_string= QString::number(num_modele);
    QString age_string= QString::number(age);
   // QDate date_derniere_m =QDate::fromString(date_derniere_m,"dd/MM/yyyy");
    qDebug()<<"*****"<< date_derniere_m;



    query.prepare("INSERT INTO Fiche(num_modele,age,etat,date_m,num_serie_machine,description) "
                  "VALUES(:num_modele,:age,:etat,:date_m,:num_serie_machine,:description)");
         query.bindValue(":num_modele",num_modele_string);
         query.bindValue(":age",age_string);
         query.bindValue(":etat", etat);
         query.bindValue(":date_m", date_derniere_m);
         query.bindValue(":num_serie_machine",num_serie_machine);
         query.bindValue(":description", description);
        return query.exec();

}

bool Fichesuivi::verifvideint1(int N)
{
    bool test=true;
        if (N==0)
        {test=false;
        return test;}
        return test;
}

bool Fichesuivi::verifvidestring1(QString N)
{
    bool test=true;
        if (N.length()==0)
        {test=false;
        return test;}
        return test;
}

bool Fichesuivi::verifiernum_modele(int num_modele)
{
    QSqlQuery  query;
        bool test=false;
          QString num_modele_string=QString::number(num_modele);
            query.prepare("Select * FROM FICHE where num_modele=:num_modele and etat='ne fonctionne plus'");

             query.bindValue(":num_modele",num_modele_string);
        if(query.exec()&&query.next())
        {     test=true;
             return test;
        }
        return test;
}
bool Fichesuivi::verifiernum_modele1(int num_modele)
{
    QSqlQuery  query;
        bool test=false;
          QString num_modele_string=QString::number(num_modele);
            query.prepare("Select * FROM FICHE where num_modele=:num_modele ");

             query.bindValue(":num_modele",num_modele_string);
        if(query.exec()&&query.next())
        {     test=true;
             return test;
        }
        return test;
}

QSqlQueryModel* Fichesuivi ::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM fiche");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_modele"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_derniere_m"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_serie_machine"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));


  return  model;
}

QSqlQueryModel* Fichesuivi ::afficher1()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT num_serie FROM MACHINE");
    return model;
}

QSqlQueryModel *Fichesuivi::chercher1(int test,QString text)
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)
       { query.prepare("SELECT * FROM FICHE where NUM_MODELE like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT * FROM FICHE where AGE like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(test==2)
           {
            query.prepare("SELECT * FROM FICHE where ETAT like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==3)
           {
            query.prepare("SELECT * FROM FICHE where NUM_SERIE_MACHINE like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }

         return model;

}

bool Fichesuivi:: modifier()
{
    QSqlQuery query;
    QString num_modele_string= QString::number(num_modele);
    QString age_string= QString::number(age);
   // QDate date_derniere_m =QDate::fromString(date_derniere_m,"dd/MM/yyyy");
    qDebug()<<"*****"<< date_derniere_m;

    query.prepare("UPDATE Fiche SET age=:age,etat=:etat,date_m=:date_m,description=:description where num_modele=:num_modele ");
    query.bindValue(":num_modele",num_modele_string);
    query.bindValue(":age",age_string);
    query.bindValue(":etat", etat);
    query.bindValue(":date_m", date_derniere_m);
    query.bindValue(":description", description);
    return    query.exec();
}




bool Fichesuivi:: supprimer(QString num_serie_machine)
{
    QSqlQuery query;
          query.prepare(" Delete from fiche where num_serie_machine=:num_serie_machine ");

          query.bindValue(0, num_serie_machine);

        return query.exec();


}





