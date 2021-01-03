#ifndef CLIENT_H
#define CLIENT_H

#include <QDesktopServices>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QLabel>
#include <QMediaPlayer>
#include <QMovie>
#include <QPainter>
#include <QPdfWriter>
#include <QPropertyAnimation>
#include <QString>
#include <QUrl>
#include <QWidget>
#include <QtSql>

class client {
public:
  client();
  client(QString, QString, QString, QString, QString, QString, QString);

  bool openConn();
  void closeConn(QSqlDatabase mydb);

  QString getnom() { return nom; }
  QString getprenom() { return prenom; }
  QString getnum() { return num; }
  QString getcin() { return cin; }
  QString getmail() { return mail; }
  QString gethbd() { return hbd; }
  QString getOperateur() { return operateur; }

  void setnom(QString);
  void setprenom(QString);
  void setcin(QString);
  void sethbd(QString);
  void setmail(QString);
  void setnum(QString);
  void setOperateur(QString);

  bool ajouter();
  QSqlQueryModel *afficher();
  bool supprimer(QString);
  QSqlQueryModel *chercher(int, QString);
  QSqlQueryModel *chercher2(QString);
  bool verifier_cin_client(QString cin);
  bool update_client(QString, QString, QString, QString, QString, QString,
                     QString);
  QSqlQueryModel *display(QSqlDatabase mydb);
  QSqlQueryModel *triUP(int test);
  QSqlQueryModel *triDOWN(int test);
  void create_pdf(QString, QString, QString);
  int calculer(QString);

private:
  QString nom;
  QString prenom;
  QString cin;
  QString mail;
  QString hbd;
  QString num;
  QString operateur;
};
#endif // CLIENT_H
