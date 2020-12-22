#ifndef FICHESUIVI_H
#define FICHESUIVI_H
#include <QString>
#include <QSqlQueryModel>


class Fichesuivi
{
public:

    Fichesuivi();
     Fichesuivi(int,int,QString,QString,QString);
    int getnum_modele();
    int getage();
    QString getetat();
    QString getdate_derniere_m();
    QString getdescription();
    void setnum_modele(int);
    void setage(int);
    void setetat(QString);
    void setdate_derniere_m(QString);
    void setdescription(QString);
    bool ajouter();
    bool verifvideint1(int);
    bool verifvidestring1(QString);
    bool verifiernum_modele(int);
    bool verifiernum_modele1(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher1();
    QSqlQueryModel* chercher1(int,QString);
    bool supprimer(int);
    bool modifier();



private:

    int num_modele;
    int age;
    QString etat;
    QString date_derniere_m;
    QString description;





};




#endif // FICHESUIVI_H
