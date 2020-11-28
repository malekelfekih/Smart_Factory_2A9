#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQueryModel>

class Commande_F
{
public:
   Commande_F();
    Commande_F(int,float,QString,QString,QString);

    int getid();
    float getmontant();
    QString gettype();
    QString getdate();
     QString getmode_paiment();

    void setid(int);
    void setmontant(float);
    void settype(QString);
    void setdate(QString);
    void setmode_paiment(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);

private:

    int id;
    float montant;
    QString type,date,mode_paiment;

};

#endif // COMMANDE_H
