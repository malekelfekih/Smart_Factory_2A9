#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"fournisseur.h"
#include "commande.h"
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


    void on_bouton_ajouter_clicked();

    void on_bouton_supprimer_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();//fournisseur

    void on_pb_modifier_2_clicked();//commande

    void on_pb_chercher_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur F;
    Commande c;
};
#endif // MAINWINDOW_H
