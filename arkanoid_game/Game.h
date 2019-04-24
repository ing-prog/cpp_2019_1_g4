#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView {
public:
    // Constructor
    Game(QWidget* parent = nullptr);

    // Public methods
    void start();
    void createBlockCol(double x);
    void createBlockGrid();

    // Public attributes
    QGraphicsScene* scene;
};

#endif // GAME_H
