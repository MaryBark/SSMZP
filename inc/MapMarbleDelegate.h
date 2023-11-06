#ifndef MAPMARBLEDELEGATE_H
#define MAPMARBLEDELEGATE_H

#include <QItemDelegate>

class MapMarbleDelegate :public QItemDelegate
{
    Q_OBJECT
public:
    MapMarbleDelegate();

    // QAbstractItemDelegate interface

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MAPMARBLEDELEGATE_H
