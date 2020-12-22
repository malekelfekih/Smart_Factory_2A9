#include "connexion.h"
#include <QDebug>
//test tutoriel git

Connexion::Connexion()
{

}

bool Connexion:: ouvrirConnexion()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("db_smartF");
db.setUserName("malek1");
db.setPassword("test");


if (db.open())
test=true;

qDebug()<<db.lastError().text();



    return  test;
}
