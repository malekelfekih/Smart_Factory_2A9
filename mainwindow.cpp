#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextLength>
#include "demande.h"
#include <QColor>
#include<QModelIndex>
#include <QSqlQueryModel>
#include <QString>
#include <QStaticStringData>
#include "statistiques.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QPixmap pix(":/new/prefix2/Nouveau dossier/backgr.jpg");
    ui->le_id->setValidator(new QIntValidator(10,999999,this));
     ui->le_cin->setValidator(new QIntValidator(10000000,99999999,this));
     ui->le_tel->setValidator(new QIntValidator(10,99999999,this));
     ui->le_salaire->setValidator(new QIntValidator(10,99999,this));
     ui->line_id->setValidator(new QIntValidator(10,999999,this));

     ui->comboBox_id2->setModel(E.afficher1());
     ui->comboBox_id_em->setModel(d.afficher2());
     ui->comboBox_id3->setModel(d.afficher3());
     ui->comboBox_id4->setModel(d.afficher4());



     ui->table_employee_2->setModel(E.afficher());
     ui->liste_demande->setModel(d.afficher_demande());



     ui->table_conges->setModel(d.afficher_demande());

    // ui->le_type_contract->lineEdit()->setPlaceholderText("RGB");



}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouter_2_clicked()
{


   // QString id_string = QString :: number(id);

    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();

    QString adresse=ui->le_adresse->text();
    QString type_de_contarct=ui->le_type_contract->currentText();
    QString operateur;
      int id=ui->le_id->text().toInt();
 //   int id_string=ui->comboBox_id1->currentText();
    int cin=ui->le_cin->text().toInt();
    int num_telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString date_naissance=ui->line_naisance->text();
    QString date_embauche=ui->line_embauche->text();
    QString cin_string = QString :: number(cin);
    QString num_telephone_string = QString :: number(num_telephone);
   QString id_string = QString :: number(id);


    if (num_telephone_string[0] == "9")
        operateur = "Telecom";
      if (num_telephone_string[0] == "2")
        operateur = "Ooredoo";
      if (num_telephone_string[0] == "5")
        operateur = "Orange";

     //this->E.getDate_naissance().toString("yyyy.MM.dd");

  /* QString date_naissance_a= date_naissance.toString("dd/MM/yyyy");
    QString date_embauche_b= date_embauche.toString("dd/MM/yyyy");*/
   bool test2=false;
   for(int i=0 ; i<email.length();i++)
   {
       if(email[i]=="@")
           test2=true;

   }
   if(test2==false)
   {
       QMessageBox::information(nullptr, QObject::tr("ajout"),
                   QObject::tr("mail non valider.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       return;
   }



  bool test3=false;
  for(int i=0 ; i<cin_string.length();i++)
  {
     if(cin_string.length()==8 )
     {
        test3=true;
     }
     if(test3==false)
     {
         QMessageBox::information(nullptr, QObject::tr("ajout"),
                     QObject::tr("cin  non valider.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         return;
     }
  }



     bool test4=false;
     for(int i=0 ; i<num_telephone_string.length();i++)
     {
        if(num_telephone_string.length()==8 )
        {
           test4=true;
        }
        if(test4==false)
        {
            QMessageBox::information(nullptr, QObject::tr("ajout"),
                        QObject::tr("numéro de téléphone  non valider.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            return;
        }
     }




        bool test5=false;
        for(int i=0 ; i<id_string.length();i++)
        {
           if(id_string.length()==6 || id_string=="" )
           {
              test5=true;
           }
           if(test5==false)
           {
               QMessageBox::information(nullptr, QObject::tr("ajout"),
                           QObject::tr("identifiant  non valider.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               return;
           }
      }
      bool test6=false;
        for(int i=0 ; i<date_naissance.length();i++)
        {
           if(date_naissance[i] =="  /  /    ")
           {
              test6=true;
           }
           if(test6==false)
           {
               QMessageBox::information(nullptr, QObject::tr("ajout"),
                           QObject::tr("date de naissnace  non valider.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               return;
           }
      }

 EMPLOYEE E (nom, prenom , email ,  adresse, type_de_contarct, operateur, date_naissance, date_embauche ,id ,cin ,num_telephone, salaire  );

bool test=E.ajouter();
if(test)


{

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("add successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->table_employee_2->setModel(E.afficher());
     ui->comboBox_id2->setModel(E.afficher1());
     ui->comboBox_id_em->setModel(d.afficher2());

}
else

    QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("add failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}







/*void MainWindow::on_modifier_clicked()
{


    EMPLOYEE *E=new EMPLOYEE();

    E->setNom(ui->le_nom->text());
    E->setPrenom(ui->le_prenom->text());

    E->setAdresse(ui->le_adresse->text());
    E->setEmail(ui->le_email->text());
    E->setType_de_contract(ui->le_type_contract->currentText());


    E->setID(ui->le_id->text().toInt());
    E->setCIN(ui->le_cin->text().toInt());
    E->setNum_telephone(ui->le_tel->text().toInt());
    E->setSalaire(ui->le_salaire->text().toInt());


    E->setDate_naissance(ui->le_naissance->date());
    E->setDate_naissance(ui->le_embauche->date());


   EMPLOYEE E1 ; E1.setID(ui->le_identifiant_2->text().toInt());
     bool test=E1.modifier(E1.getID());
     QMessageBox msgBox;
     if(test)*/





  /*  bool test=E->modifier();

    QMessageBox msgBox;
    if(test)

    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("edit successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_employee_2->setModel(E->afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("edit failed.\n"

                                "Click Cancel to exit."), QMessageBox::Cancel);

}*/





void MainWindow::on_supprimer_2_clicked()
{
    EMPLOYEE E1 ; //E1.setID(ui->le_identifiant_2->text().toInt());
    E1.setID(ui->comboBox_id2->currentText().toInt());
    bool test=E1.supprimer(E1.getID());
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_employee_2->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}



void MainWindow::on_chercher_clicked()
{
    int choix;
    choix=ui->comboBox_rech->currentIndex();
     QString rech=ui->line_recherche->text();
    ui->table_employee_2->setModel(E.recherche(choix,rech));




}




void MainWindow::on_trier_clicked()
{
    int choix ;
    choix=ui->comboBox_rech_2->currentIndex();
    QSqlQueryModel * model =new QSqlQueryModel();

//ui->table_employee_2->sortByColumn(0,Qt::AscendingOrder);
//ui->table_employee_2->setModel(E.afficher());

  if(ui->radioButton_up->isChecked())
  model = E.trierup(choix);
  //ui->table_employee_2->setModel(E.afficher());

 else if(ui->radioButton_down->isChecked())
    model=E.trier_down(choix);
   // ui->table_employee_2->setModel(E.afficher());
  else
      model=E.afficher();

   ui->table_employee_2->setModel(model);


}



void MainWindow::on_envoyer_clicked()

{

QString identifiant=ui->line_id->text();
QString date_debut=ui->line_date_debut->text();
QString date_fin=ui->line_date_fin->text();
QString type_de_conge=ui->comboBox_type_conge->currentText();
QString etats;
int id=ui->comboBox_id_em->currentText().toInt();
demande d ( identifiant , date_debut , date_fin  ,etats, id,type_de_conge  );

QMessageBox msgBox;
 bool test=d. ajouter_demande();
 if (test)
 {     msgBox.setText("Envoie avec succes");
     ui->table_conges->setModel(d.afficher_demande());
      ui->comboBox_id3->setModel(d.afficher3());
        ui->comboBox_id4->setModel(d.afficher4());
     // ui->comboBox_id_em->setModel(d.afficher2());


 }
 else
     msgBox.setText("erreur d'envoie");
 msgBox.exec();

}

/*bool test1=false;
for(int i=0 ; i<date_debut.length();i++)
{
    if(date_debut[i]=="/ / / ")
        test1=true;

}
if(test1==false)
{
    QMessageBox::information(nullptr, QObject::tr("ajout"),
                QObject::tr("date_debut non valider.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}*/


 /*demande d ( identifiant , date_debut ,date_fin ,type_de_conge );


bool test=d.ajouter_demande();
if(test  )

{

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("add successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->table_conges->setModel(d.afficher_demande());

//if(identifiant.length()!=8)
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("add failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);





}*/















void MainWindow::on_mise_a_jour_clicked()
{


       //demande d1 ; d1.setIdentifiant(ui->le_identifiant_2->text().toInt());
     bool test=d.afficher_demande();
     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("la demande a été mise à jours .\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

           ui->liste_demande->setModel(d.afficher_demande());
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                     QObject::tr("la demande n'est pas mise à jours .\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);



}

/*void MainWindow::on_mise_a_jours_clicked()
{
    ui->liste_demande->setModel(d.afficher_demande());


    bool test=d.afficher_demande();
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("votre demande est accepter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_employee_2->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("votre demande n'est pas mise à jours .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
*/


void MainWindow::on_accepter_clicked()
{

   demande d1 ;
  // ui->comboBox_id4->setModel(d.afficher4());

    d1.setEtats(ui->comboBox_id4->currentText());
    bool test=d1.accepter(d1.getIdentifiant());

     QMessageBox msgBox ;


     if (test)
     {

       msgBox.setText(("modification avec succes"));

        ui->liste_demande->setModel(d.afficher_demande());
     }
     else

         msgBox.setText("non");
        msgBox.exec();

/*
if(test)
{

QString e ;

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("la demande est accepter.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     //ui->table_employee_2->setModel(E.afficher());
//e = d.getEtats();
//e = "Accepté";
//d.setEtats(e);

         //  d.getEtats() = d.etats_string(e);
            ui->liste_demande->setModel(d.afficher_demande());
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("erreur .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);*/



  }


void MainWindow::on_refuser_clicked()
{
    ui->liste_demande->setModel(d.afficher_demande());
    QMessageBox::information(nullptr, QObject::tr(" not ok"),
                QObject::tr("la demande est refuser.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->liste_demande->setModel(d.afficher_demande());

}





void MainWindow::on_supprimer_demande_clicked()
{
    demande d1 ;
    d1.setIdentifiant(ui->comboBox_id3->currentText());
    bool test=d1.supprimer_demande(d1.getIdentifiant());
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_conges->setModel(d.afficher_demande());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


/*
    EMPLOYEE E1 ; //E1.setID(ui->le_identifiant_2->text().toInt());
    E1.setID(ui->comboBox_sup_dem->currentText().toInt());
    bool test=E1.supprimer(E1.getID());
    QMessageBox msgBox;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->table_employee_2->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


*/



void MainWindow::on_recherche_demande_clicked()
{
    int choice;
    choice=ui->combo_re->currentIndex();

    QString re=ui->lineEdit_4->text();
   ui->table_conges->setModel(d.chercher_demande(choice,re));


}

void MainWindow::on_trier_les_demandes_clicked()
{
    int choix ;
    choix=ui->combobox_tri2->currentIndex();
    QSqlQueryModel * model =new QSqlQueryModel();

//ui->table_employee_2->sortByColumn(0,Qt::AscendingOrder);
//ui->table_employee_2->setModel(E.afficher());

  if(ui->up->isChecked())
  model = d.trier_up_demande(choix);
  //ui->table_employee_2->setModel(E.afficher());

 else if(ui->down->isChecked())
    model=d.trier_down_demande(choix);
   // ui->table_employee_2->setModel(E.afficher());
  else
      model=d.afficher_demande();

   ui->table_conges->setModel(model);

}


/*void MainWindow::on_stat_clicked()
{
    QSqlQuery query ;
    QSqlQueryModel * model =new QSqlQueryModel();
    stats s;
    model =s.returnNumber();
    ui->table_employee_2->setModel(model);
    QString nbr_employe=
    QString :: number(ui->table_employee_2->model()->index(0,0).data().toInt());
    model =E.afficher();
    ui->table_employee_2->setModel(model);
    QMessageBox msgbox;
    msgbox.setText("le nombre actuel des employes est " +nbr_employe +
                   "employes in the systm .");
    msgbox.exec();

}*/






void MainWindow::on_modifier_clicked()
{
   // click->play();

    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();

    QString adresse=ui->le_adresse->text();
    QString type_de_contarct=ui->le_type_contract->currentText();
    QString operateur;
      int id=ui->le_id->text().toInt();
 //   int id_string=ui->comboBox_id1->currentText();
    int cin=ui->le_cin->text().toInt();
    int num_telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString date_naissance=ui->line_naisance->text();
    QString date_embauche=ui->line_embauche->text();
    QString cin_string = QString :: number(cin);
    QString num_telephone_string = QString :: number(num_telephone);
   QString id_string = QString :: number(id);

  //EMPLOYEE E(QString nom, QString prenom ,QString email , QString adresse ,QString type_de_contract,QString operateur, QString date_naissance , QString date_embauche, int  id , int cin , int  num_telephone ,int salaire);


QMessageBox msgBox;



      bool test=E.modifier(nom, prenom , email ,  adresse, type_de_contarct , date_naissance ,date_embauche ,id ,cin ,num_telephone, salaire );

      if(test)
    {

        msgBox.setText("Modification avec succes !");
        ui->table_employee_2->setModel(E.afficher());


      }
      else
      {
          msgBox.setText("Modification échouée !");
  msgBox.exec();
      }
}


void MainWindow::on_modif_demande_clicked()
{
    QString identifiant=ui->line_id->text();
    QString date_debut=ui->line_date_debut->text();
     QString date_fin=ui->line_date_fin->text();
     QString type_de_conge=ui->comboBox_type_conge->currentText();

    // int id=ui->comboBox_id_em->currentText().toInt();


QMessageBox msgBox;



      bool test=d.modifier_demande(identifiant, date_debut , date_fin ,  type_de_conge );

      if(test)
    {

        msgBox.setText("Modification avec succes !");
         ui->table_conges->setModel(d.afficher_demande());
        // ui->comboBox_type_conge->setModel(d.afficher_demande());


      }
      else
      {
          msgBox.setText("Modification échouée !");
  msgBox.exec();
      }




}



void MainWindow::on_stat_clicked()
{
    int res;
    statistiques w(this);
    w.setWindowTitle("Statistiques des operateurs");

    res = w.exec();
    qDebug() << res;
    if (res == QDialog::Rejected)
      return;
}
