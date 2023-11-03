#include "connectDataBase.h"

#include "PZ_90_02.h"


connectDataBase::connectDataBase(const QString& dataBase)
{
    // Создание объекта базы данных
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Указание имени файла базы данных
    db.setDatabaseName(dataBase/*"mathDataBase.db"*/);

    // Открытие базы данных
    if (!db.open())
    {
        qDebug() << "Не удалось открыть базу данных";
//        return -1;
    }

    // Создание таблицы
    if (!query.exec("CREATE TABLE IF NOT EXISTS Geo (num INTEGER PRIMARY KEY, N DOUBLE PRECISION, M DOUBLE PRECISION, Cnm DOUBLE PRECISION, Dnm DOUBLE PRECISION)"))
    {
        qDebug() << "Не удалось создать таблицу";
//        return -1;
    }

//    QSqlQuery query;
//    query.prepare("INSERT INTO Geo (num, N, M, Cnm, Dnm) "
//                "VALUES (:num, :N, :Mm :Cnm, :Dnm)");
//    for (int i=0; i<2557; i++) {
//        query.bindValue(":num", 1);
//        query.bindValue(":N", GeoPotenzivalEarth_9002[(0) * 4 + 1]);
//        query.bindValue(":M", GeoPotenzivalEarth_9002[(0) * 4 + 2]);
//        query.bindValue(":Cnm", GeoPotenzivalEarth_9002[(0) * 4 + 3]);
//        query.bindValue(":Dnm", GeoPotenzivalEarth_9002[(0) * 4 + 4]);
//        query.exec();
//    }



    QSqlQuery query1;
    query1.exec("CREATE TABLE IF NOT EXISTS Geopot (num INTEGER PRIMARY KEY, n DOUBLE PRECISION, m DOUBLE PRECISION, Cnm DOUBLE PRECISION, Dnm DOUBLE PRECISION)");

    int rows = 2557; // количество строк в массиве
    int columns = 5; // количество столбцов в массиве
//    int array[rows][columns]; // инициализация и заполнение массива данными


    // цикл для записи данных из массива в таблицу
    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            array[i][j] = i+34;
            // формирование запроса на вставку данных в таблицу
            QString sql = "INSERT INTO Geopot (num, n, m, Cnm, Dnm) VALUES (:num, :n, :m, :Cnm, :Dnm)";
            query1.prepare(sql);
            query1.bindValue(":num", i+1);
            query1.bindValue(":n", GeoPotenzivalEarth_9002[(i) * 4 + 1]);
            query1.bindValue(":m", GeoPotenzivalEarth_9002[(i) * 4 + 2]);
            query1.bindValue(":Cnm", GeoPotenzivalEarth_9002[(i) * 4 + 3]);
            query1.bindValue(":Dnm", GeoPotenzivalEarth_9002[(i) * 4 + 4]);
            // выполнение запроса
            if (!query1.exec()) {
                qDebug() << "Error executing query: " << query.lastError();
            }
//        }
    }



//    for (int i=0; i<2557; i++)
//    {
//        array[i][0] = i+1;
//        array[i][1] = GeoPotenzivalEarth_9002[(0) * 4 + 1];
//        array[i][2] = GeoPotenzivalEarth_9002[(0) * 4 + 2];
//        array[i][3] = GeoPotenzivalEarth_9002[(0) * 4 + 3];
//        array[i][4] = GeoPotenzivalEarth_9002[(0) * 4 + 4];
//    }

//    // цикл для записи данных из массива в таблицу
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
////            array[i][j] = i+34;
//            // формирование запроса на вставку данных в таблицу
//            QString sql = "INSERT INTO Geopot (num, n, m, Cnm, Dnm) VALUES (:num, :n, :m, :Cnm, :Dnm)";
//            query1.prepare(sql);
//            query1.bindValue(":n", array[i][j]);
//            query1.bindValue(":m", array[i][j]);
//            query1.bindValue(":Cnm", array[i][j]);
//            query1.bindValue(":Dnm", array[i][j]);
//            // выполнение запроса
//            if (!query1.exec()) {
//                qDebug() << "Error executing query: " << query.lastError();
//            }
//        }
//    }



//    if (!query.exec("CREATE TABLE IF NOT EXISTS runge (num INTEGER PRIMARY KEY, X DOUBLE PRECISION, Y DOUBLE PRECISION, Z DOUBLE PRECISION, VX DOUBLE PRECISION, VY DOUBLE PRECISION, VZ DOUBLE PRECISION)"))
//    {
//        qDebug() << "Не удалось создать таблицу";
////        return -1;
//    }


    // Подготовка запроса на вставку
//    QSqlQuery insertQuery;
//    query.prepare("INSERT INTO  erty (num, N, M, Cnm, Dnm) VALUES (:num, :N, :M, :Cnm, :Dnm)");

////    for (int i = 0; i < GPZ_PZ90_02_SIZE + 1; ++i)
////    {
////        for (int j = 0; j < 4; ++j)
////        {
//            // Привязка значений к подготовленному запросу
//            query.bindValue(":num", 1);
//            query.bindValue(":N", GeoPotenzivalEarth_9002[(0) * 4 + 1]);
//            query.bindValue(":M", GeoPotenzivalEarth_9002[(0) * 4 + 2]);
//            query.bindValue(":Cnm", GeoPotenzivalEarth_9002[(0) * 4 + 3]);
//            query.bindValue(":Dnm", GeoPotenzivalEarth_9002[(0) * 4 + 4]);
////        }

//        // Выполнение запроса
//        if (!query.exec())
//        {
//            qDebug() << "Ошибка при выполнении запроса на вставку данных";
//            return;
//        }
////    }


//    // Добавление записи в таблицу
//    if (!query.exec("INSERT INTO Gepotenzival (num, N, M, Cnm, Dnm) VALUES (? , ?, ?, ?, ?)"))
//    {
//        qDebug() << "Не удалось добавить запись в таблицу";
//    }

//    for(int i = 0; i < GPZ_PZ90_02_SIZE + 1; i++)
//    {
//        query.addBindValue(i+1);
//        query.addBindValue(GeoPotenzivalEarth_9002[(i) * 4]);
//        query.addBindValue(GeoPotenzivalEarth_9002[(i) * 4 + 1]);
//        query.addBindValue(GeoPotenzivalEarth_9002[(i) * 4 + 2]);
//        query.addBindValue(GeoPotenzivalEarth_9002[(i) * 4 + 3]);
//        query.addBindValue(GeoPotenzivalEarth_9002[(i) * 4 + 4]);
//    }


    // Выборка данных из таблицы
    if (!query.exec("SELECT * FROM Geo"))
    {
        qDebug() << "Не удалось выбрать данные из таблицы";
//        return -1;
    }





//    // Обработка результатов выборки
//    while (query.next())
//    {
//        int id = query.value(0).toInt();
//        QString name = query.value(1).toString();
//        int age = query.value(2).toInt();

//        qDebug() << "ID:" << id << "Имя:" << name << "Возраст:" << age;
//    }

    // Закрытие базы данных
    db.close();
}
