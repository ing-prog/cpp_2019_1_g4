#include "Block.h"
#include <QBrush>
#include <QPen>

Block::Block(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(0,0,50,50);
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    pen.setColor(Qt::darkGreen);
    setBrush(brush);
    setPen(pen);
}
