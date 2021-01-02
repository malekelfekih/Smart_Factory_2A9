/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *ajouter;
    QWidget *ajouterunemplyee;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_cin;
    QLineEdit *le_tel;
    QLineEdit *le_email;
    QLineEdit *le_adresse;
    QLineEdit *le_salaire;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *ajouter_2;
    QLineEdit *le_id;
    QLabel *label_10;
    QLabel *label_11;
    QDateEdit *le_embauche;
    QDateEdit *le_naissance;
    QPushButton *modifier;
    QTableView *table_employee_2;
    QLineEdit *le_identifiant_2;
    QLabel *label_13;
    QPushButton *supprimer_2;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_23;
    QLineEdit *line_recherche;
    QPushButton *chercher;
    QPushButton *trier;
    QComboBox *comboBox_rech;
    QRadioButton *radioButton_up;
    QRadioButton *radioButton_down;
    QComboBox *comboBox_rech_2;
    QComboBox *le_type_contract;
    QWidget *tab_3;
    QLabel *label_16;
    QLineEdit *le_id2;
    QPushButton *accepter;
    QPushButton *refuser;
    QLabel *label_21;
    QLabel *label_22;
    QTableView *liste_demande;
    QPushButton *mise_a_jour;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *widget;
    QLabel *label_24;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *line_id;
    QDateEdit *line_debut;
    QDateEdit *le_date_fin;
    QPushButton *envoyer;
    QLabel *label_29;
    QCheckBox *checkBox_certifier;
    QTableView *table_conges;
    QLabel *label_30;
    QPushButton *pushButton_2;
    QLabel *label_31;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *modif_demande;
    QLineEdit *lineEdit_5;
    QLabel *label_32;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1637, 911);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1451, 641));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        ajouter = new QTabWidget(tab);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(0, 0, 1611, 721));
        QFont font;
        font.setFamily(QStringLiteral("Dubai"));
        font.setPointSize(8);
        ajouter->setFont(font);
        ajouterunemplyee = new QWidget();
        ajouterunemplyee->setObjectName(QStringLiteral("ajouterunemplyee"));
        le_nom = new QLineEdit(ajouterunemplyee);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(150, 70, 113, 22));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_nom->sizePolicy().hasHeightForWidth());
        le_nom->setSizePolicy(sizePolicy);
        le_nom->setStyleSheet(QLatin1String("le_nom{\n"
"	background-color: rgb(88, 88, 88);\n"
"border 2px solid rgb(37,39,48)\n"
"border -raduis : 20px;\n"
"\n"
"}"));
        le_nom->setFrame(true);
        le_nom->setEchoMode(QLineEdit::Normal);
        le_nom->setDragEnabled(false);
        le_nom->setCursorMoveStyle(Qt::LogicalMoveStyle);
        le_nom->setClearButtonEnabled(false);
        le_prenom = new QLineEdit(ajouterunemplyee);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(150, 130, 113, 22));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(7);
        le_prenom->setFont(font1);
        le_prenom->setFrame(true);
        le_cin = new QLineEdit(ajouterunemplyee);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(150, 190, 113, 22));
        le_cin->setFont(font);
        le_cin->setFrame(true);
        le_tel = new QLineEdit(ajouterunemplyee);
        le_tel->setObjectName(QStringLiteral("le_tel"));
        le_tel->setGeometry(QRect(470, 80, 113, 22));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(8);
        le_tel->setFont(font2);
        le_tel->setFrame(true);
        le_email = new QLineEdit(ajouterunemplyee);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(460, 180, 113, 22));
        le_email->setFrame(true);
        le_adresse = new QLineEdit(ajouterunemplyee);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(790, 130, 113, 22));
        le_salaire = new QLineEdit(ajouterunemplyee);
        le_salaire->setObjectName(QStringLiteral("le_salaire"));
        le_salaire->setGeometry(QRect(790, 180, 113, 22));
        label = new QLabel(ajouterunemplyee);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 55, 16));
        label_2 = new QLabel(ajouterunemplyee);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 55, 16));
        label_3 = new QLabel(ajouterunemplyee);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 200, 55, 16));
        label_4 = new QLabel(ajouterunemplyee);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 70, 171, 31));
        label_5 = new QLabel(ajouterunemplyee);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 130, 151, 21));
        label_6 = new QLabel(ajouterunemplyee);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(380, 180, 55, 16));
        label_7 = new QLabel(ajouterunemplyee);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(640, 80, 151, 31));
        label_8 = new QLabel(ajouterunemplyee);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(680, 130, 81, 16));
        label_9 = new QLabel(ajouterunemplyee);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(690, 180, 55, 16));
        ajouter_2 = new QPushButton(ajouterunemplyee);
        ajouter_2->setObjectName(QStringLiteral("ajouter_2"));
        ajouter_2->setGeometry(QRect(700, 300, 93, 28));
        QFont font3;
        font3.setFamily(QStringLiteral("Dubai"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        ajouter_2->setFont(font3);
        le_id = new QLineEdit(ajouterunemplyee);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(150, 240, 113, 22));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial Unicode MS"));
        font4.setPointSize(8);
        le_id->setFont(font4);
        le_id->setFrame(true);
        label_10 = new QLabel(ajouterunemplyee);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 240, 55, 16));
        label_11 = new QLabel(ajouterunemplyee);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(340, 240, 111, 16));
        le_embauche = new QDateEdit(ajouterunemplyee);
        le_embauche->setObjectName(QStringLiteral("le_embauche"));
        le_embauche->setGeometry(QRect(470, 240, 110, 22));
        le_embauche->setFont(font2);
        le_embauche->setFrame(true);
        le_naissance = new QDateEdit(ajouterunemplyee);
        le_naissance->setObjectName(QStringLiteral("le_naissance"));
        le_naissance->setGeometry(QRect(470, 130, 131, 21));
        le_naissance->setFont(font);
        le_naissance->setFrame(true);
        modifier = new QPushButton(ajouterunemplyee);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(560, 300, 93, 28));
        modifier->setFont(font3);
        table_employee_2 = new QTableView(ajouterunemplyee);
        table_employee_2->setObjectName(QStringLiteral("table_employee_2"));
        table_employee_2->setGeometry(QRect(40, 380, 961, 181));
        le_identifiant_2 = new QLineEdit(ajouterunemplyee);
        le_identifiant_2->setObjectName(QStringLiteral("le_identifiant_2"));
        le_identifiant_2->setGeometry(QRect(1080, 120, 131, 31));
        label_13 = new QLabel(ajouterunemplyee);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(960, 120, 101, 21));
        supprimer_2 = new QPushButton(ajouterunemplyee);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(1280, 120, 121, 31));
        supprimer_2->setFont(font3);
        label_12 = new QLabel(ajouterunemplyee);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 330, 241, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("Dubai"));
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setUnderline(true);
        font5.setWeight(75);
        label_12->setFont(font5);
        label_14 = new QLabel(ajouterunemplyee);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(960, 30, 241, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Dubai"));
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setUnderline(true);
        font6.setWeight(75);
        label_14->setFont(font6);
        label_15 = new QLabel(ajouterunemplyee);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 20, 241, 31));
        label_15->setFont(font6);
        label_15->setFrameShape(QFrame::NoFrame);
        label_23 = new QLabel(ajouterunemplyee);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(960, 200, 291, 31));
        label_23->setFont(font6);
        line_recherche = new QLineEdit(ajouterunemplyee);
        line_recherche->setObjectName(QStringLiteral("line_recherche"));
        line_recherche->setGeometry(QRect(1080, 260, 191, 31));
        chercher = new QPushButton(ajouterunemplyee);
        chercher->setObjectName(QStringLiteral("chercher"));
        chercher->setGeometry(QRect(1290, 260, 93, 28));
        chercher->setFont(font3);
        trier = new QPushButton(ajouterunemplyee);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(1060, 440, 93, 28));
        trier->setFont(font3);
        comboBox_rech = new QComboBox(ajouterunemplyee);
        comboBox_rech->setObjectName(QStringLiteral("comboBox_rech"));
        comboBox_rech->setGeometry(QRect(910, 260, 141, 21));
        radioButton_up = new QRadioButton(ajouterunemplyee);
        radioButton_up->setObjectName(QStringLiteral("radioButton_up"));
        radioButton_up->setGeometry(QRect(1170, 430, 95, 20));
        radioButton_down = new QRadioButton(ajouterunemplyee);
        radioButton_down->setObjectName(QStringLiteral("radioButton_down"));
        radioButton_down->setGeometry(QRect(1170, 450, 95, 20));
        comboBox_rech_2 = new QComboBox(ajouterunemplyee);
        comboBox_rech_2->setObjectName(QStringLiteral("comboBox_rech_2"));
        comboBox_rech_2->setGeometry(QRect(1050, 390, 141, 21));
        le_type_contract = new QComboBox(ajouterunemplyee);
        le_type_contract->setObjectName(QStringLiteral("le_type_contract"));
        le_type_contract->setGeometry(QRect(780, 80, 141, 31));
        le_type_contract->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        ajouter->addTab(ajouterunemplyee, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(710, 130, 55, 16));
        le_id2 = new QLineEdit(tab_3);
        le_id2->setObjectName(QStringLiteral("le_id2"));
        le_id2->setGeometry(QRect(770, 130, 113, 22));
        accepter = new QPushButton(tab_3);
        accepter->setObjectName(QStringLiteral("accepter"));
        accepter->setGeometry(QRect(920, 130, 93, 28));
        refuser = new QPushButton(tab_3);
        refuser->setObjectName(QStringLiteral("refuser"));
        refuser->setGeometry(QRect(1030, 130, 93, 28));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(710, 40, 131, 31));
        QFont font7;
        font7.setFamily(QStringLiteral("Dubai"));
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setUnderline(true);
        font7.setWeight(75);
        label_21->setFont(font7);
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(60, 40, 241, 31));
        label_22->setFont(font7);
        liste_demande = new QTableView(tab_3);
        liste_demande->setObjectName(QStringLiteral("liste_demande"));
        liste_demande->setGeometry(QRect(50, 90, 571, 221));
        mise_a_jour = new QPushButton(tab_3);
        mise_a_jour->setObjectName(QStringLiteral("mise_a_jour"));
        mise_a_jour->setGeometry(QRect(530, 330, 93, 28));
        ajouter->addTab(tab_3, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1441, 601));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(70, 110, 101, 21));
        label_27 = new QLabel(widget);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(70, 160, 81, 21));
        label_28 = new QLabel(widget);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(80, 210, 81, 16));
        line_id = new QLineEdit(widget);
        line_id->setObjectName(QStringLiteral("line_id"));
        line_id->setGeometry(QRect(190, 110, 113, 22));
        line_debut = new QDateEdit(widget);
        line_debut->setObjectName(QStringLiteral("line_debut"));
        line_debut->setGeometry(QRect(190, 160, 110, 22));
        le_date_fin = new QDateEdit(widget);
        le_date_fin->setObjectName(QStringLiteral("le_date_fin"));
        le_date_fin->setGeometry(QRect(190, 210, 110, 22));
        envoyer = new QPushButton(widget);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(370, 120, 93, 28));
        QFont font8;
        font8.setBold(true);
        font8.setWeight(75);
        envoyer->setFont(font8);
        label_29 = new QLabel(widget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(90, 40, 201, 31));
        QFont font9;
        font9.setPointSize(11);
        label_29->setFont(font9);
        checkBox_certifier = new QCheckBox(widget);
        checkBox_certifier->setObjectName(QStringLiteral("checkBox_certifier"));
        checkBox_certifier->setGeometry(QRect(150, 260, 81, 20));
        table_conges = new QTableView(widget);
        table_conges->setObjectName(QStringLiteral("table_conges"));
        table_conges->setGeometry(QRect(610, 100, 721, 261));
        label_30 = new QLabel(widget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(610, 40, 311, 31));
        QFont font10;
        font10.setPointSize(11);
        font10.setBold(false);
        font10.setWeight(50);
        label_30->setFont(font10);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1200, 420, 93, 28));
        pushButton_2->setFont(font8);
        label_31 = new QLabel(widget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(690, 430, 201, 21));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(930, 420, 241, 31));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1200, 480, 93, 28));
        pushButton_3->setFont(font8);
        modif_demande = new QPushButton(widget);
        modif_demande->setObjectName(QStringLiteral("modif_demande"));
        modif_demande->setGeometry(QRect(370, 190, 93, 28));
        modif_demande->setFont(font8);
        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(930, 480, 241, 31));
        label_32 = new QLabel(widget);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(690, 480, 211, 21));
        tabWidget_2->addTab(widget, QString());
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1637, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        ajouter->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        le_nom->setPlaceholderText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        le_prenom->setPlaceholderText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        le_cin->setPlaceholderText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        le_tel->setPlaceholderText(QApplication::translate("MainWindow", "num-tel", Q_NULLPTR));
        le_email->setPlaceholderText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        le_adresse->setPlaceholderText(QApplication::translate("MainWindow", "adresse", Q_NULLPTR));
        le_salaire->setPlaceholderText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "num\303\251ro de t\303\251l\303\251phone", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "date de naissance", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "type de contract", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "adresse", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        ajouter_2->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        le_id->setPlaceholderText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "date d'embauche", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        le_identifiant_2->setPlaceholderText(QApplication::translate("MainWindow", "identifiant", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "la liste  des employ\303\251s :", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "supprimer un employ\303\251s :", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "ajouter un employ\303\251 :", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "chercher un employ\303\251 par ID:", Q_NULLPTR));
        chercher->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        trier->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        comboBox_rech->clear();
        comboBox_rech->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "prenom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "email", Q_NULLPTR)
         << QApplication::translate("MainWindow", "adresse", Q_NULLPTR)
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "cin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "num_telephone", Q_NULLPTR)
         << QApplication::translate("MainWindow", "salaire", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date de naissance", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date d'embauche", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type de contract", Q_NULLPTR)
         << QString()
         << QString()
         << QString()
         << QString()
        );
        radioButton_up->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        radioButton_down->setText(QApplication::translate("MainWindow", "down", Q_NULLPTR));
        comboBox_rech_2->clear();
        comboBox_rech_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date d'embauche", Q_NULLPTR)
         << QApplication::translate("MainWindow", "salaire", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QString()
         << QString()
         << QString()
         << QString()
         << QString()
        );
        le_type_contract->clear();
        le_type_contract->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "CDI", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CDD", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CTT", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CUI", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CAE", Q_NULLPTR)
        );
        le_type_contract->setPlaceholderText(QString());
        ajouter->setTabText(ajouter->indexOf(ajouterunemplyee), QApplication::translate("MainWindow", "traiter les profils des employ\303\251s", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "ID :", Q_NULLPTR));
        accepter->setText(QApplication::translate("MainWindow", "accepter", Q_NULLPTR));
        refuser->setText(QApplication::translate("MainWindow", "refuser", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "demande :", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "liste des demandes :", Q_NULLPTR));
        mise_a_jour->setText(QApplication::translate("MainWindow", "Mise \303\240 jour", Q_NULLPTR));
        ajouter->setTabText(ajouter->indexOf(tab_3), QApplication::translate("MainWindow", "traiter les cong\303\251s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "espace admin", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "DATE DEBUT:", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "DATE_FIN :", Q_NULLPTR));
        envoyer->setText(QApplication::translate("MainWindow", "envoyer", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "remplir le formulaire :", Q_NULLPTR));
        checkBox_certifier->setText(QApplication::translate("MainWindow", "certifi\303\251 ", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "Afficher la liste de mes cong\303\251s :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "chercherr", Q_NULLPTR));
        label_31->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        modif_demande->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "supprimer une demande par date :", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(widget), QApplication::translate("MainWindow", "envoyer une demande de cong\303\251", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "espace employ\303\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
