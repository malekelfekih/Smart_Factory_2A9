#ifndef DEMANDE_H
#define DEMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlDatabase>
#include <QDate>
#include <QIntValidator>
#include <QApplication>
#include <QDebug>
#include<QObject>


    class demande

    {

    private:
         QString identifiant;

         QString  date_debut , date_fin;

         QString etats;
         QString type_de_conge;
         int id;
       //  int id;
    public:
        //constructeurs

        demande(){}

        demande(QString  , QString , QString ,QString ,int);
      demande (QString  ,QString  , QString   ,QString , int ,QString);


        //getters
        QString getIdentifiant(){return identifiant;}




       QString getDate_debut(){return date_debut;}
       QString getDate_fin(){return date_fin;}
       QString getEtats(){return etats;}
       QString getType_conge(){return type_de_conge; }

      // int getID(){return id;}



        //setters

         void setIdentifiant(QString identifiant){this->identifiant=identifiant;}

         void setDate_debut(QString date_debut){this->date_debut=date_debut;}
         void setDate_fin(QString date_fin){this->date_fin=date_fin;}
         void setEtats(QString etats ){this->etats=etats;}
         void setTypeconge(QString type_de_conge ){this->type_de_conge=type_de_conge;}
        // void setID(int id){this->id=id;}

       //fonctionnalites de base relatives a l'entite admin

        bool  ajouter_demande();
         //QSqlQueryModel * afficher_demande();
         QSqlQueryModel *  afficher_demande();
         bool  supprimer_demande(QString);
        // bool  modifier_demande();
         bool modifier_demande( QString ,QString  ,QString  , QString );
         QSqlQueryModel * chercher_demande(int, QString );

        // QString etats_string(QString);
         bool   accepter (QString  );
         //bool  refuser (QString  );
         QSqlQueryModel *  trier_up_demande(int);
         QSqlQueryModel *  trier_down_demande(int);
         QSqlQueryModel *  afficher2();
         QSqlQueryModel *  afficher3();
         QSqlQueryModel *  afficher4();
        // bool modifier(int, QString, QString, int , int);








};

#endif // DEMANDE_H
