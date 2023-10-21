#ifndef STATEVECTORDELEGATE_H
#define STATEVECTORDELEGATE_H

#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>
#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyle>
#include <QApplication>
#include <QStyleOptionProgressBar>

class stateVectorDelegate  : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit stateVectorDelegate(QObject* parent = nullptr);
    virtual ~stateVectorDelegate(){}

//    virtual QSize sizeHint(const QStyleOptionViewItem &option,
//                   const QModelIndex &index) const override;

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const override;
};

#endif // STATEVECTORDELEGATE_H
