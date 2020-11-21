#ifndef FICHESUIVI_H
#define FICHESUIVI_H
#include <QString>
#include <QSqlQueryModel>

class Fichesuivi
{
public:

    Fichesuivi();
     Fichesuivi(int,int,QString,QString);
    int getnum_modele();
    int getage();
    QString getetat();
    QString getdate_derniere_m();
    void setnum_modele(int);
    void setage(int);
    void setetat(QString);
    void setdate_derniere_m(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int,QString);
    bool modifier();


private:

    int num_modele;
    int age;
    QString etat;
    QString date_derniere_m;




};




#endif // FICHESUIVI_H
