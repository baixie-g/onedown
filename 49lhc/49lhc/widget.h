#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtCharts>
#include<QtMath>
#include<complex>
#include<QMessageBox>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int data[49]={};

private slots:

    void on_puchase_clicked();

    void on_rand_clicked();

    void on_killcomfirm_clicked();

private:
    Ui::Widget *ui;


private:
    void CreateChartFunc();
    void updateBarChart(int data[]);
    void updateshow(int data[]);
    void calculateAndDisplayResults();
    QBarSeries* barSeries = new QBarSeries();
    QChart* chart = new QChart();
    QString history="";
    QBarSet* barSet = new QBarSet("Values");
};


#endif // WIDGET_H
