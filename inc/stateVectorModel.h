#ifndef STATEVECTORMODEL_H
#define STATEVECTORMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QVector>
#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>
#include <QModelIndex>

#include "stateVectorShell.h"

class stateVectorModelPrivate;

class stateVectorModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    stateVectorModel(QObject* parent = nullptr);
//    stateVectorModel(std::vector<coordVectorBLH<double>>& dataModel, const QObject* parent = nullptr);
    stateVectorModel(const QList <double > & dataModel, const QObject* parent = nullptr);
//    stateVectorModel(/*const QList <double >*/const QByteArray& dataModel, const QObject* parent = nullptr);
    ~stateVectorModel();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
//    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void populate(QList<stateVectorShell> *newValues);

private:
    stateVectorModelPrivate *m_dataModelptr;
//    QList<stateVectorShell> *values;
};



#endif // STATEVECTORMODEL_H
