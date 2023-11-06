#ifndef SETTINGSTREEITEM_H
#define SETTINGSTREEITEM_H

//#include <QObject>
#include <QList>
#include <QVector>
#include <QVariant>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemDelegate>
#include <QLineEdit>


class SettingsDelegate : public QItemDelegate
{
public:
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        // Создание редактора на основе типа ячейки
        QLineEdit* editor = new QLineEdit(parent);
        return editor;
    }

    void setEditorData(QWidget* editor, const QModelIndex& index) const override
    {
        // Установка значений редактора на основе данных из модели
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
};




//class settingsTreeItem
//{
////    Q_OBJECT
//public:
//    explicit settingsTreeItem(QList< QWidget *> lstWGT, settingsTreeItem *parentItem = 0);
//    ~settingsTreeItem();


//private:
//    QList< QWidget *> m_lstWGT; // спикок виджетов
//};

#endif // SETTINGSTREEITEM_H
