#include "stateVectorModel.h"

#include <QDateTime>
#include <QFont>
#include <QColor>
#include <QPainter>
#include <QDebug>
#include <QLabel>

class stateVectorModelPrivate
{
public:
//    QDateTime m_dt; // время КА
    QList <double > m_q; // вектор кеплеровый элементов орбиты КА
//    QByteArray m_q;
};

stateVectorModel::stateVectorModel(QObject *parent) :
    m_dataModelptr(new stateVectorModelPrivate), QAbstractTableModel(parent)
{
    values = new QList<stateVectorShell>();
}

//stateVectorModel::stateVectorModel(std::vector<coordVectorBLH<double>>& dataModel, const QObject *parent):
stateVectorModel::stateVectorModel(const QList <double > & dataModel, const QObject *parent):
    m_dataModelptr(new stateVectorModelPrivate()),
    QAbstractTableModel(/*parent*/)
{
    m_dataModelptr->m_q = dataModel;
    values = new QList<stateVectorShell>();
}

stateVectorModel::~stateVectorModel()
{
    delete m_dataModelptr;
}

int stateVectorModel::rowCount(const QModelIndex &parent) const
{
    return values->count(); // количество эфемерид (сколько их будет - это надо из бекенда дергать, а его пока не прикрутила)
}

int stateVectorModel::columnCount(const QModelIndex &parent) const
{
    return 7; // вектор кеплеровый элементов орбиты КА и дата
}

QVariant stateVectorModel::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
    case Qt::DisplayRole:
    {
        QVariant value;
        switch (index.column())
        {
        case 0: {
            value = this->values->at(index.row()).getX();
            break;
        }
        case 1: {
            value = this->values->at(index.row()).getY();
            break;
        }
        case 2: {
            value = this->values->at(index.row()).getZ();
            break;
        }
        case 3: {
            value = this->values->at(index.row()).getvX();
            break;
        }
        case 4: {
            value = this->values->at(index.row()).getvY();
            break;
        }
        case 5: {
            value = this->values->at(index.row()).getvZ();
            break;
        }
        }
        return value;
    }
     break;
    case Qt::DecorationRole:
       {
        if(index.column() == 1) // а
            return QIcon("semimajor.png");
        if(index.column() == 2) // i
            return QIcon("inclination.png");
        if(index.column() == 3) // e
            return QIcon("eccentricity.png");
        if(index.column() == 4) // Q
            return QIcon("Longitude_of_the_ascending_node.png");
        if(index.column() == 5) // u
            return QIcon("The_pericenter_argument.png");
        if(index.column() == 6) // M
            return QIcon("Average_anomaly.png");

    }
         break;
    case Qt::BackgroundRole:
    {
        return QColor(55, 0, 0, 40);
    }
      break;
     case Qt::FontRole:
    {
        return QFont("Times", 10, QFont::Bold);
    }
      break;
    }

    return QVariant();
}

//Qt::ItemFlags stateVectorModel::flags(const QModelIndex &index) const
//{

//}

QVariant stateVectorModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(role)
    {
    case Qt::DisplayRole:
    {
        if(orientation == Qt::Horizontal) {
                switch(section) {
                    case 0:
                        return QString("Time");
                    case 1:
                        return QString("a");
                    case 2:
                        return QString("i");
                    case 3:
                        return QString("e");
                    case 4:
                        return QString("Q");
                    case 5:
                        return QString("u");
                    case 6:
                        return QString("M");
                    default:
                        return QVariant();
                }
            }
    }
     break;
    case Qt::DecorationRole:
       {
        if(orientation == Qt::Horizontal) {
                switch(section) {
                    case 0:
                        return QString("Time");
                    case 1:
                        return QIcon("semimajor.png");
                    case 2:
                        return QIcon("inclination.png");
                    case 3:
                        return QIcon("eccentricity.png");
                    case 4:
                        return QIcon("Longitude_of_the_ascending_node.png");
                    case 5:
                        return QIcon("The_pericenter_argument.png");
                    case 6:
                        return QIcon("Average_anomaly.png");
                    default:
                        return QVariant();
                }
            }
    }
         break;
    case Qt::BackgroundRole:
    {
        return QColor(55, 0, 0, 40);
    }
      break;
     case Qt::FontRole:
    {
        return QFont("Times", 10, QFont::Bold);
    }
      break;


    }
        return QVariant();
}

void stateVectorModel::populate(QList<stateVectorShell> *newValues)
{
    int idx = this->values->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
    this->values = newValues;
    endInsertRows();
}


//StateVectorModel::StateVectorModel(QObject *parent)
//    :QAbstractListModel(parent)
//{
//    values = new QList<stateVectorShell>();
//}

//int StateVectorModel::rowCount(const QModelIndex &parent) const
//{
//    return values->count();
//}

//int StateVectorModel::columnCount(const QModelIndex &parent) const
//{
//    return 6;
//}

//QVariant StateVectorModel::data(const QModelIndex &index, int role) const
//{
//    QVariant value;

//           switch ( role )
//           {
//               case Qt::DisplayRole: //string
//               {
//                   switch (index.column()) {
//                       case 0: {
//                           value = this->values->at(index.row()).getX();
//                           break;
//                       }
//                       case 1: {
//                           value = this->values->at(index.row()).getY();
//                           break;
//                       }
//                       case 2: {
//                           value = this->values->at(index.row()).getZ();
//                           break;
//                       }
//                   case 3: {
//                       value = this->values->at(index.row()).getvX();
//                       break;
//                   }
//                   case 4: {
//                       value = this->values->at(index.row()).getvY();
//                       break;
//                   }
//                   case 5: {
//                       value = this->values->at(index.row()).getvZ();
//                       break;
//                   }
//                   }
//               }
//               break;

////               case Qt::UserRole: //data
////               {
////                   value = this->values->at(index.row()).getId();
////               }
////               break;

//               default:
//                   break;
//           }

//       return value;
//}

//QVariant StateVectorModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    switch(role)
//       {
//       case Qt::DisplayRole:
//       {
//           if(orientation == Qt::Horizontal) {
//                   switch(section) {
//                       case 0:
//                           return QString("Time");
//                       case 1:
//                           return QString("a");
//                       case 2:
//                           return QString("i");
//                       case 3:
//                           return QString("e");
//                       case 4:
//                           return QString("Q");
//                       case 5:
//                           return QString("u");
//                       case 6:
//                           return QString("M");
//                       default:
//                           return QVariant();
//                   }
//               }
//       }
//        break;
//       case Qt::DecorationRole:
//          {
////           if(orientation == Qt::Horizontal) {
////                   switch(section) {
////                       case 0:
////                           return QString("Time");
////                       case 1:
////                           return QIcon("semimajor.png");
////                       case 2:
////                           return QIcon("inclination.png");
////                       case 3:
////                           return QIcon("eccentricity.png");
////                       case 4:
////                           return QIcon("Longitude_of_the_ascending_node.png");
////                       case 5:
////                           return QIcon("The_pericenter_argument.png");
////                       case 6:
////                           return QIcon("Average_anomaly.png");
////                       default:
////                           return QVariant();
////                   }
////               }
//       }
//            break;
//       case Qt::BackgroundRole:
//       {
//           return QColor(55, 0, 0, 40);
//       }
//         break;
//        case Qt::FontRole:
//       {
//           return QFont("Times", 10, QFont::Bold);
//       }
//         break;


//       }
//    return QVariant();
//}

//void StateVectorModel::populate(QList<stateVectorShell> *newValues)
//{
//    int idx = this->values->count();
//       this->beginInsertRows(QModelIndex(), 1, idx);
//           this->values = newValues;
//       endInsertRows();
//}



