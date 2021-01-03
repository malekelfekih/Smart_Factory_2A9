#include "employee.h"




EMPLOYEE::EMPLOYEE (QString nom, QString prenom ,QString email , QString adresse ,QString type_de_contract,QString operateur, QString date_naissance , QString date_embauche, int  id , int cin , int  num_telephone , int salaire )
{
    this->nom=nom;
    this->prenom=prenom;

    this->email=email;
    this->adresse=adresse;
    this->type_de_contract=type_de_contract;
    this->operateur=operateur;
    this->date_naissance=date_naissance;
    this->date_embauche=date_embauche;

    this->id=id;
    this->cin=cin;
    this->num_telephone=num_telephone;
    this->salaire=salaire;

}



bool EMPLOYEE ::  ajouter()
{

    QSqlQuery query;

    QString id_string = QString :: number(id);


    QString salaire_string= QString :: number(salaire);

   //prepare() prend la requete en parametre pour la préparer à l'exécution
    query.prepare("insert into EMPLOYEE(nom , prenom , email , adresse ,id ,cin, num_telephone , salaire , date_naissance , date_embauche , type_de_contract ,operateur) values(:nom,:prenom, :email , :adresse , :id , :cin ,:num_telephone ,:salaire ,:date_naissance ,:date_embauche,:type_de_contract,:operateur)");

    //creation des variables liées

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    query.bindValue(":email",email);

    query.bindValue(":adresse",adresse);
    query.bindValue(":type_de_contract",type_de_contract);

   query.bindValue(":id",id);
    query.bindValue(":cin",cin);
   query.bindValue(":num_telephone",num_telephone);
    query.bindValue(":salaire",salaire);

    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":date_embauche",date_embauche);
    query.bindValue(":type_de_contract",type_de_contract);
    query.bindValue(":operateur",operateur);
  /*  QString date_naissance = "20/12/2015";
    QDate Date;
    Date= QDate::fromString(date_naissance,"dd/MM/yyyy");*/


    return query.exec(); //exec () envoie la requete pour l'exécuter


}

bool EMPLOYEE :: supprimer(int id )
{
    QSqlQuery query ;
    QString id_string = QString :: number(id);
    query.prepare("Delete from EMPLOYEE where id =:id_string");
    query.bindValue(0,id);
    return query.exec();

}












QSqlQueryModel * EMPLOYEE :: afficher()
{
QSqlQueryModel * model =new QSqlQueryModel();

model->setQuery("SELECT * FROM EMPLOYEE");



return model ;
}


/*bool EMPLOYEE ::modifier()
{
   QSqlQuery  query ;
   QString id_string = QString :: number(id);
   query.prepare("UPDATE EMPLOYEE set  nom=:nom , prenom=:prenom , email=:email , adresse=:adresse , id=:id, cin=:cin, num_telephone=:num_telephone  , salaire=:salaire , date_naissance=:date_naissance ,  date_embauche=:date_embauche ,type_de_contract=:type_de_contract ");

   query.bindValue(0,nom);
   query.bindValue(1,prenom);

   query.bindValue(2,email);

    query.bindValue(3,adresse);

    query.bindValue(4,id);
    query.bindValue(5,cin);
    query.bindValue(6,num_telephone);
    query.bindValue(7,salaire);

   query.bindValue(8,date_naissance);
   query.bindValue(9,date_embauche);
   query.bindValue(10,type_de_contract);





   return query.exec(); //exec () envoie la requete pour l'exécuter



}*/
bool EMPLOYEE::modifier(QString nom, QString prenom ,QString email , QString adresse ,QString type_de_contract,QString date_naissance ,QString date_embauche, int  id , int cin , int  num_telephone , int salaire )
{


QSqlQuery query;


if (nom != "") {
   query.prepare("UPDATE EMPLOYEE SET nom = :nom WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":nom", nom);
   if(!query.exec())
      {
       return false;
   }
}
if (prenom != "") {
   query.prepare("UPDATE EMPLOYEE SET prenom = :prenom WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":prenom", prenom);
   if(!query.exec())
      {
       return false;
   }
}
if (email != "") {
   query.prepare("UPDATE EMPLOYEE SET email = :email WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":email", email);
   if(!query.exec())
      {
       return false;
   }
}
if (adresse != "") {
   query.prepare("UPDATE EMPLOYEE SET adresse = :adresse WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":adresse", adresse);
   if(!query.exec())
      {
       return false;
   }
}
if (type_de_contract !="") {
   query.prepare("UPDATE EMPLOYEE SET type_de_contract = :type_de_contract WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":type_de_contract", type_de_contract);
   if(!query.exec())
      {
       return false;
      }

      }
if (date_naissance !="" ) {
   query.prepare("UPDATE EMPLOYEE SET date_naissance = :date_naissance WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":date_naissance", date_naissance);
   if(!query.exec())
      {
       return false;
   }
}
if (date_embauche !="" ) {
   query.prepare("UPDATE EMPLOYEE SET date_embauche = :date_embauche WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":date_embauche", date_embauche);
   if(!query.exec())
      {
       return false;
   }
}

if (cin != 0) {
   query.prepare("UPDATE EMPLOYEE SET cin = :cin WHERE id = :id ");
   query.bindValue(":id", id);
   query.bindValue(":cin", cin);
   if(!query.exec())
      {
       return false;
   }
}
   if (salaire != 0) {
       query.prepare("UPDATE EMPLOYEE SET salaire = :salaire WHERE id = :id ");
       query.bindValue(":id", id);
       query.bindValue(":salaire", salaire);
       if(!query.exec())
          {
           return false;
       }
   }
       if (num_telephone != 0) {
           query.prepare("UPDATE EMPLOYEE SET num_telephone = :num_telephone WHERE id = :id ");
           query.bindValue(":id", id);
           query.bindValue(":num_telephone", num_telephone);
           if(!query.exec())
              {
               return false;
           }
       }


          return true;
       }





QSqlQueryModel* EMPLOYEE::recherche(int test , QString text )
{


       QSqlQuery query ;

       QSqlQueryModel *model = new QSqlQueryModel();

       if(test==0)
       {
           query.prepare("SELECT * from employee where nom like '"+text+"'  ");
           query.exec();
           model->setQuery(query);
       }

           if(test==1)
           {
               query.prepare("SELECT * from employee where prenom like '"+text+"'  ");
               query.exec();
               model->setQuery(query);
           }
          if(test==2)
          {
              query.prepare("SELECT * from employee where email like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==3)
          {
              query.prepare("SELECT * FROM employee where adresse  like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==4)
          {
              query.prepare("SELECT * FROM employee where id   like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==5)
          {
              query.prepare("SELECT * FROM employee where cin  like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==6)
          {
              query.prepare("SELECT * FROM employee where num_telephone   like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==7)
          {
             query.prepare("SELECT * FROM employee where salaire like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==8)
          {
              query.prepare("SELECT * FROM employee where date_naissance like ='"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==9)
          {
              query.prepare("SELECT * FROM employee where date_embauche like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }
          if(test==9)
          {
              query.prepare("SELECT * FROM employee where type_de_contract like '"+text+"'  ");
              query.exec();
              model->setQuery(query);
          }







       return model;


}


/*QSqlQueryModel * EMPLOYEE :: trierup(int test)

{
   QSqlQuery query;
  // int test;
   //query.prepare("SELECT * FROM EMPLOYEE ORDER BY id  asc;");
  // query.prepare("SELECT * FROM EMPLOYEE ORDER BY date_embauche  asc;");

   query.prepare("SELECT *FROM EMPLOYEE ORDER BY id ASC;");

   query.exec();
   QSqlQueryModel * model =new QSqlQueryModel();

   model->setQuery(query);







return model ;
}*/



QSqlQueryModel *EMPLOYEE::trier_down(int test) {
 QSqlQuery query;
 QSqlQueryModel *model = new QSqlQueryModel();

 if (test == 0) {
   query.prepare(" SELECT * FROM EMPLOYEE ORDER BY id desc; ");
   query.exec();
   model->setQuery(query);
 }

 if (test == 1) {
   query.prepare(" SELECT * FROM EMPLOYEE ORDER BY date_embauche desc; ");
   query.exec();
   model->setQuery(query);
 }

 if (test == 2) {
   query.prepare(" SELECT * FROM EMPLOYEE ORDER BY salaire desc; ");
   query.exec();
   model->setQuery(query);
 }


 return model;
}


QSqlQueryModel *EMPLOYEE::trierup(int test)
{
 QSqlQuery query;
 QSqlQueryModel *model = new QSqlQueryModel();

 if (test == 0) {
   query.prepare(" SELECT * FROM EMPLOYEE ORDER BY id asc; ");
   query.exec();
   model->setQuery(query);
 }

 if (test == 1) {
   query.prepare(" SELECT * FROM EMPLOYEE ORDER BY date_embauche asc; ");
   query.exec();
   model->setQuery(query);
 }

 if (test == 2) {
   query.prepare(" SELECT * FROM EMPLOYEE ORDER BY salaire asc; ");
   query.exec();
   model->setQuery(query);
 }

 return model;
}


/*QSqlQueryModel *static ::returnNumber()
{
QSqlQuery query;
QSqlQueryModel *model =new QSqlQueryModel();
query.prepare("SELECT COUNT(*) FROM EMPLOYEE;");
query.exec();
model->setQuery(query);
return model;

return model;

}*/

int EMPLOYEE::calculer(QString operateur) {
 QSqlQuery query;
 query.prepare("select * from EMPLOYEE where operateur = :operateur");
 query.bindValue(":operateur", operateur);

 query.exec();
 int total = 0;
 while (query.next()) {
   total++;
 }

 return total;
}

QSqlQueryModel *EMPLOYEE::afficher1()
{
   QSqlQueryModel* model=new QSqlQueryModel();
       model->setQuery("SELECT id FROM EMPLOYEE");
       return model;
}

