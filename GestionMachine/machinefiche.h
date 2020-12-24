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
    QString getnum_serie();
    QSqlQueryModel* afficherserie();
    QSqlQueryModel* affichermodele();
    QSqlQueryModel *affichermachinefiche();
    bool ajouter();
    bool verifiernum_serie(QString);
    QSqlQueryModel * chercher1(int,QString );




private:
    QString num_serie_machine;
    int num_modele_fiche;

};

#endif // MACHINEFICHE_H
