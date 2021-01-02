#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "demande.h"
#include "authentifier.h"
#include <QMessageBox>
#include<QSqlQuery>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

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

private:
    Ui::MainWindow *ui;
     EMPLOYEE E;
     demande d;


};

#endif // MAINWINDOW_H
