#ifndef COMMANDE_H
#define COMMANDE_H
#include "commandef.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {class Commande;}

class Commande: public QDialog
{
    Q_OBJECT

public:
    explicit Commande(QWidget *parent = nullptr);
    ~Commande();


private slots:

    void on_bouton_ajouter_clicked();

private:
     Ui::Commande *ui;
     Commande_F C;

};

#endif // COMMANDE_H
