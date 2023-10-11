#ifndef STATEVECTORMODEL_H
#define STATEVECTORMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QVector>
#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>

class stateVectorModelPrivate;

class stateVectorModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    stateVectorModel(QObject* parent = nullptr);
//    stateVectorModel(/*const QList <double >*/const QByteArray& dataModel, const QObject* parent = nullptr);
    stateVectorModel(/*const QList <double >*/const QByteArray& dataModel, const QObject* parent = nullptr);
    ~stateVectorModel();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);


private:
    stateVectorModelPrivate *m_dataModelptr;


    // QAbstractItemModel interface

};

#endif // STATEVECTORMODEL_H
