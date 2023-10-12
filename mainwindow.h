#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


// подключаем marble
//#include "../3rd_party/marble-product/include/marble/MarbleWidget.h"
#include "../../3rd_party/marble-product/include/marble/MarbleWidget.h"
#include "../../3rd_party/marble-product/include/marble/GeoPainter.h"
#include "../../3rd_party/marble-product/include/marble/MarbleMap.h"
#include "../../3rd_party/marble-product/include/marble/GeoDataLineString.h"
#include "../../3rd_party/marble-product/include/marble/LayerInterface.h"
#include "../../3rd_party/marble-product/include/marble/RouteRequest.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
