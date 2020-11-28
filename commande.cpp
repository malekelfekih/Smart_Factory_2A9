#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Commande::Commande()
{
id=0;
montant=0;
code_fournisseur=0;
}
Commande::Commande(int id,QString p,QString d,QString m,float montant,int code)
{
 this->id=id;
    produits=p;
    date_commande=d;
    mode_paiment=m;
    this->montant=montant;
    code_fournisseur=code;
}
int Commande::getid()
{
    return id;
}
QString Commande:: getproduits()
{
    return produits;
}
QString Commande::getdate_commande()
{
    return date_commande;
}
QString Commande::getmode_paiment()
{
 return mode_paiment;
}
float Commande::getmontant()
{
   return montant;
}

void Commande:: setid(int id)
{
   this->id=id;
}
void Commande::setproduits(QString produits)
{
    this->produits=produits;
}
void Commande::setdate(QString date)
{
   date_commande=date;
}
void Commande::setmode_paiment(QString mode_p)
{
  mode_paiment=mode_p;
}
void Commande::setmontant(float m)
{
   montant=m;
}

bool Commande::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString code_fournisseur_string= QString::number(code_fournisseur);
    QString montant_string= QString::number(montant,'f',4);
    query.prepare("INSERT INTO commande (identifiant, produits, date_commande,mode_paiment,montant,code_fournisseur)"
                  "VALUES (:identifiant, :produits, :date_commande, :mode_paiment, :montant,:code_fournisseur)");
    query.bindValue(":identifiant", id_string);
    query.bindValue(":produits",produits);
    query.bindValue(":date_commande", date_commande);
    query.bindValue(":mode_paiment", mode_paiment);
    query.bindValue(":montant", montant_string);
     query.bindValue(":code_fournisseur", code_fournisseur_string);


    return query.exec();
}


bool Commande::supprimer (int id)
{

    QSqlQuery query;
         query.prepare(" Delete from commande where identifiant=:identifiant");
         query.bindValue(0,id);

        return query.exec();
}





QSqlQueryModel* Commande:: afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM commande ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("produits"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_commande"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("mode_paiment"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("montant"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("code_fournisseur"));

    return  model;
}

bool Commande:: modifier()
{


    QSqlQuery  query ;
    QString id_string= QString::number(id);
    QString montant_string= QString::number(montant,'f',4);
        query.prepare("UPDATE commande  set produits=:produits , date_commande=:date_commande , mode_paiment=:mode_paiment , montant=:montant,code_fournisseur=code_fournisseur, where identifiant=:identifiant ");


        query.bindValue(":identifiant",id_string);
        query.bindValue(":produits",produits);
        query.bindValue(":date_commande",date_commande);
        query.bindValue(":mode_paiment", mode_paiment);
        query.bindValue(":montant",montant_string);
        query.bindValue(":code_fournisseur",code_fournisseur);


        return query.exec();
}
QSqlQueryModel *  Commande::recherche(QString text,int test)
{

    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)
       { query.prepare("SELECT * FROM commande where identifiant like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT * FROM commande where produits like '"+text+"'");
               query.exec();
               model->setQuery(query);

        model->setQuery(query);
       }
       if(test==2)
           {
            query.prepare("SELECT * FROM commande where date_commande like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==3)
           {
            query.prepare("SELECT * FROM commande where mode_paiment like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==4)
           {
            query.prepare("SELECT * FROM commande where montant like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
        if(test==5)
           {
            query.prepare("SELECT * FROM commande  where code_fournisseur like '"+text+"'");
                query.exec();
                model->setQuery(query);
        }
         return model;

}

