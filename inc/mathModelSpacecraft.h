#ifndef MATHMODELSPACECRAFT_H
#define MATHMODELSPACECRAFT_H

#include <QObject>
#include <QAbstractItemModel>

class mathModelSpacecraft : public QAbstractItemModel
{
    Q_OBJECT
public:
    mathModelSpacecraft(QObject* parent = nullptr);
    virtual ~mathModelSpacecraft();

    // QAbstractItemModel interface
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // MATHMODELSPACECRAFT_H
