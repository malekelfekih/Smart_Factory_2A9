#ifndef CONGES_H
#define CONGES_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>
#include "demande.h"


class conges
{
private:
/*int id , num_demande;
QString nom;
QString prenom ;
QDate date_debut;
QDate date_fin ;*/
public:
    conges();
   //  QString conges :: etats_string();

 //QSqlQueryModel * demande :: afficher_demande();


      /*  conges(int,int  ,QString  ,QString , QDate , QDate );

        //getters
        int getNum_demande(){return num_demande;}
        int getID(){return id;}
        QString getNom(){return nom;}
        QString getPrenom(){return prenom;}




       QDate getDate_naissance(){return date_debut;}
       QDate getDate_embauche(){return date_fin;}



        //setters
        void setID(int id){this->id=id;}
        void setNum_demande(int num_demande){this->num_demande=num_demande;}
        void setNom(QString nom){this->nom=nom;}
        void setPrenom(QString prenom){this->prenom=prenom;}




        void setDate_naissance(QDate date_debut){this->date_debut=date_debut;}
        void setDate_embauche(QDate date_fin){this->date_fin=date_fin;}

    //fonctionnalites de base relatives a l'entite admin


                    bool Ajouter_Conge();
                    bool Supprimer_Conge(QString);
                    bool verifier_demande();
                   QSqlQueryModel *  Consulter_Conge();
                   QSqlQueryModel * Rechercher_Conge(QString x);*/




    };






#endif // CONGES_H
