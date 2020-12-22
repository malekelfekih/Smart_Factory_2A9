#ifndef COMMANDE_H
#define COMMANDE_H

#include<QString>
#include <QSqlQueryModel>

class Commande
{
public:
    Commande();
    Commande(int,QString,QString,QString,QString,int);
    int getid();
    QString getproduits();
    QString getdate_commande();
    QString getmode_paiment();
    QString getmontant();
    int  getcode_fournisseur();

    void setid(int);
    void setproduits(QString);
    void setdate(QString);
    void setmode_paiment(QString);
    void setmontant(QString);
    void setcode_fournisseur(int);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier();
    QSqlQueryModel* recherche(QString,int);
    QSqlQueryModel* afficherfournisseur();
    bool verifvidestring(QString);
    bool verifint(int);
    bool veriffloat(float);
    bool verifid(int);
    QSqlQueryModel* afficherid();

private:

    int id;
    QString produits,date_commande,mode_paiment,montant;

   int code_fournisseur;




};

#endif // COMMANDE_H
