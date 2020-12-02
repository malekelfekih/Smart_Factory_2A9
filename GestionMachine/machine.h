#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQueryModel>


class Machine
{
public:
    Machine();
    Machine(QString,int,int,int);
    QString getnum_serie();
    int getcapacite_production();
    int getpuissance_moteur();
    int getnb_heure();
    void setnum_serie(QString);
    void setcapacite_production(int);
    void setpuissance_moteur(int);
    void setnb_heure(int);
    bool ajouter();
    bool verifvidestring(QString);
    bool verifiernum_serie(QString);
    bool verifiernum_serie_machine(QString);
    bool verifvideint(int);
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    QSqlQueryModel * chercher(int,QString);
    QSqlQueryModel* consulternb();
    QSqlQueryModel* affichermachine();






private :
   QString num_serie ;
   int capacite_production ;
   int puissance_moteur;
   int nb_heure;


};

#endif // MACHINE_H
