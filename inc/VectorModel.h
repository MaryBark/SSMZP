#ifndef VECTORMODEL_H
#define VECTORMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QVector>
#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>
#include <QModelIndex>
#include "stateVectorDelegate.h"


class VectorModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    VectorModel(QObject* parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;


private:
    QList < stateVectorDelegate > * stateVec;
};

#endif // VECTORMODEL_H
