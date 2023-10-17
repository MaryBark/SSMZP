#ifndef STATEVECTORDELEGATE_H
#define STATEVECTORDELEGATE_H

#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>


class stateVectorDelegate  : public QItemDelegate
{
    Q_OBJECT
public:
    stateVectorDelegate();

    QSize sizeHint(const QStyleOptionViewItem &option,
                           const QModelIndex &index) const override;

        void paint(QPainter *painter, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const override;
};

#endif // STATEVECTORDELEGATE_H
