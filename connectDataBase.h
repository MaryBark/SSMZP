#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include "PZ_90_02.h"

#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QObject>


class connectDataBase : public QObject
{
    Q_OBJECT
public:
    connectDataBase(const QString& dataBase);

public slots:
    void run()
    {
        // чего сюда сувать хз
    }

private:
    QSqlDatabase db;
    QSqlQuery query;

};




// Потом посажу сей чудесный класс в отдельную пару файлов, а сейчас пока ну его на фиг и так в файлах путаюсь((((
class DatabaseDelegate : public QStyledItemDelegate
{
public:
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QWidget* editor = QStyledItemDelegate::createEditor(parent, option, index);
        // Настройка редактора, если необходимо
        return editor;
    }

    void setEditorData(QWidget* editor, const QModelIndex& index) const override
    {
        // Задание значений редактора на основе данных из модели
        QString value = index.model()->data(index, Qt::DisplayRole).toString();
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(editor);
        if (lineEdit)
            lineEdit->setText(value);
    }

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override
    {
        // Сохранение изменений из редактора в модель
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(editor);
        if (lineEdit)
            model->setData(index, lineEdit->text(), Qt::EditRole);
    }

    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        editor->setGeometry(option.rect);
    }

    QString displayText(const QVariant& value, const QLocale& locale) const override
    {
        // Настройка отображения значения ячейки, если необходимо
        return value.toString();
    }
};



#endif // CONNECTDATABASE_H
