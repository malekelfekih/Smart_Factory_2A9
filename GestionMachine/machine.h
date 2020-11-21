#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSqlQueryModel>

class Machine
{
public:
    Machine();
    Machine(QString,int,int,QString);
    QString getnum_serie();
    int getcapacite_production();
    int getpuissance_moteur();
    QString getnb_heure();
    void setnum_serie(QString);
    void setcapacite_production(int);
    void setpuissance_moteur(int);
    void setnb_heure(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);





private :
   QString num_serie ;
   int capacite_production ;
   int puissance_moteur;
   QString nb_heure;


};

#endif // MACHINE_H
