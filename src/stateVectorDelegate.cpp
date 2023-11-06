#include "inc/stateVectorDelegate.h"
#include "math.h"

//#include <QPainter>


stateVectorDelegate::stateVectorDelegate(QObject* parent) : QStyledItemDelegate(parent)
{}

void stateVectorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 1) {
            int progress = index.data().toInt();

            QStyleOptionButton buttonOption;
            buttonOption.rect = option.rect;
//            progressBarOption.
//            progressBarOption.minimum = 0;
//            progressBarOption.maximum = 100;
//            progressBarOption.progress = progress;
            buttonOption.text = QString::number(progress) + "%";
//            progressBarOption.textVisible = true;

            QApplication::style()->drawControl(QStyle::CE_RadioButton,
                                               &buttonOption, painter);
        } else
            QStyledItemDelegate::paint(painter, option, index);
}

//QSize stateVectorDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    return QItemDelegate::sizeHint(option, index);
//}

//void stateVectorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//  QStyleOptionViewItem myOption = option;

//    if (index.column()==2)
//    {
//        QString data = index.model()->data(index, Qt::DisplayRole).toString();


//        myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;

//        QString icon = ":/img/" + index.model()->data(index, Qt::DisplayRole).toString();

////        qDebug() << icon;

//        QPixmap pixmap2(icon);

//        painter->drawPixmap(myOption.rect.x()+30,myOption.rect.y(),32,32, pixmap2);
//    }
//    else
//    {
//        drawDisplay(painter, option, option.rect, index.model()->data(index, Qt::DisplayRole).toString());

//    }
//    drawFocus(painter, myOption, myOption.rect);




//}
