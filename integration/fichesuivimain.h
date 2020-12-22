#ifndef FICHESUIVIMAIN_H
#define FICHESUIVIMAIN_H
#include "fiche_suivi.h"
#include <QDialog>

namespace Ui {
class Fichesuivimain;
}

class Fichesuivimain : public QDialog
{
    Q_OBJECT

public:
    explicit Fichesuivimain(QWidget *parent = nullptr);
    ~Fichesuivimain();

private slots:
    void on_pushButtonajouter1_clicked();

private:
    Ui::Fichesuivimain *ui;
    Fiche_suivi F ;
};

#endif // FICHE_SUIVIMAIN_H
