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
//    QList <double > m_q; // вектор координат и скоростей КА
    QByteArray m_q;
};

stateVectorModel::stateVectorModel(QObject *parent) :
    m_dataModelptr(new stateVectorModelPrivate), QAbstractTableModel(parent)
{

}

stateVectorModel::stateVectorModel(const QByteArray &dataModel, const QObject *parent):
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
    return 10; // количество эфемерид (скольки их будет - это надо из бекенда дергать, а его пока не прикрутила)
}

int stateVectorModel::columnCount(const QModelIndex &parent) const
{
    return 7; // координаты, скорости и дата
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
//        int d =  m_dataModelptr->m_q[0];

//        QVariant value;
//        if (!index.isValid())
//                return QVariant();

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

//        return QVariant(d)/*m_dataModelptr->m_q*//*value*/;

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


//    case Qt::Pa
//   {
//    }
//    break;

    }

    return QVariant();
}

Qt::ItemFlags stateVectorModel::flags(const QModelIndex &index) const
{

}

bool stateVectorModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    switch(role)
    {
    case Qt::DisplayRole:
    {

    }
        break;
    }
}




