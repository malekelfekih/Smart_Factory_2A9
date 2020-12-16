#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "machine.h"
#include "fichesuivi.h"
#include "statistiques.h"
#include "machinefiche.h"


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

private:
    Ui::MainWindow *ui;
    Machine M;
    Fichesuivi F;
    Statistiques *s;
    Machinefiche MF;
};
#endif // MAINWINDOW_H
