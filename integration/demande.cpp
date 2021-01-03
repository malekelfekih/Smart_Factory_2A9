#include "demande.h"

#include <QMessageBox>
 /*demande::demande (QString identifiant , QString date_debut , QString date_fin  ,QString type_de_conge , int id )
 {

     this->identifiant=identifiant;
     this->date_debut=date_debut;
     this->date_fin=date_fin;
     this->type_de_conge=type_de_conge;
     this->id=id;



 }*/
 demande::demande (QString identifiant ,QString date_debut , QString date_fin  ,QString etats, int id,QString type_de_conge  )
 {

     this->identifiant=identifiant;
     this->date_debut=date_debut;
     this->date_fin=date_fin;
     this->etats=etats;
     this->type_de_conge=type_de_conge;
     this->id=id;



 }

     bool demande ::  ajouter_demande()
{

    QSqlQuery query;

    //QString identifiant_string = QString :: number(identifiant);


   //prepare() prend la requete en parametre pour la préparer à l'exécution
  // int id;
    QString id_string=QString::number(id);

    query.prepare("insert into DEMANDE( identifiant , date_debut,date_fin, id ,type_conge )""values(:identifiant, :date_debut ,:date_fin, :id ,:type_conge)");



    //creation des variables liées

    query.bindValue(":identifiant",identifiant);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":date_fin",date_fin);
   // query.bindValue(":etats",etats);
    query.bindValue(":id", id);
    query.bindValue(":type_conge",type_de_conge);





    return query.exec(); //exec () envoie la requete pour l'exécuter

}


// FONCTION AFFICHER

    QSqlQueryModel * demande :: afficher_demande()
    {
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM DEMANDE");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_debut"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_fin"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("etats"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_conge"));


    return model ;
    }
//fonction modifier

    /*bool demande ::modifier_demande()
    {
        QSqlQuery  query ;
        query.prepare("UPDATE demande SET  identifiant=:identifiant  ,date_debut=:date_debut ,  date_fin=:date_fin , id:=id WHERE identifiant:=identifiant");

        query.bindValue(0,identifiant);
        query.bindValue(1,date_debut);
        query.bindValue(2,date_fin);
        return query.exec(); //exec () envoie la requete pour l'exécuter

    }*/

    bool demande :: supprimer_demande(QString identifiant )
    {
        QSqlQuery query ;
       // QString identifiant_identifiant = QString :: number(identifiant);
        query.prepare("Delete from demande where identifiant =:identifiant");
        query.bindValue(0,identifiant);
        return query.exec();

    }

    bool demande :: accepter (QString identifiant )
    {
        QSqlQuery query ;
       // QString identifiant_string = QString :: number(identifiant);
        //QString e = " ";

          query.prepare("UPDATE demande SET etats = 'accepter' WHERE identifiant = :identifiant");

        query.bindValue(":identifiant",identifiant);

        query.bindValue(":etats",etats);

        return query.exec();

    }

   /* bool demande :: refuser (QString identifiant )
    {
        QSqlQuery query ;
       // QString identifiant_string = QString :: number(identifiant);
        QString e = " ";
        query.prepare("Update DEMANDE set etats ='refuser' where identifiant =:identifiant");
        query.bindValue(":=identifiant",identifiant);
        //query.bindValue(1,identifiant);
        return query.exec();

    }*/



















    QSqlQueryModel* demande::chercher_demande(int a , QString b )
    {


            QSqlQuery query ;

            QSqlQueryModel *model = new QSqlQueryModel();

            if(a==0)
            {
                query.prepare("SELECT * from demande where identifiant like '"+b+"'  ");
                query.exec();
                model->setQuery(query);
            }

                if(a==1)
                {
                    query.prepare("SELECT * from demande where date_debut like '"+b+"'  ");
                    query.exec();
                    model->setQuery(query);
                }
               if(a==2)
               {
                   query.prepare("SELECT * from demande where date_fin like '"+b+"'  ");
                   query.exec();

                   model->setQuery(query);
             }
               if(a==3)
               {
                   query.prepare("SELECT * from demande where type_conge like '"+b+"'  ");
                   query.exec();
                   model->setQuery(query);
             }







            return model;


    }

    QSqlQueryModel *demande::trier_down_demande(int test) {
      QSqlQuery query;
      QSqlQueryModel *model = new QSqlQueryModel();

      if (test == 0) {
        query.prepare(" SELECT * FROM demande ORDER BY identifiant desc; ");
        query.exec();
        model->setQuery(query);
      }

      if (test == 1) {
        query.prepare(" SELECT * FROM demande ORDER BY date_debut desc; ");
        query.exec();
        model->setQuery(query);
      }

      if (test == 2) {
        query.prepare(" SELECT * FROM demande ORDER BY date_fin desc; ");
        query.exec();
        model->setQuery(query);
      }


      return model;
    }


    QSqlQueryModel *demande::trier_up_demande(int test)  {
      QSqlQuery query;
      QSqlQueryModel *model = new QSqlQueryModel();

      if (test == 0) {
        query.prepare(" SELECT * FROM demande ORDER BY identifiant asc; ");
        query.exec();
        model->setQuery(query);
      }

      if (test == 1) {
        query.prepare(" SELECT * FROM demande ORDER BY date_debut asc; ");
        query.exec();
        model->setQuery(query);
      }

      if (test == 2) {
        query.prepare(" SELECT * FROM demande ORDER BY date_fin asc; ");
        query.exec();
        model->setQuery(query);
      }







      return model;
    }
    bool demande::modifier_demande(QString identifiant,QString date_debut ,QString date_fin , QString type_de_conge )
    {


    QSqlQuery query;

    if (identifiant != "") {
        query.prepare("UPDATE demande SET identifiant = :identifiant WHERE identifiant = :identifiant ");
        query.bindValue(":identifiant", identifiant);
        //query.bindValue(":identifiant", identifiant);
        if(!query.exec())
           {
            return false;
        }
    }
    if (date_debut != "") {
        query.prepare("UPDATE demande SET date_debut = :date_debut WHERE identifiant = :identifiant ");
        query.bindValue(":identifiant", identifiant);
        query.bindValue(":date_debut", date_debut);
        if(!query.exec())
           {
            return false;
        }
    }
    if (date_fin != "") {
        query.prepare("UPDATE demande SET date_fin = :date_fin WHERE identifiant = :identifiant ");
        query.bindValue(":identifiant", identifiant);
        query.bindValue(":date_fin", date_fin);
        if(!query.exec())
           {
            return false;
        }
    }
    if (type_de_conge != "") {
        query.prepare("UPDATE demande SET type_conge = :type_conge WHERE identifiant = :identifiant ");
        query.bindValue(":identifiant", identifiant);
        query.bindValue(":type_conge", type_de_conge);
        if(!query.exec())
           {
            return false;
        }
    }
    return true;
 }



     QSqlQueryModel *demande::afficher2()
     {
         QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT id FROM EMPLOYEE");
             return model;
     }

     QSqlQueryModel *demande::afficher3()
     {
         QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT identifiant FROM DEMANDE");
             return model;
     }
     QSqlQueryModel *demande::afficher4()
     {
         QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT identifiant FROM DEMANDE");
             return model;
     }

