#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QGraphicsRectItem>

class Snake : public QObject
{
    Q_OBJECT
public:
    explicit Snake(QObject *parent = nullptr);
    QVector<QGraphicsRectItem *> &getBlocks();

    QPointF getHeadPos();

    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();

signals:

public slots:
    void move();

private:
    void CheckWall();

    QVector<QGraphicsRectItem*> snake_blocks;
    QVector<int> direction;
    bool moved = false;
};

#endif // SNAKE_H
