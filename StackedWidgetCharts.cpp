#include "StackedWidgetCharts.h"
#include "ui_StackedWidgetCharts.h"

StackedWidgetCharts::StackedWidgetCharts(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::StackedWidgetCharts)
{
    ui->setupUi(this);
}

StackedWidgetCharts::~StackedWidgetCharts()
{
    delete ui;
}
