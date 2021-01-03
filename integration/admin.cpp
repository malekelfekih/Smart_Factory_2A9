#include "admin.h"


Admin::Admin()
{

  username="";
  password="";
  role="";
}
Admin::Admin(QString username,QString password,QString role)
{

    this->username=username;
    this->password=password;
    this->role=role;
}
bool Admin::Login()
{
    QSqlQuery query;
       bool test=false;

           query.prepare("Select username,password,role FROM login where username=:username and password=:password");
            query.bindValue(":username",username);
             query.bindValue(":password",password);
             query.bindValue(":role",role);

             if(query.exec()&&query.next())
       {
                 test=true;
            return test;
       }
       return test;
}
QString Admin::afficherRole()
{
    QSqlQuery query;

           query.prepare("Select username,password,role FROM login where username=:username and password=:password");
            query.bindValue(":username",username);
             query.bindValue(":password",password);
             query.bindValue(":role",role);
            query.exec();
            query.next();
            QString a=query.value(2).toString();


return a;
}
