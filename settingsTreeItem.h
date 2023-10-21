#ifndef SETTINGSTREEITEM_H
#define SETTINGSTREEITEM_H

//#include <QObject>
#include <QList>
#include <QVector>
#include <QVariant>


class settingsTreeItem
{
//    Q_OBJECT
public:
    explicit settingsTreeItem(QList< QWidget *> lstWGT, settingsTreeItem *parentItem = 0);
    ~settingsTreeItem();


private:
    QList< QWidget *> m_lstWGT; // спикок виджетов
};

#endif // SETTINGSTREEITEM_H
