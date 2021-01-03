#ifndef STAT_H
#define STAT_H

#include "client.h"
#include <QDialog>
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
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Stat;
}

class Stat : public QDialog {
  Q_OBJECT

public:
  explicit Stat(QWidget *parent = nullptr);
  ~Stat();

private:
  Ui::Stat *ui;
  stat s;
  client client;
};

#endif // STAT_H
