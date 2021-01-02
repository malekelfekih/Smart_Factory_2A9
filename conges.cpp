#include "conges.h"
#include "demande.h"



// FONCTION AFFICHER

   /* QSqlQueryModel * demande :: afficher_demande()
    {
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM DEMANDE");
     }*/






/*conges::conges (int  id ,int num_demande,QString nom, QString prenom ,   QDate date_debut , QDate date_fin )
{

    this->id=id;
    this->num_demande=num_demande;
    this->nom=nom;
    this->prenom=prenom;
    this->date_debut=date_debut;
    this->date_fin=date_fin;

}

bool conges ::  Ajouter_Conge()
{

    QSqlQuery query;

    QString id_string = QString :: number(id);


   //prepare() prend la requete en parametre pour la préparer à l'exécution

    query.prepare("insert into EMPLOYEE(id , num_demande ,nom , prenom , date_debut , date_fin )""values(:id,:num_demande ,:nom,:prenom, :date_debut,:date_fin )");

    //creation des variables liées

    query.bindValue(0,id);
    query.bindValue(1,num_demande);

    query.bindValue(2,nom);
    query.bindValue(3,prenom);
    query.bindValue(4,date_debut);
    query.bindValue(5,date_fin);



    return query.exec(); //exec () envoie la requete pour l'exécuter

}

bool conges::Supprimer_Conge(QString x)
{
    QSqlQuery qrt;
    bool result;

    QString str="Delete from Conge where Numero_demande='"+x+"'";
    result=qrt.exec(str);
    qDebug()<<str<<result;
    return result;
}
QSqlQueryModel * conges::Consulter_Conge()
{
    QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT id, num_demande , nom , prenom , date_debut , date_fin , FROM conges");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero_demande"));
     model->setHeaderData(1, Qt::Horizontal,QObject:: tr("id"));
     model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Nom"));
     model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Prenom"));


     return model;
}*/
















