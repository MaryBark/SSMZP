#include "inc/MapMarbleDelegate.h"
#include <QPainter>
#include <QDebug>

MapMarbleDelegate::MapMarbleDelegate() : QItemDelegate()
{}

void MapMarbleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString data = index.model()->data(index, Qt::DisplayRole).toString();

    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;

    QString icon = ":/img/" + index.model()->data(index, Qt::DecorationRole).toString();

    QPixmap pixmap2(icon);

    drawDisplay(painter, myOption, myOption.rect, data);
    drawFocus(painter, myOption, myOption.rect);

    painter->drawPixmap(myOption.rect.x(),myOption.rect.y(),13,13, pixmap2);
}

QSize MapMarbleDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

