#include "inc/VectorModel.h"

VectorModel::VectorModel(QObject *parent) :
   QAbstractTableModel(parent)
{
    stateVec = new QList < stateVectorDelegate >;

}

int VectorModel::rowCount(const QModelIndex &parent) const
{
    return 1;
}

int VectorModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant VectorModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

           switch ( role )
           {
               case Qt::DisplayRole: //string
               {
                   switch (index.column()) {
//                       case 0: {
//                           value = this->stateVec->at(index.row()).getId();
//                           break;
//                       }
//                       case 1: {
//                           value = this->stateVec->at(index.row()).getName();
//                           break;
//                       }
//                       case 2: {
//                           value = this->stateVec->at(index.row()).getIcon();
//                           break;
//                       }
//                       case 3: {
//                           value = this->stateVec->at(index.row()).getIcon();
//                           break;
//                       }
                   }
               }
               break;

               case Qt::UserRole: //data
               {
//                   value = this->values->at(index.row()).getId();
               }
               break;

               default:
                   break;
           }

       return value;
}
