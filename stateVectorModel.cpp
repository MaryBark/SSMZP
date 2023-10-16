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
{}

//stateVectorModel::stateVectorModel(std::vector<coordVectorBLH<double>>& dataModel, const QObject *parent):
stateVectorModel::stateVectorModel(const QList <double > & dataModel, const QObject *parent):
    m_dataModelptr(new stateVectorModelPrivate()),
    QAbstractTableModel(/*parent*/)
{
    m_dataModelptr->m_q = dataModel;
}

stateVectorModel::~stateVectorModel()
{
    delete m_dataModelptr;
}

int stateVectorModel::rowCount(const QModelIndex &parent) const
{
    return 10; // количество эфемерид (сколько их будет - это надо из бекенда дергать, а его пока не прикрутила)
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
//        m_dataModelptr->m_q = QList<double>();
//        m_dataModelptr->m_q << = 10;
//        m_dataModelptr->m_q[1] = 10;
//        m_dataModelptr->m_q[3] = 10;
        QList <double> d;
        d << m_dataModelptr->m_q[0] << m_dataModelptr->m_q[2] << m_dataModelptr->m_q[3];

        QVariant value;
        if (!index.isValid())
                return QVariant();

//        QModelIndex index = this->model()->index(0, 0);
//        QLabel *lblImage = new QLabel();
//        lblImage->setPixmap(QPixmap("free-icon-whatsapp-3670051.png"));
//        return lblImage;
//        tabelview->setIndexWidget(index, lblImage);

//        return QIcon("free-icon-whatsapp-3670051.png");

//        switch (index.column()) {
//        case 0: {
//            value = m_dataModelptr->m_q.at(0/*index.row()*/);
//            break;
//        }
//        case 1: {
//            value = m_dataModelptr->m_q.at(156);
//            break;
//        }
//        case 2: {
//            value = m_dataModelptr->m_q.at(34546/*index.row()*/);
//            break;
//        }
//        }

//        this->setHeaderData(1, Qt::Horizontal, tr(""));


//        int d = m_dataModelptr->m_q.at(index.row() * 7 + index.column());

//        return QVariant(d);
        return d;

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

Qt::ItemFlags stateVectorModel::flags(const QModelIndex &index) const
{

}

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





