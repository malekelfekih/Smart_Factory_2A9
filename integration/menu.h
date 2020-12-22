#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "machine.h"
#include "fichesuivi.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButtonmachine_clicked();

    void on_pushButtonfiche_clicked();

private:
    Ui::menu *ui;
    Fichesuivi *fs;
    Machine *ma;

};

#endif // MENU_H
