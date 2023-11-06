#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "inc/stateVectorModel.h"
#include "inc/mathModelSpacecraft.h"
#include "inc/MapMarbleTrassa.h"
#include "inc/stateVectorDelegate.h"
#include <QStandardItemModel>
#include "inc/MapSettings.h"
#include "inc/settingsTreeView.h"
#include "inc/settingsTreeItem.h"
#include "inc/connectDataBase.h"
#include <QSqlError>
#include <QThread>


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

    ui->pBback->setIcon(QIcon("://left-arrow.png"));
    ui->pBNext->setIcon(QIcon("://right-arrow.png"));

    // убирвем стирекы таба
     ui->tabWidget->tabBar()->hide();

    // Заполнение таблицы
    vector</*coordVectorXYZ<*/double/*>*/> coord;
    coord = MapMarbleTrassa::buildingRouteKAXYZ1();

    // нахрена вот это надо уже не помню....
    QList<stateVectorShell> * values = new QList<stateVectorShell>;
    for(int i = 1; i < coord.size(); i++)
    {
        values->append(stateVectorShell(QDateTime(), coord[(i-1) * 6], coord[(i-1) * 6 +1], coord[(i-1) * 6 +2],
                coord[(i-1) * 6 + 3], coord[(i-1) * 6 + 4], coord[(i-1) * 6 + 5]));
    }

    stateVectorModel *statVec = new stateVectorModel(/*mq,*/ this);
    statVec->populate(values);
    ui->tableView->setModel(statVec);

    mathModelSpacecraft * mathMod  = new mathModelSpacecraft(/*this*/);
    ui->tableView_2->setModel(mathMod);
    ui->tableView_2->setItemDelegate(new stateVectorDelegate());

    // настройки через делегат от treeview
    QTreeView treeView;
    QStandardItemModel modelStdItem;

    // Создание заголовков колонок
    modelStdItem.setHorizontalHeaderLabels({"MDKA", "MDKA Value"});

    // Создание данных настроек
    QList<QStandardItem*> setting1;
    QStandardItem* keyItem1 = new QStandardItem("MDKA1");
    QStandardItem* valueItem1 = new QStandardItem("MDKA Value1");
    setting1 << keyItem1 << valueItem1;
    modelStdItem.appendRow(setting1);

    QList<QStandardItem*> setting2;
    QStandardItem* keyItem2 = new QStandardItem("MDKA2");
    QStandardItem* valueItem2 = new QStandardItem("MDKA Value2");
    setting2 << keyItem2 << valueItem2;
    modelStdItem.appendRow(setting2);

    // Установка модели данных для QTreeView
    treeView.setModel(&modelStdItem);

    // Установка делегата для второй колонки
    SettingsDelegate* delegate1 = new SettingsDelegate;
    treeView.setItemDelegateForColumn(1, delegate1);

    treeView.show();
    ui->horizontalLayout_5->addWidget(&treeView);

    // добавляем записи в базу данных
    connectDataBase *db = new connectDataBase("mathDataBase.db");

    // Добавляем таблицу базы данных на на форму
    QSqlTableModel *model = new QSqlTableModel(this, QSqlDatabase::database());
    QString tableName = "Geopot";//"mytable"/*Geo*/;
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableViewGeo->setModel(model);
    ui->labelGeo->setText(tableName);

    // делегат для изменения значения в таблице базы данных
    DatabaseDelegate* delegate = new DatabaseDelegate;
    ui->tableViewGeo->setItemDelegateForColumn(5, delegate);

    // раздаем классам потоки
    QThread tread1;
    QThread tread2;

    db->moveToThread(&tread1);

//    connect(&tread1, &QThread::started, &db, &connectDataBase::run);
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

void MainWindow::on_pBsettingMap_clicked()
{
    MapSettings * mapSet = new MapSettings();
    mapSet->show();
}

void MainWindow::on_pushButtonBD_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_pBback_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(ui->stackedWidget_2->currentIndex() - 1);
}

void MainWindow::on_pBNext_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(ui->stackedWidget_2->currentIndex() + 1);
}

