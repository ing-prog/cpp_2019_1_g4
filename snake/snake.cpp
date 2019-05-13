#include "snake.h"

#include <QBrush>
#include <QPen>

Snake::Snake(QObject *parent) :
    QObject(parent)
{
    QGraphicsRectItem* new_snake_block = new QGraphicsRectItem();
    new_snake_block->setRect(0, 0, 9, 9);
    new_snake_block->setPos(50, 50);
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    pen.setColor(Qt::darkGreen);
    new_snake_block->setBrush(brush);
    new_snake_block->setPen(pen);

    snake_blocks.push_back(new_snake_block);

    new_snake_block = new QGraphicsRectItem();
    new_snake_block->setRect(0, 0, 9, 9);
    new_snake_block->setPos(60, 50);
    new_snake_block->setBrush(brush);
    new_snake_block->setPen(pen);

    snake_blocks.push_back(new_snake_block);

    new_snake_block = new QGraphicsRectItem();
    new_snake_block->setRect(0, 0, 9, 9);
    new_snake_block->setPos(70, 50);
    new_snake_block->setBrush(brush);
    new_snake_block->setPen(pen);

    snake_blocks.push_back(new_snake_block);

    direction.append(1);
    direction.append(0);
}

QVector<QGraphicsRectItem *> &Snake::getBlocks()
{
    return snake_blocks;
}

void Snake::move() {
    snake_blocks.first()->setPos(snake_blocks.last()->pos() + QPointF(10 * direction[0], 10 * direction[1]));

    snake_blocks.push_back(snake_blocks.first());
    snake_blocks.pop_front();
    moved = true;

    CheckWall();
}

void Snake::GoUp()
{
    if (direction[1] == 1 || !moved) return;

    direction[1] = -1;
    direction[0] = 0;
    moved = false;
}

void Snake::GoDown()
{
    if (direction[1] == -1 || !moved) return;

    direction[1] = 1;
    direction[0] = 0;
    moved = false;
}

void Snake::GoLeft()
{
    if (direction[0] == 1 || !moved) return;

    direction[0] = -1;
    direction[1] = 0;
    moved = false;
}

void Snake::GoRight()
{
    if (direction[0] == -1 || !moved) return;

    direction[0] = 1;
    direction[1] = 0;
    moved = false;
}

void Snake::CheckWall()
{
    if (snake_blocks.last()->x() > 490)
    {
        snake_blocks.last()->setPos(0, snake_blocks.last()->y());
    }
    if (snake_blocks.last()->x() < 0)
    {
        snake_blocks.last()->setPos(490, snake_blocks.last()->y());
    }
    if (snake_blocks.last()->y() > 490)
    {
        snake_blocks.last()->setPos(snake_blocks.last()->x(), 0);
    }
    if (snake_blocks.last()->y() < 0)
    {
        snake_blocks.last()->setPos(snake_blocks.last()->x(), 490);
    }
}
