#ifndef STACKEDWIDGETCHARTS_H
#define STACKEDWIDGETCHARTS_H

#include <QStackedWidget>

namespace Ui {
class StackedWidgetCharts;
}

class StackedWidgetCharts : public QStackedWidget
{
    Q_OBJECT

public:
    explicit StackedWidgetCharts(QWidget *parent = nullptr);
    ~StackedWidgetCharts();

private:
    Ui::StackedWidgetCharts *ui;
};

#endif // STACKEDWIDGETCHARTS_H
