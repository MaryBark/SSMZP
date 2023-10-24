#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "stateVectorModel.h"
#include "mathModelSpacecraft.h"
#include "MapMarbleTrassa.h"
#include "stateVectorDelegate.h"
#include <QStandardItemModel>
#include "MapSettings.h"

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


    connectDataBase *db = new connectDataBase("mathDataBase.db");



//    // Создание объекта базы данных
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

//    // Указание имени файла базы данных
//    db.setDatabaseName("example.db");

//    // Открытие базы данных
//    if (!db.open())
//    {
//        qDebug() << "Не удалось открыть базу данных";
////        return -1;
//    }

//    // Создание таблицы
//    QSqlQuery query;
//    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)"))
//    {
//        qDebug() << "Не удалось создать таблицу";
////        return -1;
//    }

//    // Добавление записи в таблицу
//    if (!query.exec("INSERT INTO users (name, age) VALUES ('John', 30)"))
//    {
//        qDebug() << "Не удалось добавить запись в таблицу";
////        return -1;
//    }

//    // Выборка данных из таблицы
//    if (!query.exec("SELECT * FROM users"))
//    {
//        qDebug() << "Не удалось выбрать данные из таблицы";
////        return -1;
//    }

//    // Обработка результатов выборки
//    while (query.next())
//    {
//        int id = query.value(0).toInt();
//        QString name = query.value(1).toString();
//        int age = query.value(2).toInt();

//        qDebug() << "ID:" << id << "Имя:" << name << "Возраст:" << age;
//    }

//    // Закрытие базы данных
//    db.close();


    QSqlTableModel *model = new QSqlTableModel;
        model->setTable("Gepotenzival");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
//        model->setHeaderData(0, Qt::Horizontal, tr("Name"));
//        model->setHeaderData(1, Qt::Horizontal, tr("Salary"));

        ui->tableView_3->setModel(model);
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

