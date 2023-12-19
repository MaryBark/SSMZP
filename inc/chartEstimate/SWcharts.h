#ifndef SWCHARTS_H
#define SWCHARTS_H

#include <QWidget>
#include <QVector>
#include <QString>

struct dataCharts
{
    dataCharts( QVector <double> dataX1,
    QVector <double> dataY1):s_dataX1(dataX1),
    s_dataY1(dataY1)
    {}

    QVector <double> s_dataX1;
    QVector <double> s_dataY1;
    QVector < QVector <double> > s_dataX2;
    int s_poins = s_dataX1.count();
    QString s_axisXname;
    QString s_axisYname;
};


namespace Ui {
class SWcharts;
}

class SWcharts : public QWidget
{
    Q_OBJECT

public:
    explicit SWcharts(dataCharts& dc, QWidget *parent = nullptr);
    ~SWcharts();

private:
    Ui::SWcharts *ui;

    dataCharts& m_dc;
};

#endif // SWCHARTS_H


