#ifndef SETTINGSTREEVIEW_H
#define SETTINGSTREEVIEW_H

#include <QObject>
#include <QAbstractItemModel>
#include <QModelIndex>

#include "MapMarbleTrassa.h"


//class settingsTreeView  : public QAbstractItemModel
//{
//    Q_OBJECT
//public:
//    settingsTreeView(QList< QWidget *> lstwgt, QObject *parent = nullptr);
//    ~settingsTreeView(){}

//    // QAbstractItemModel interface
//    QModelIndex index(int row, int column, const QModelIndex &parent) const;
//    QModelIndex parent(const QModelIndex &child) const;
//    int rowCount(const QModelIndex &parent) const;
//    int columnCount(const QModelIndex &parent) const;
//    QVariant data(const QModelIndex &index, int role) const;
////    bool setData(const QModelIndex &index, const QVariant &value, int role);
////    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

//private:
//    QList< QWidget *> _lstWGT;

//};

#endif // SETTINGSTREEVIEW_H
