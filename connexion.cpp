#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("smart_factory");
db.setUserName("omayma");//inserer nom de l'utilisateur
db.setPassword("omayma2000");//inserer mot de passe de cet utilisateur

if (db.open())
return true;
    return  false;
}

void Connexion::fermerConnexion()
{db.close();}
