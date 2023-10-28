#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "stateVectorModel.h"
#include "mathModelSpacecraft.h"
#include "MapMarbleTrassa.h"
#include "stateVectorDelegate.h"
#include <QStandardItemModel>
#include "MapSettings.h"
#include "settingsTreeView.h"
#include "settingsTreeItem.h"
#include "connectDataBase.h"


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

    ui->pBback->setIcon(QIcon("left-arrow.png"));
    ui->pBNext->setIcon(QIcon("right-arrow.png"));

    // убирвем стирекы таба
     ui->tabWidget->tabBar()->hide();

    // Заполнение таблицы
    vector</*coordVectorXYZ<*/double/*>*/> coord;
    coord = MapMarbleTrassa::buildingRouteKAXYZ1();

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
    // Установка модели данных для QTreeView
    treeView.setModel(&modelStdItem);

    // Установка делегата для второй колонки
    SettingsDelegate* delegate1 = new SettingsDelegate;
    treeView.setItemDelegateForColumn(1, delegate1);

    treeView.show();
    ui->horizontalLayout_5->addWidget(&treeView);




    connectDataBase *db = new connectDataBase("mathDataBase.db");

    QSqlTableModel *model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable("erty");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //        model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    //        model->setHeaderData(1, Qt::Horizontal, tr("Salary"));
    ui->tableView_3->setModel(model);


    DatabaseDelegate* delegate = new DatabaseDelegate;
    ui->tableView_3->setItemDelegateForColumn(5, delegate);
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

