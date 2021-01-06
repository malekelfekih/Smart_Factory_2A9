#ifndef STATF_H
#define STATF_H

#include "admin.h"
#include "mainwindow.h"
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
class statf;
}

class statf : public QDialog
{
    Q_OBJECT

public:
    explicit statf(QWidget *parent = nullptr);
    ~statf();

private:
    Ui::statf *ui;
    EMPLOYEE E;
    client client;
};



#endif // STATF_H
