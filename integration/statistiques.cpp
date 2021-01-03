#include "statistiques.h"
#include "ui_statistiques.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>

Statistiques::Statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistiques)
{
    ui->setupUi(this);
 }

Statistiques::~Statistiques()
{
    delete ui;
}

int Statistiques::Stat_partie1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from MACHINE where NB_HEURE BETWEEN '10' AND '15'") ;
    while(requete.next())
    {
            count++ ;
    }

    return count ;
}

int Statistiques::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from MACHINE where NB_HEURE BETWEEN '15' AND '20'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int Statistiques::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from MACHINE where NB_HEURE BETWEEN '20' AND '25'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}



void Statistiques::paintEvent(QPaintEvent *)
{

    int b=Stat_partie1();
    //cout<<b<<endl ;
    int c=Stat_partie2();
   // cout<<c<<endl ;
    int d=Stat_partie3();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("10-15") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("15-20") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("20-25") ;

}
