#include "food.h"

#include <QBrush>
#include <QPen>

Food::Food(QObject *parent) :
    QObject(parent)
{
    setRect(0, 0, 9, 9);
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    pen.setColor(Qt::red);
    setBrush(brush);
    setPen(pen);
}

void Food::new_food_pos()
{
    int x = rand.bounded(49);
    int y = rand.bounded(49);
    setPos(x*10, y*10);
}
