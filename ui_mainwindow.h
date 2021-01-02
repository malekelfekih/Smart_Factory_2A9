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
#include <QtWidgets/QComboBox>
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
    QLabel *label_11;
    QPushButton *modifier;
    QTableView *table_employee_2;
    QLabel *label_13;
    QPushButton *supprimer_2;
    QLabel *label_12;
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
    QPushButton *stat;
    QLabel *label_17;
    QComboBox *comboBox_id2;
    QLineEdit *line_embauche;
    QLineEdit *line_naisance;
    QLabel *label_18;
    QWidget *tab_3;
    QLabel *label_16;
    QPushButton *accepter;
    QPushButton *refuser;
    QLabel *label_21;
    QLabel *label_22;
    QTableView *liste_demande;
    QPushButton *mise_a_jour;
    QComboBox *comboBox_id4;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *widget;
    QLabel *label_24;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *line_id;
    QPushButton *envoyer;
    QLabel *label_29;
    QTableView *table_conges;
    QLabel *label_30;
    QPushButton *recherche_demande;
    QLabel *label_31;
    QLineEdit *lineEdit_4;
    QPushButton *supprimer_demande;
    QPushButton *modif_demande;
    QComboBox *combo_re;
    QRadioButton *up;
    QRadioButton *down;
    QPushButton *trier_les_demandes;
    QComboBox *combobox_tri2;
    QLabel *label_14;
    QLineEdit *line_date_fin;
    QLineEdit *line_date_debut;
    QLabel *label_10;
    QComboBox *comboBox_type_conge;
    QComboBox *comboBox_id_em;
    QComboBox *comboBox_id3;
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
        centralWidget->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background : #F0E5C7;\n"
"}"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1451, 721));
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        ajouter = new QTabWidget(tab);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(0, 0, 1611, 721));
        QFont font;
        font.setFamily(QStringLiteral("Dubai"));
        font.setPointSize(8);
        ajouter->setFont(font);
        ajouter->setStyleSheet(QLatin1String("tab_widgets\n"
"{\n"
"color ::rgb(204, 174, 206)\n"
"}"));
        ajouter->setDocumentMode(true);
        ajouter->setTabsClosable(true);
        ajouter->setMovable(false);
        ajouter->setTabBarAutoHide(false);
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
        le_nom->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"color :: #F0E5C7;\n"
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
        le_email->setGeometry(QRect(470, 180, 113, 22));
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
        ajouter_2->setGeometry(QRect(730, 270, 93, 28));
        QFont font3;
        font3.setFamily(QStringLiteral("Dubai"));
        font3.setPointSize(10);
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
        label_11 = new QLabel(ajouterunemplyee);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(340, 240, 111, 16));
        modifier = new QPushButton(ajouterunemplyee);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(1070, 190, 121, 31));
        modifier->setFont(font3);
        table_employee_2 = new QTableView(ajouterunemplyee);
        table_employee_2->setObjectName(QStringLiteral("table_employee_2"));
        table_employee_2->setGeometry(QRect(40, 380, 831, 191));
        label_13 = new QLabel(ajouterunemplyee);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1070, 40, 111, 21));
        label_13->setFont(font3);
        supprimer_2 = new QPushButton(ajouterunemplyee);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(1070, 140, 121, 31));
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
        label_15 = new QLabel(ajouterunemplyee);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 20, 241, 31));
        QFont font6;
        font6.setFamily(QStringLiteral("Dubai"));
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setUnderline(true);
        font6.setWeight(75);
        label_15->setFont(font6);
        label_15->setFrameShape(QFrame::NoFrame);
        label_23 = new QLabel(ajouterunemplyee);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(930, 250, 321, 31));
        label_23->setFont(font6);
        line_recherche = new QLineEdit(ajouterunemplyee);
        line_recherche->setObjectName(QStringLiteral("line_recherche"));
        line_recherche->setGeometry(QRect(1110, 310, 201, 31));
        chercher = new QPushButton(ajouterunemplyee);
        chercher->setObjectName(QStringLiteral("chercher"));
        chercher->setGeometry(QRect(1330, 310, 93, 28));
        QFont font7;
        font7.setFamily(QStringLiteral("Dubai"));
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        chercher->setFont(font7);
        trier = new QPushButton(ajouterunemplyee);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(1130, 380, 93, 28));
        trier->setFont(font3);
        comboBox_rech = new QComboBox(ajouterunemplyee);
        comboBox_rech->setObjectName(QStringLiteral("comboBox_rech"));
        comboBox_rech->setGeometry(QRect(940, 310, 141, 21));
        radioButton_up = new QRadioButton(ajouterunemplyee);
        radioButton_up->setObjectName(QStringLiteral("radioButton_up"));
        radioButton_up->setGeometry(QRect(1260, 370, 95, 20));
        radioButton_down = new QRadioButton(ajouterunemplyee);
        radioButton_down->setObjectName(QStringLiteral("radioButton_down"));
        radioButton_down->setGeometry(QRect(1260, 400, 95, 20));
        comboBox_rech_2 = new QComboBox(ajouterunemplyee);
        comboBox_rech_2->setObjectName(QStringLiteral("comboBox_rech_2"));
        comboBox_rech_2->setGeometry(QRect(940, 380, 141, 21));
        le_type_contract = new QComboBox(ajouterunemplyee);
        le_type_contract->setObjectName(QStringLiteral("le_type_contract"));
        le_type_contract->setGeometry(QRect(790, 80, 111, 21));
        le_type_contract->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"color ::#EFE6D7;\n"
"}"));
        le_type_contract->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        stat = new QPushButton(ajouterunemplyee);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(1070, 520, 151, 31));
        QFont font8;
        font8.setFamily(QStringLiteral("Dubai"));
        font8.setPointSize(10);
        stat->setFont(font8);
        label_17 = new QLabel(ajouterunemplyee);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(930, 460, 381, 31));
        label_17->setFont(font6);
        comboBox_id2 = new QComboBox(ajouterunemplyee);
        comboBox_id2->setObjectName(QStringLiteral("comboBox_id2"));
        comboBox_id2->setGeometry(QRect(1070, 80, 121, 22));
        line_embauche = new QLineEdit(ajouterunemplyee);
        line_embauche->setObjectName(QStringLiteral("line_embauche"));
        line_embauche->setGeometry(QRect(470, 240, 113, 22));
        line_naisance = new QLineEdit(ajouterunemplyee);
        line_naisance->setObjectName(QStringLiteral("line_naisance"));
        line_naisance->setGeometry(QRect(470, 130, 113, 22));
        label_18 = new QLabel(ajouterunemplyee);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(60, 250, 55, 16));
        ajouter->addTab(ajouterunemplyee, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1090, 190, 81, 20));
        accepter = new QPushButton(tab_3);
        accepter->setObjectName(QStringLiteral("accepter"));
        accepter->setGeometry(QRect(1220, 250, 93, 28));
        accepter->setFont(font3);
        refuser = new QPushButton(tab_3);
        refuser->setObjectName(QStringLiteral("refuser"));
        refuser->setGeometry(QRect(1220, 300, 93, 28));
        refuser->setFont(font3);
        refuser->setFocusPolicy(Qt::StrongFocus);
        refuser->setInputMethodHints(Qt::ImhNone);
        refuser->setCheckable(false);
        refuser->setAutoRepeat(false);
        refuser->setAutoExclusive(false);
        refuser->setAutoDefault(false);
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(710, 40, 131, 31));
        QFont font9;
        font9.setFamily(QStringLiteral("Dubai"));
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setUnderline(true);
        font9.setWeight(75);
        label_21->setFont(font9);
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(80, 90, 241, 31));
        label_22->setFont(font9);
        liste_demande = new QTableView(tab_3);
        liste_demande->setObjectName(QStringLiteral("liste_demande"));
        liste_demande->setGeometry(QRect(70, 160, 961, 241));
        mise_a_jour = new QPushButton(tab_3);
        mise_a_jour->setObjectName(QStringLiteral("mise_a_jour"));
        mise_a_jour->setGeometry(QRect(940, 420, 93, 28));
        QFont font10;
        font10.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font10.setPointSize(8);
        font10.setBold(true);
        font10.setWeight(75);
        mise_a_jour->setFont(font10);
        comboBox_id4 = new QComboBox(tab_3);
        comboBox_id4->setObjectName(QStringLiteral("comboBox_id4"));
        comboBox_id4->setGeometry(QRect(1190, 190, 161, 31));
        ajouter->addTab(tab_3, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1441, 651));
        tabWidget_2->setDocumentMode(true);
        tabWidget_2->setTabsClosable(true);
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
        envoyer = new QPushButton(widget);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(200, 380, 93, 28));
        QFont font11;
        font11.setBold(true);
        font11.setWeight(75);
        envoyer->setFont(font11);
        label_29 = new QLabel(widget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(90, 40, 201, 31));
        QFont font12;
        font12.setPointSize(11);
        label_29->setFont(font12);
        table_conges = new QTableView(widget);
        table_conges->setObjectName(QStringLiteral("table_conges"));
        table_conges->setGeometry(QRect(530, 100, 801, 261));
        label_30 = new QLabel(widget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(530, 40, 311, 31));
        QFont font13;
        font13.setPointSize(11);
        font13.setBold(false);
        font13.setWeight(50);
        label_30->setFont(font13);
        recherche_demande = new QPushButton(widget);
        recherche_demande->setObjectName(QStringLiteral("recherche_demande"));
        recherche_demande->setGeometry(QRect(1200, 420, 93, 28));
        recherche_demande->setFont(font11);
        recherche_demande->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"color :: red\n"
"}"));
        label_31 = new QLabel(widget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(690, 430, 201, 21));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(930, 420, 241, 31));
        supprimer_demande = new QPushButton(widget);
        supprimer_demande->setObjectName(QStringLiteral("supprimer_demande"));
        supprimer_demande->setGeometry(QRect(1080, 490, 93, 28));
        supprimer_demande->setFont(font11);
        modif_demande = new QPushButton(widget);
        modif_demande->setObjectName(QStringLiteral("modif_demande"));
        modif_demande->setGeometry(QRect(960, 490, 101, 31));
        modif_demande->setFont(font11);
        combo_re = new QComboBox(widget);
        combo_re->setObjectName(QStringLiteral("combo_re"));
        combo_re->setGeometry(QRect(710, 420, 171, 31));
        up = new QRadioButton(widget);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(1210, 540, 95, 20));
        down = new QRadioButton(widget);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(1210, 580, 95, 20));
        trier_les_demandes = new QPushButton(widget);
        trier_les_demandes->setObjectName(QStringLiteral("trier_les_demandes"));
        trier_les_demandes->setGeometry(QRect(940, 560, 211, 28));
        combobox_tri2 = new QComboBox(widget);
        combobox_tri2->setObjectName(QStringLiteral("combobox_tri2"));
        combobox_tri2->setGeometry(QRect(740, 560, 141, 21));
        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 260, 81, 16));
        line_date_fin = new QLineEdit(widget);
        line_date_fin->setObjectName(QStringLiteral("line_date_fin"));
        line_date_fin->setGeometry(QRect(190, 210, 113, 22));
        line_date_debut = new QLineEdit(widget);
        line_date_debut->setObjectName(QStringLiteral("line_date_debut"));
        line_date_debut->setGeometry(QRect(190, 160, 113, 22));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 310, 81, 20));
        comboBox_type_conge = new QComboBox(widget);
        comboBox_type_conge->setObjectName(QStringLiteral("comboBox_type_conge"));
        comboBox_type_conge->setGeometry(QRect(180, 315, 131, 21));
        comboBox_id_em = new QComboBox(widget);
        comboBox_id_em->setObjectName(QStringLiteral("comboBox_id_em"));
        comboBox_id_em->setGeometry(QRect(190, 260, 121, 21));
        comboBox_id3 = new QComboBox(widget);
        comboBox_id3->setObjectName(QStringLiteral("comboBox_id3"));
        comboBox_id3->setGeometry(QRect(710, 480, 171, 31));
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

        tabWidget->setCurrentIndex(0);
        ajouter->setCurrentIndex(1);
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
        label_11->setText(QApplication::translate("MainWindow", "date d'embauche", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Identifiant :", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "la liste  des employ\303\251s :", Q_NULLPTR));
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
        //le_type_contract->setPlaceholderText(QString());
        stat->setText(QApplication::translate("MainWindow", "statistiques", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "statistiques de nombre d'employ\303\251s :", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        ajouter->setTabText(ajouter->indexOf(ajouterunemplyee), QApplication::translate("MainWindow", "traiter les profils des employ\303\251s", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "identifiant :", Q_NULLPTR));
        accepter->setText(QApplication::translate("MainWindow", "accepter", Q_NULLPTR));
        refuser->setText(QApplication::translate("MainWindow", "refuser", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        refuser->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        label_21->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "liste des demandes :", Q_NULLPTR));
        mise_a_jour->setText(QApplication::translate("MainWindow", "Mise \303\240 jour", Q_NULLPTR));
        ajouter->setTabText(ajouter->indexOf(tab_3), QApplication::translate("MainWindow", "traiter les cong\303\251s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "espace admin", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "DATE DEBUT:", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "DATE_FIN :", Q_NULLPTR));
        envoyer->setText(QApplication::translate("MainWindow", "envoyer", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "remplir le formulaire :", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "Afficher la liste de mes cong\303\251s :", Q_NULLPTR));
        recherche_demande->setText(QApplication::translate("MainWindow", "chercherr", Q_NULLPTR));
        label_31->setText(QString());
        supprimer_demande->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        modif_demande->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        combo_re->clear();
        combo_re->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_debut", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_fin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type_de_conge", Q_NULLPTR)
        );
        up->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        down->setText(QApplication::translate("MainWindow", "down", Q_NULLPTR));
        trier_les_demandes->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        combobox_tri2->clear();
        combobox_tri2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_debut", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_fin", Q_NULLPTR)
        );
        label_14->setText(QApplication::translate("MainWindow", "id_emoploy\303\251 ", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "type de cong\303\251", Q_NULLPTR));
        comboBox_type_conge->clear();
        comboBox_type_conge->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "maladie", Q_NULLPTR)
         << QApplication::translate("MainWindow", "vacances", Q_NULLPTR)
         << QApplication::translate("MainWindow", "raison personnel", Q_NULLPTR)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(widget), QApplication::translate("MainWindow", "envoyer une demande de cong\303\251", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "espace employ\303\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
