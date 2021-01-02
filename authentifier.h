#ifndef AUTHENTIFIER_H
#define AUTHENTIFIER_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class authentifier;
}

class authentifier : public QDialog
{
    Q_OBJECT

public:
    explicit authentifier(QWidget *parent = nullptr);
    ~authentifier();
    authentifier();
    authentifier(QString , QString);
    bool ajouter();
    QSqlQueryModel * afficher();

private slots:
   // void on_pushButton_clicked();

private:
    Ui::authentifier *ui;
    QString login , password;

};

#endif // AUTHENTIFIER_H
