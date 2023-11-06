#include "inc/mathModelSpacecraft.h"

mathModelSpacecraft::mathModelSpacecraft(QObject *parent) :
    QAbstractItemModel(parent)
{}

mathModelSpacecraft::~mathModelSpacecraft()
{}

QModelIndex mathModelSpacecraft::index(int row, int column, const QModelIndex &parent) const
{
    if(!parent.isValid())
    {
        return createIndex(row, column, quintptr(row+1));
    }
    else
    {
        size_t id = parent.internalId();
        return createIndex(row, column, quintptr(id * 10 + (row+1)));
    }

    return QModelIndex();
}

QModelIndex mathModelSpacecraft::parent(const QModelIndex &child) const
{
    if(!child.isValid())
        return QModelIndex();

    size_t id = child.internalId();
    if(id < 10)
        return QModelIndex();


    int parentRow = ((id / 10 % 10)) - 1;
    return createIndex(parentRow, 0, id /  10);
}

int mathModelSpacecraft::rowCount(const QModelIndex &parent) const
{
    return 9;
}

int mathModelSpacecraft::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant mathModelSpacecraft::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return (uint32_t)index.internalId();
    return QVariant();
}
