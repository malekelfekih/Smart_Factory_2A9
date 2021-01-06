#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "machine.h"
#include "fichesuivi.h"
#include "statistiques.h"
#include "machinefiche.h"
#include"fournisseur.h"
#include "commande.h"
#include "arduino.h"
#include "employee.h"
#include "demande.h"
#include "statf.h"
#include "cf.h"
#include "client.h"
#include "arduino1.h"
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
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonajouter_clicked();
    void on_pushButtonsupprimer_clicked();
    void on_pushButtonrecherche_clicked();

    void on_pushButtonajouter1_clicked();

    void on_pushButtonimprimer_clicked();

    void on_pushButtonmodifier_clicked();

    void on_pushButtonsupprimer2_clicked();


    void on_pushButton_clicked();

    void on_pushButtonrecherche1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonajoutermf_clicked();

    void on_pushButtonrecherche1_2_clicked();


    //******Fournisseur****

    void on_bouton_ajouter_clicked();

    void on_bouton_supprimer_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();//fournisseur

    void on_pb_modifier_2_clicked();//commande

    void on_pb_chercher_clicked();//commande

    void on_pb_chercher_2_clicked();//fournisseur

    void on_pb_imprimer_clicked();


    //***************arduino***********
   void on_Demander_clicked();//arduino

    void update_label(); //arduino
 //*****************employee*********
    void on_ajouter_2_clicked();







    void on_modifier_clicked();

    void on_supprimer_2_clicked();



    void on_chercher_clicked();





    void on_trier_clicked();

    void on_envoyer_clicked();



    void on_modif_demande_clicked();

   // void on_mise_ajour_clicked();

    void on_mise_a_jour_clicked();

   // void on_mise_a_jours_clicked();

    void on_accepter_clicked();

   void on_refuser_clicked();

   // void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    //void on_pushButton_3_clicked();

    void on_supprimer_demande_clicked();



    void on_recherche_demande_clicked();

    void on_trier_les_demandes_clicked();

   // void on_pushButton_clicked();

  //  void on_stat_clicked();
    void on_stat_clicked();


    //**********************client

    void on_add_clicked();

    void on_stats_clicked();

    void on_display_clicked();

    void on_tri_clicked();

    void on_search_clicked();

    void on_pushButton_5_clicked();

    void on_delete_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    //void on_Desactiver_clicked();

    void on_tri_2_clicked();

    void update_label1();


private:
    Ui::MainWindow *ui;
    Machine M;
    Fichesuivi FS;
    Statistiques *s;
    Machinefiche MF;


    Fournisseur F;
    Commande c;


    EMPLOYEE E;
    demande d;



    client CL;
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


    QByteArray data;
    Arduino A;
    Arduino A1;
    int x=0;
};
#endif // MAINWINDOW_H
