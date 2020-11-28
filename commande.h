#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQueryModel>

class Commande
{
public:
    Commande();
    Commande(int,QString,QString,QString,float,int);
    int getid();
    QString getproduits();
    QString getdate_commande();
    QString getmode_paiment();
    float getmontant();
    int  getcode_fournisseur();

    void setid(int);
    void setproduits(QString);
    void setdate(QString);
    void setmode_paiment(QString);
    void setmontant(float);
    void setcode_fournisseur(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier();
    QSqlQueryModel* recherche(QString,int);
private:

    int id;
    QString produits,date_commande,mode_paiment;
    float montant;
   int code_fournisseur;




};

#endif // COMMANDE_H
