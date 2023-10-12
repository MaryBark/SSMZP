#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "stateVectorModel.h"
#include "mathModelSpacecraft.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Подключаем картографию
    Marble::MarbleWidget *mapWidget = new Marble::MarbleWidget;
    mapWidget->setProjection(Marble::Mercator);
    mapWidget->setMapThemeId("earth/bluemarble/bluemarble.dgml");
    QHBoxLayout * layot = new QHBoxLayout();
    layot->addWidget(mapWidget);
    ui->lwidget->setLayout(layot);

    // убирвем стирекы таба
     ui->tabWidget->tabBar()->hide();


     // Собственные модели
//     QList <double> mq {10.0 , 10.0 , 10.0 , 10.0 , 10.0 ,10.0};


     QByteArray mq = QString("123456789345345").toUtf8();

    stateVectorModel *statVec = new stateVectorModel(mq, this);
    ui->tableView->setModel(statVec);

    mathModelSpacecraft * mathMod  = new mathModelSpacecraft(/*this*/);
    ui->treeView->setModel(mathMod);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentIndex(4);
}

