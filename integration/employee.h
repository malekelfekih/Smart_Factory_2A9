#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlDatabase>
#include <QDate>
#include <QIntValidator>
#include <QApplication>
#include <QDebug>
#include<QObject>
#include <QComboBox>

class EMPLOYEE
{

private:
    QString nom , prenom , email, adresse,type_de_contract , operateur, date_naissance , date_embauche ;
    int id , cin , num_telephone , salaire ;

  //  QString date_naissance , date_embauche;
public:
    //constructeurs

    EMPLOYEE(){}

    EMPLOYEE(QString  ,QString  ,QString ,QString ,QString ,QString,QString ,QString,int,int ,int ,int);

    //getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}

    QString getEmail(){return email;}

    QString getAdresse(){return adresse;}
     QString getType_de_conctrat(){return type_de_contract;}
     QString getOperateur(){return operateur;}
     QString getDate_naissance(){return date_naissance;}
     QString getDate_embauche(){return date_embauche;}
    int getID(){return id;}
    int getCIN(){return cin;}
    int getNum_telephone(){return num_telephone;}
    int getSalaire(){return salaire ;}



    //setters
     void setNom(QString nom){this->nom=nom;}
     void setPrenom(QString prenom){this->prenom=prenom;}

     void setEmail(QString email){this->email=email;}

     void setAdresse(QString adresse){this->adresse=adresse;}
      void setType_de_contract(QString type_de_contract){this->type_de_contract=type_de_contract;}
      void setOperateur(QString operateur){this->operateur=operateur;}
      void setDate_naissance(QString date_naissance){this->date_naissance=date_naissance;}
      void setDate_embauche(QString date_embauche){this->date_embauche=date_embauche;}
     void setID(int id){this->id=id;}
     void setCIN(int cin){this->cin=cin;}
     void setNum_telephone(int num_telephone){this->num_telephone=num_telephone;}
     void setSalaire(int salaire){this->salaire=salaire;}



     //fonctionnalites de base relatives a l'entite admin
     bool ajouter();
     QSqlQueryModel * afficher();
     bool  supprimer(int);
     bool  modifier(QString , QString  ,QString  , QString  ,QString , QString  ,QString , int   , int  , int   , int );
     QSqlQueryModel * recherche(int  , QString );
     QSqlQueryModel *  trierup(int);
     QSqlQueryModel *  trier_down(int);
     QSqlQueryModel * statistique(int);
     int calculer(QString );
      QSqlQueryModel * afficher1();




};

#endif // EMPLOYEE_H
