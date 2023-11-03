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

//    // Создание таблицы
//    if (!query.exec("CREATE TABLE IF NOT EXISTS Geo (num INTEGER PRIMARY KEY, N DOUBLE PRECISION, M DOUBLE PRECISION, Cnm DOUBLE PRECISION, Dnm DOUBLE PRECISION)"))
//    {
//        qDebug() << "Не удалось создать таблицу";
////        return -1;
//    }

    QSqlQuery query1;
    query1.exec("CREATE TABLE IF NOT EXISTS Geopot (num INTEGER PRIMARY KEY, n DOUBLE PRECISION, m DOUBLE PRECISION, Cnm DOUBLE PRECISION, Dnm DOUBLE PRECISION)");

    int rows = 2557; // количество строк в массиве
    // цикл для записи данных из массива в таблицу
    for (int i = 0; i < rows; i++) {

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
    }

    // Выборка данных из таблицы
    if (!query.exec("SELECT * FROM Geo"))
    {
        qDebug() << "Не удалось выбрать данные из таблицы";
//        return -1;
    }

    // Закрытие базы данных
    db.close();
}
