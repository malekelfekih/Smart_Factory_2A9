#ifndef MACHINEFICHE_H
#define MACHINEFICHE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQueryModel>

class Machinefiche
{
public:
    Machinefiche();
    Machinefiche(QString,int);
    int getnum_modele();
    QSqlQueryModel* afficherserie();
    QSqlQueryModel* affichermodele();
    QSqlQueryModel *affichermachinefiche();
    bool ajouter();
    bool verifiernum_modele(int);
    QSqlQueryModel * chercher1(int,QString );





private:
    QString num_serie_machine;
    int num_modele_fiche;

};

#endif // MACHINEFICHE_H
