#include "statistiques.h"
#include "ui_statistiques.h"

#include "admin.h"
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

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
      ui->setupUi(this);
      QBarSet *set0 = new QBarSet("Orange");
      QBarSet *set1 = new QBarSet("Ooredoo");
      QBarSet *set2 = new QBarSet("Telecom");

      *set0 <<  E.calculer("Orange")<< 0 << 0;
      *set1 << 0 << E.calculer("Ooredoo") << 0;
      *set2 << 0 << 0 << E.calculer("Telecom");

      QBarSeries *series = new QBarSeries();
      series->append(set0);
      series->append(set1);
      series->append(set2);

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Simple barchart example");
      chart->setAnimationOptions(QChart::SeriesAnimations);

      QStringList categories;
      categories << "Orange"
                 << "Ooredoo"
                 << "Telecom";

      QBarCategoryAxis *axis = new QBarCategoryAxis();
      axis->append(categories);
      chart->createDefaultAxes();
      chart->setAxisX(axis, series);

      chart->legend()->setVisible(true);
      chart->legend()->setAlignment(Qt::AlignBottom);

      QChartView *chartview = new QChartView(chart);
      chartview->setRenderHint(QPainter::Antialiasing);
      QGridLayout *mainLayout = new QGridLayout;
      mainLayout->addWidget(chartview, 1, 1);
      setLayout(mainLayout);
}

statistiques::~statistiques()
{
    delete ui;
}
