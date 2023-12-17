#ifndef SWCHARTS_H
#define SWCHARTS_H

#include <QWidget>

namespace Ui {
class SWcharts;
}

class SWcharts : public QWidget
{
    Q_OBJECT

public:
    explicit SWcharts(QWidget *parent = nullptr);
    ~SWcharts();

private:
    Ui::SWcharts *ui;
};

#endif // SWCHARTS_H
