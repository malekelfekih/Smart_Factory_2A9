#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Fournisseur::Fournisseur()
{
code=0;
num_tel=0;
}

Fournisseur::Fournisseur(int c,QString n,QString a,int n1,QString s,QString dbc,QString fnc,QString courriel)
{
    code=c;
    nom=n;
    adresse=a;
    num_tel=n1;
    service=s;
    debut_contrat=dbc;
    Fin_contrat=fnc;
    this->courriel=courriel;

}
int Fournisseur:: getcode()
{
    return code;
}
int  Fournisseur::getnum()
{
  return num_tel;
}

QString Fournisseur:: getnom()
{
    return nom;
}
QString Fournisseur::getadresse()
{
    return adresse;
}
QString Fournisseur:: getservice()
{
   return service;
}
QString Fournisseur::getdb_contrat()
{
    return debut_contrat;
}
QString Fournisseur::getfin_contrat()
{
    return Fin_contrat;
}
QString Fournisseur::getcourriel()
{
    return courriel;
}
void Fournisseur::setcode(int code)
{
                              this->code=code;
                          }
void Fournisseur::setnum(int num)
{
   num_tel=num;
}
void Fournisseur::setnom(QString nom)
                          {
                           this->nom=nom;
                          }
void Fournisseur::setadresse(QString adresse)
                          {

                              this->adresse=adresse;
                          }
void  Fournisseur::setservice(QString s)
{
    service=s;
}
void  Fournisseur::setdb_contrat(QString db)
{
    debut_contrat=db;
}
void  Fournisseur::setfin_contrat(QString fin)
{
    Fin_contrat=fin;
}
void Fournisseur::setcourriel(QString c)
{
 courriel =c;
}
 bool Fournisseur:: ajouter()
                          {


                              QSqlQuery query;
                              QString code_string= QString::number(code);
                              QString num_string= QString::number(num_tel);

                              query.prepare("INSERT INTO fournisseur (code, nom, adresse,num_tel,service,debut_contrat,Fin_contrat,courriel)"
                                            "VALUES (:code, :nom, :adresse, :num_tel, :service, :debut_contrat, :Fin_contrat,:courriel)");
                              query.bindValue(":code", code_string);

                              query.bindValue(":nom",nom);
                              query.bindValue(":adresse", adresse);
                               query.bindValue(":num_tel", num_string);
                               query.bindValue(":service", service);
                               query.bindValue(":debut_contrat", debut_contrat);
                               query.bindValue(":Fin_contrat", Fin_contrat);
                                query.bindValue(":courriel", courriel);

                              return query.exec();


                          }
 bool Fournisseur:: supprimer (int code)


 {

     QSqlQuery query;
          query.prepare(" Delete from fournisseur where code=:code");
          query.bindValue(0, code);

         return query.exec();


 }








 QSqlQueryModel* Fournisseur::afficher()
 {
   QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM fournisseur ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero_tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Service"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Debut_contrat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fin_contrat"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("courriel"));


   return  model;
 }



bool Fournisseur:: modifier()
{


    QSqlQuery  query ;
        query.prepare("UPDATE fournisseur  set nom=:nom , adresse=:adresse , num_tel=:num_tel , service=:service, debut_contrat=:debut_contrat, Fin_contrat=:Fin_contrat,courriel=:courriel where code=:code ");
        QString num_tel_string= QString::number(num_tel);
        QString code_string= QString::number(code);
        query.bindValue(":code",code_string);
        query.bindValue(":nom",nom);

        query.bindValue(":adresse",adresse);

         query.bindValue(":num_tel",num_tel_string);

         query.bindValue(":service",service);
         query.bindValue(":debut_contrat",debut_contrat);
         query.bindValue(":Fin_contrat",Fin_contrat);
         query.bindValue(":courriel",courriel);

        return query.exec();
}








