#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include<QString>
#include <QSqlQueryModel>
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QString,int,QString,QString,QString,QString);
    int getcode();
    int getnum();
    QString getnom();
    QString getadresse();
    QString getservice();
    QString getdb_contrat();
    QString getfin_contrat();
     QString getcourriel();






    void setcode(int);
    void setnum(int);
    void setnom(QString);
    void setadresse(QString);
    void setservice(QString);
    void setdb_contrat(QString);
    void setfin_contrat(QString);
    void setcourriel(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier();
    QSqlQueryModel* recherche(QString,int);
    bool verifvidestring(QString);
    bool verifint(int);
    bool verifcode(int);
     QSqlQueryModel* affichercode();


     QSqlQueryModel *triUP(int test);
     QSqlQueryModel *triDOWN(int test);
private:

    int code,num_tel;
    QString nom,adresse,service,debut_contrat,Fin_contrat,courriel;

};
#endif // FOURNISSEUR_H
