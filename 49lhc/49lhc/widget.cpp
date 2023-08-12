#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("49六合彩");
    CreateChartFunc();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::CreateChartFunc() {
    for (int i = 0; i < 49; i++) {
        barSet->append(data[i]);
    }

    // 创建柱状图系列
    barSeries->append(barSet);

    // 创建坐标轴
    QBarCategoryAxis* xAxis = new QBarCategoryAxis(); // 使用QBarCategoryAxis作为X轴
    QValueAxis* yAxis = new QValueAxis();
    yAxis->setRange(0, 100);

    // 创建图表并添加系列和坐标轴
    chart->addSeries(barSeries);
    chart->setTitle("Bar Chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置X轴的刻度标签
    QStringList categories;
    for (int i = 1; i <= 49; i++) {
        categories << QString::number(i);
    }
    xAxis->setCategories(categories);
    chart->createDefaultAxes(); // 此处可以省略
    chart->setAxisX(xAxis, barSeries);
    chart->setAxisY(yAxis, barSeries);

    // 显示每个柱的对应数值
    QBarSet *barSet = barSeries->barSets().at(0);
    for (int i = 0; i < 49; i++) {
        barSet->setLabel(QString::number(data[i]));
    }
    barSeries->hovered(1,1,barSeries->barSets().at(0));
    // 设置柱子颜色
        for (int i = 0; i < 49; i++) {
            if (i == 0 || i == 12 || i == 24 || i == 36 || i == 48)
                barSeries->barSets().at(0)->setColor(Qt::green);
        }

    // 创建图表视图并显示
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(chartView);
    QWidget* window = new QWidget();
    window->setLayout(layout);
    window->resize(1400, 900);
    window->show();
}

// 更新数据并刷新图表
void Widget::updateBarChart(int data[]) {
    QBarSet *newBarSet = new QBarSet("Data");
    int maxValue = 0; // Track the maximum value in the data array

    for (int i = 0; i < 49; i++) {
        *newBarSet << data[i];
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }

    barSeries->clear(); // Clear the previous series from the chart
    barSeries->append(newBarSet); // Set the new series with updated data

    QValueAxis* yAxis = qobject_cast<QValueAxis*>(chart->axisY()); // Get the existing Y-axis

    if (yAxis) {
        if (maxValue > yAxis->max()) {
            // If the maximum value in the data is greater than the current Y-axis maximum, update the Y-axis
            yAxis->setMax(maxValue);
        }
        else
            yAxis->setMax(yAxis->max());
    }


    chart->update(); // Update the chart to reflect the changes
}

void Widget::updateshow(int data[]){
    QString tableContent = "Index\tValue\n"; // Header row

    for (int i = 0; i < 49; i++) {
        QString row = QString("%1\t%2\n").arg(QString::number(i + 1), QString::number(data[i]));
        tableContent += row;
    }

    // Set the formatted table content to the QTextBrowser
    ui->show->setText(tableContent);
}


void Widget::on_puchase_clicked() {
    int code = ui->code->text().toInt();
    int money = ui->money->text().toInt();

    if (code < 1 || code > 49) {
        QMessageBox::warning(this, "错误", "请输入1到49之间的号码！");
        return;
    }

    data[code - 1] += money;

    calculateAndDisplayResults();
    QMessageBox::information(this, "提示框", "成功输入");
    updateBarChart(data);

    QString his = ui->code->text() + "号增加" + ui->money->text();
    ui->code->setText("0");
    ui->money->setText("0");
    history += "\n" + his;
    ui->his->setText(history);
    updateshow(data);


}

void Widget::on_rand_clicked()
{
    int a = ui->lineEdit_a->text().toInt();
    int b = ui->lineEdit_b->text().toInt();

        // 确保a和b在合理范围内，并且a<=b
        if (a < 0 || a > 1000000 || b < 0 || b > 1000000 || a > b) {
            QMessageBox::warning(this, "错误", "请输入合理的区间范围 (0到1000000)，且a应小于等于b！");
            return;
        }

        // 赋值数组data中a到b之间的元素为value
        for (int i = 0; i < 49; i++) {
                data[i] = QRandomGenerator::global()->bounded(a, b + 1); // Generate a random number in the range [a, b]
            }

        // 更新柱状图和展示区
        updateBarChart(data);
        updateshow(data);

        // 提示赋值成功
        QMessageBox::information(this, "提示", QString("已随机赋值"));
        calculateAndDisplayResults();
}

void Widget::calculateAndDisplayResults() {
    QString resultText = "<html><body><table>";
    resultText += "<tr><th> 号码</th><th>金额</th><th>奖金</th><th>收益</th><th>利润</th></tr>";

    int maxincomeline=0;
    int winner=0;
    int p=0;
    for (int i = 0; i < 49; i++) {
        int cost = 47 * data[i];

        int revenue = 0;
        for (int j = 0; j < 49; j++) {
            if (data[j] < data[i]) {
                revenue += data[j];
            } else if (data[j] >= data[i]) {
                revenue += data[i];
            }
        }

        int profit = revenue - cost;

        QString row;
        if (profit > 0) {
            row = QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td><font color=\"red\">%5</font></td></tr>")
                      .arg(i+1).arg(data[i]).arg(cost).arg(revenue).arg(profit);
        } else {
            row = QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td></tr>")
                      .arg(i+1).arg(data[i]).arg(cost).arg(revenue).arg(profit);
        }
        resultText += row;
        if(profit>p){
            winner=i;
            maxincomeline=data[i];
            p=profit;
        }
    }

    resultText += "</table></body></html>";
    ui-> income->setHtml(resultText);
    ui->killb->setText(QString::number(maxincomeline));
    ui->recommendnumber->setText(QString::number(winner+1));
    ui->redetail->setText("预计获利"+QString::number(p));
}

void Widget::on_killcomfirm_clicked()
{
    int cost=ui->killline->value();
    int temp[49];
    for (int i=0;i<49;i++) {
        if(data[i]>=cost)
            temp[i]=data[i];
        else
            temp[i]=0;

    }
    updateBarChart(temp);
    updateshow(temp);
}
