#ifndef CF_H
#define CF_H

#include "client.h"

class cf {
public:
  cf();
  cf(QString, int);

  QString getID() { return ID; }
  int getSolde() { return solde; }

  void setID(QString);
  void setSolde(int);

  QString generateID();
  bool ajouter(QString);
  bool supprimer(QString);
  QSqlQueryModel *displayCF(QSqlDatabase);
  QSqlQueryModel *triDOWN(int);
  QSqlQueryModel *triUP(int);

private:
  QString ID;
  int solde;
  cf *carteF;
};


#endif // CF_H
