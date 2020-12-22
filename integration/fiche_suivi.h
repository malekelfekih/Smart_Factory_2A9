#ifndef FICHE_SUIVI_H
#define FICHE_SUIVI_H
#include <QString>
#include <QSqlQueryModel>

class Fiche_suivi
{


public:
    Fiche_suivi();
    Fiche_suivi(int,int,QString,QString);
    int getnum_modele();
    int getage();
    QString getetat();
    QString getdate_derniere_maintenance();
    void setnum_modele(int);
    void setage(int);
    void setgetetat(QString);
    void setdate_derniere_maintenance(QString);
    bool ajouter();
    SqlQueryModel* afficher();


private:
    int num_modele;
    int age;
    QString etat;
    QString date_derniere_maintenance;




};

#endif // FICHE_SUIVI_H
