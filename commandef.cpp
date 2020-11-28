#include "commandef.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Commande_F::Commande_F()
{
id=0;
montant=0;
}

Commande_F::Commande_F(int id,float m,QString t,QString d,QString mode_paiment)
{
    this->id=id;
    montant=m;
    type=t;
    date=d;
    this->mode_paiment=mode_paiment;
}
int Commande_F::getid()
{
    return id;
}
float Commande_F:: getmontant()
{
    return montant;
}
QString Commande_F::gettype()
{
    return type;
}
QString Commande_F::getdate()
{
return date;
}
 QString Commande_F:: getmode_paiment()
 {
     return mode_paiment;
 }

void Commande_F::setid(int id)
{
 this->id=id;
}
void Commande_F::setmontant(float montant)
{
    this->montant=montant;
}
void Commande_F::settype(QString type)
{
 this->type=type;
}
void Commande_F::setdate(QString date)
{
  this->date=date;
}
void Commande_F::setmode_paiment(QString mode_paiment)
{
    this->mode_paiment=mode_paiment;
}

bool Commande_F:: ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);
    QString montant_string= QString::number(montant);
    query.prepare("INSERT INTO commande (id,montant,type,date,mode_paiment)"
                  "VALUES (:id, :montant, :type,:date,:mode_paiment)");
    query.bindValue(":id", id_string);
    query.bindValue(":montant",montant_string);
    query.bindValue(":type",type);
    query.bindValue(":date",date);
    query.bindValue(":mode_paiment",mode_paiment);

    return query.exec();
}
QSqlQueryModel* Commande_F::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM commande ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("mode_paiment"));


    return  model;
}
bool Commande_F::supprimer (int)
{
    QSqlQuery query;
         query.prepare(" Delete from commande where id=:id");
         query.bindValue(0,id);

        return query.exec();
}
