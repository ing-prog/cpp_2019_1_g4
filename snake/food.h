#ifndef FOOD_H
#define FOOD_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QRandomGenerator>

class Food : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Food(QObject *parent = nullptr);
    void new_food_pos();

signals:

public slots:

private:
    QRandomGenerator rand;
};

#endif // FOOD_H
