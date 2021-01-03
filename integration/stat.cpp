#include "stat.h"
#include "ui_stat.h"

#include "client.h"
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

Stat::Stat(QWidget *parent) : QDialog(parent), ui(new Ui::Stat) {
  ui->setupUi(this);

  QBarSet *set0 = new QBarSet("Orange");
  QBarSet *set1 = new QBarSet("Ooredoo");
  QBarSet *set2 = new QBarSet("Telecom");

  *set0 << client.calculer("Orange") << 0 << 0;
  *set1 << 0 << client.calculer("Telecom") << 0;
  *set2 << 0 << 0 << client.calculer("Ooredoo");

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
             << "Telecom"
             << "Ooredoo";

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

Stat::~Stat() { delete ui; }
