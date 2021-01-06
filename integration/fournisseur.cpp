#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QDate>
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


bool Fournisseur::verifvidestring(QString S)
{
    bool test=true;
        if(S.length()==0)
         {  test=false;
            return test;}
        return test;
}
bool Fournisseur ::verifint(int S)
{
    bool test=true;
        if(S==0)
         {  test=false;
            return test;}
        return test;

}

bool Fournisseur::verifcode(int)
{
    QSqlQuery  query;
          bool test=false;
            QString code_string=QString::number(code);
              query.prepare("Select * FROM fournisseur where code=:code ");

               query.bindValue(":code",code_string);
          if(query.exec()&&query.next())
          {     test=true;
               return test;
          }
          return test;
}


 bool Fournisseur:: ajouter()
                          {


                              QSqlQuery query;
                              QString code_string= QString::number(code);
                              QString num_string= QString::number(num_tel);
                              QDate debutcontrat_date =QDate::fromString(debut_contrat,"dd/MM/yyyy");
                              QDate fincontrat_date =QDate::fromString(Fin_contrat,"dd/MM/yyyy");

                              query.prepare("INSERT INTO fournisseur (code, nom, adresse,num_tel,service,debut_contrat,Fin_contrat,courriel)"
                                            "VALUES (:code, :nom, :adresse, :num_tel, :service, :debut_contrat, :Fin_contrat,:courriel)");
                              query.bindValue(":code", code_string);

                              query.bindValue(":nom",nom);
                              query.bindValue(":adresse", adresse);
                               query.bindValue(":num_tel", num_string);
                               query.bindValue(":service", service);
                               query.bindValue(":debut_contrat", debutcontrat_date);
                               query.bindValue(":Fin_contrat", fincontrat_date);
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
        QDate debutcontrat_date =QDate::fromString(debut_contrat,"dd/MM/yyyy");
        QDate fincontrat_date =QDate::fromString(Fin_contrat,"dd/MM/yyyy");
        query.bindValue(":code",code_string);
        query.bindValue(":nom",nom);

        query.bindValue(":adresse",adresse);

         query.bindValue(":num_tel",num_tel_string);

         query.bindValue(":service",service);
         query.bindValue(":debut_contrat", debutcontrat_date);
         query.bindValue(":Fin_contrat",fincontrat_date);
         query.bindValue(":courriel",courriel);

        return query.exec();
}

QSqlQueryModel *  Fournisseur::recherche(QString text,int test)
{

    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)

         { query.prepare("SELECT * FROM fournisseur where code like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT * FROM fournisseur where nom like '"+text+"'");
               query.exec();
               model->setQuery(query);


       }
       if(test==2)
           {
            query.prepare("SELECT * FROM fournisseur where adresse like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==3)
           {
            query.prepare("SELECT * FROM fournisseur where num_tel like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==4)
           {
            query.prepare("SELECT * FROM fournisseur where service like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==5)
           {
            query.prepare("SELECT * FROM fournisseur  where debut_contrat like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==6)
           {
            query.prepare("SELECT * FROM fournisseur where Fin_contrat like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==7)
           {
            query.prepare("SELECT * FROM fournisseur where courriel like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
         return model;

}

QSqlQueryModel* Fournisseur ::affichercode()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT code FROM fournisseur");
    return model;
}




QSqlQueryModel *Fournisseur::triUP(int test) {
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (test == 0) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY code asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 1) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY nom asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 2) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY adresse asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 3) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Numero_tel asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 4) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Service asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 5) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Debut_contrat asc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 6) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Fin_contrat asc; ");
    query.exec();
    model->setQuery(query);
  }
  if (test == 7) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY courriel asc; ");
    query.exec();
    model->setQuery(query);
  }
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero_tel"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Service"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Debut_contrat"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fin_contrat"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("courriel"));

  return model;
}

QSqlQueryModel * Fournisseur ::triDOWN(int test) {
  QSqlQuery query;
  QSqlQueryModel *model = new QSqlQueryModel();

  if (test == 0) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY code desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 1) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY  nom desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 2) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Adresse desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 3) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY numero_tel desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 4) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Service desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 5) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Debut_contrat desc; ");
    query.exec();
    model->setQuery(query);
  }

  if (test == 6) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY Fin_contrat desc; ");
    query.exec();
    model->setQuery(query);
  }
  if (test == 7) {
    query.prepare(" SELECT * FROM fournisseur ORDER BY courriel desc; ");
    query.exec();
    model->setQuery(query);
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero_tel"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Service"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Debut_contrat"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fin_contrat"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("courriel"));

  return model;
}


