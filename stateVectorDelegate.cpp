#include "stateVectorDelegate.h"
#include "math.h"

#include <QPainter>


stateVectorDelegate::stateVectorDelegate()
{}

QSize stateVectorDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

void stateVectorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItem myOption = option;

    if (index.column()==2)
    {
        QString data = index.model()->data(index, Qt::DisplayRole).toString();


        myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;

        QString icon = ":/img/" + index.model()->data(index, Qt::DisplayRole).toString();

//        qDebug() << icon;

        QPixmap pixmap2(icon);

        painter->drawPixmap(myOption.rect.x()+30,myOption.rect.y(),32,32, pixmap2);
    }
    else
    {
        drawDisplay(painter, option, option.rect, index.model()->data(index, Qt::DisplayRole).toString());

    }
    drawFocus(painter, myOption, myOption.rect);


}
