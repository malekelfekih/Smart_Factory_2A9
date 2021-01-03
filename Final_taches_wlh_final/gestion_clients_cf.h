#ifndef GESTION_CLIENTS_CF_H
#define GESTION_CLIENTS_CF_H

#include "cf.h"
#include "client.h"
#include <QDebug>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QFileInfo>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QLabel>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QMovie>
#include <QPainter>
#include <QPdfWriter>
#include <QPropertyAnimation>
#include <QSqlDatabase>
#include <QTimer>
#include <QUrl>
#include <QWidget>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class Gestion_Clients_CF;
}
QT_END_NAMESPACE

class Gestion_Clients_CF : public QMainWindow {
  Q_OBJECT

public:
  Gestion_Clients_CF(QWidget *parent = nullptr);
  ~Gestion_Clients_CF();

private slots:
  void on_add_clicked();

  void on_stats_clicked();

  void on_display_clicked();

  void on_tri_clicked();

  void on_search_clicked();

  void on_pushButton_5_clicked();

  void on_delete_2_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::Gestion_Clients_CF *ui;
  client E;
  QSqlDatabase mydb;
  QPropertyAnimation *animation;
  QMediaPlayer *player;
  QLabel *Gif_Anim;
  QMovie *movie;
  QGraphicsProxyWidget *proxy;
  QGraphicsScene *scene;
  QPdfWriter *PDFWriter;
  QTimer timer;
  QString operateur;
  cf carteF;
};
#endif // GESTION_CLIENTS_CF_H
