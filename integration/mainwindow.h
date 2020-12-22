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

private:
    Ui::MainWindow *ui;
    Machine M;
    Fichesuivi FS;
    Statistiques *s;
    Machinefiche MF;


    Fournisseur F;
    Commande c;


    QByteArray data;
    Arduino A;
    int x=0;
};
#endif // MAINWINDOW_H
