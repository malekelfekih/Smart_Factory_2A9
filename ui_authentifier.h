/********************************************************************************
** Form generated from reading UI file 'authentifier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTIFIER_H
#define UI_AUTHENTIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_authentifier
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;

    void setupUi(QDialog *authentifier)
    {
        if (authentifier->objectName().isEmpty())
            authentifier->setObjectName(QStringLiteral("authentifier"));
        authentifier->resize(1018, 563);
        groupBox = new QGroupBox(authentifier);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(149, 39, 611, 431));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 300, 93, 28));
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(250, 160, 231, 31));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(250, 230, 231, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 170, 55, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 240, 111, 21));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(280, 80, 201, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 90, 161, 21));

        retranslateUi(authentifier);

        QMetaObject::connectSlotsByName(authentifier);
    } // setupUi

    void retranslateUi(QDialog *authentifier)
    {
        authentifier->setWindowTitle(QApplication::translate("authentifier", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("authentifier", "login", Q_NULLPTR));
        label->setText(QApplication::translate("authentifier", "login :", Q_NULLPTR));
        label_2->setText(QApplication::translate("authentifier", "mot de passe :", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("authentifier", "admin", Q_NULLPTR)
         << QApplication::translate("authentifier", "employer", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("authentifier", "s'authentifier en tant que :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class authentifier: public Ui_authentifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTIFIER_H
