/********************************************************************************
** Form generated from reading UI file 'demande.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMANDE_H
#define UI_DEMANDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demande
{
public:
    QTabWidget *tabWidget;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *line_id;
    QLineEdit *line_nom;
    QLineEdit *line_prenom;
    QDateEdit *line_debut;
    QDateEdit *line_fin;
    QPushButton *envoyer;
    QLabel *label_6;
    QCheckBox *checkBox_certifier;
    QTableView *tableView;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QWidget *en;
    QPushButton *pushButton;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label_11;

    void setupUi(QDialog *demande)
    {
        if (demande->objectName().isEmpty())
            demande->setObjectName(QStringLiteral("demande"));
        demande->resize(1438, 682);
        tabWidget = new QTabWidget(demande);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 30, 1371, 601));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 110, 101, 21));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 160, 55, 16));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 200, 71, 16));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 240, 81, 21));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 290, 81, 16));
        line_id = new QLineEdit(widget);
        line_id->setObjectName(QStringLiteral("line_id"));
        line_id->setGeometry(QRect(200, 100, 113, 22));
        line_nom = new QLineEdit(widget);
        line_nom->setObjectName(QStringLiteral("line_nom"));
        line_nom->setGeometry(QRect(200, 150, 113, 22));
        line_prenom = new QLineEdit(widget);
        line_prenom->setObjectName(QStringLiteral("line_prenom"));
        line_prenom->setGeometry(QRect(200, 190, 113, 22));
        line_debut = new QDateEdit(widget);
        line_debut->setObjectName(QStringLiteral("line_debut"));
        line_debut->setGeometry(QRect(200, 240, 110, 22));
        line_fin = new QDateEdit(widget);
        line_fin->setObjectName(QStringLiteral("line_fin"));
        line_fin->setGeometry(QRect(200, 290, 110, 22));
        envoyer = new QPushButton(widget);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(370, 120, 93, 28));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        envoyer->setFont(font);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 40, 201, 31));
        QFont font1;
        font1.setPointSize(11);
        label_6->setFont(font1);
        checkBox_certifier = new QCheckBox(widget);
        checkBox_certifier->setObjectName(QStringLiteral("checkBox_certifier"));
        checkBox_certifier->setGeometry(QRect(150, 340, 81, 20));
        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(610, 100, 721, 261));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(610, 40, 311, 31));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        label_7->setFont(font2);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1200, 420, 93, 28));
        pushButton_2->setFont(font);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(690, 430, 201, 21));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(930, 420, 241, 31));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1200, 480, 93, 28));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 190, 93, 28));
        pushButton_4->setFont(font);
        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(930, 480, 241, 31));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(690, 480, 211, 21));
        tabWidget->addTab(widget, QString());
        en = new QWidget();
        en->setObjectName(QStringLiteral("en"));
        pushButton = new QPushButton(en);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 410, 93, 28));
        label_10 = new QLabel(en);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 100, 91, 16));
        lineEdit = new QLineEdit(en);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(240, 140, 161, 31));
        textEdit = new QTextEdit(en);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(250, 200, 551, 191));
        label_11 = new QLabel(en);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 150, 101, 16));
        tabWidget->addTab(en, QString());

        retranslateUi(demande);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(demande);
    } // setupUi

    void retranslateUi(QDialog *demande)
    {
        demande->setWindowTitle(QApplication::translate("demande", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("demande", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("demande", "NOM :", Q_NULLPTR));
        label_3->setText(QApplication::translate("demande", "PRENOM :", Q_NULLPTR));
        label_4->setText(QApplication::translate("demande", "DATE DEBUT:", Q_NULLPTR));
        label_5->setText(QApplication::translate("demande", "DATE_FIN :", Q_NULLPTR));
        envoyer->setText(QApplication::translate("demande", "envoyer", Q_NULLPTR));
        label_6->setText(QApplication::translate("demande", "remplir le formulaire :", Q_NULLPTR));
        checkBox_certifier->setText(QApplication::translate("demande", "certifi\303\251 ", Q_NULLPTR));
        label_7->setText(QApplication::translate("demande", "Afficher la liste de mes cong\303\251s :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("demande", "chercherr", Q_NULLPTR));
        label_8->setText(QApplication::translate("demande", "chercher une demande par date :", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("demande", "supprimer", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("demande", "modifier", Q_NULLPTR));
        label_9->setText(QApplication::translate("demande", "supprimer une demande par date :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("demande", "envoyer une demande de cong\303\251", Q_NULLPTR));
        pushButton->setText(QApplication::translate("demande", "envoyer", Q_NULLPTR));
        label_10->setText(QApplication::translate("demande", "boite mail :", Q_NULLPTR));
        label_11->setText(QApplication::translate("demande", "destinataire :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(en), QApplication::translate("demande", "envoyer un mail ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class demande: public Ui_demande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMANDE_H
