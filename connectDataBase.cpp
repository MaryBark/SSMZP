#include "connectDataBase.h"

#include "PZ_90_02.h"


connectDataBase::connectDataBase(const QString& dataBase)
{
    // Создание объекта базы данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // Указание имени файла базы данных
    db.setDatabaseName(dataBase/*"mathDataBase.db"*/);

    // Открытие базы данных
    if (!db.open())
    {
        qDebug() << "Не удалось открыть базу данных";
//        return -1;
    }

    // Создание таблицы
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS Gepotenzival (num INTEGER PRIMARY KEY, N DOUBLE PRECISION, M DOUBLE PRECISION, Cnm DOUBLE PRECISION, Dnm DOUBLE PRECISION)"))
    {
        qDebug() << "Не удалось создать таблицу";
//        return -1;
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS runge (num INTEGER PRIMARY KEY, X DOUBLE PRECISION, Y DOUBLE PRECISION, Z DOUBLE PRECISION, VX DOUBLE PRECISION, VY DOUBLE PRECISION, VZ DOUBLE PRECISION)"))
    {
        qDebug() << "Не удалось создать таблицу";
//        return -1;
    }


    // Добавление записи в таблицу
    if (!query.exec("INSERT INTO Gepotenzival (num, N, M, Cnm, Dnm) VALUES (1 , 1, 1, 56, 76)"))
    {
        qDebug() << "Не удалось добавить запись в таблицу";
    }

    // Выборка данных из таблицы
    if (!query.exec("SELECT * FROM Gepotenzival"))
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
