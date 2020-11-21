#ifndef FICHEWINDOW_H
#define FICHEWINDOW_H
#include <QDialog>
#include "fichesuivi.h"

namespace Ui {
class fichewindow;
}

class fichewindow : public QDialog
{
    Q_OBJECT

public:
    explicit fichewindow(QWidget *parent = nullptr);
    ~fichewindow();

private slots:
    void on_pushButtonajouter1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonmodifier_clicked();

private:
    Ui::fichewindow *ui;
    Fichesuivi F;
};

#endif // FICHEWINDOW_H
