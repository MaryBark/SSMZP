#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // загрузка файла стилей
    QFile styleF;
    styleF.setFileName("styles.css");
    if(styleF.open(QFile::ReadOnly))
    {
        QString qssStr = styleF.readAll();
        a.setStyleSheet(qssStr);
    }

    w.show();
    return a.exec();
}
