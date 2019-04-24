#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

Game::Game(QWidget *parent): QGraphicsView(parent) {
    // Initialize scene
    scene = new QGraphicsScene(0, 0, 400, 600);
    setScene(scene);

    // set mouse tracking
    setMouseTracking(true);
}

void Game::start() {
    // Create a ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);

    // Create a paddle
    Paddle* paddle = new Paddle();
    paddle->setPos(150,575);
    scene->addItem(paddle);

    paddle->grabMouse();

    // Create the blocks grid
    createBlockGrid();
}

void Game::createBlockCol(double x) {
    for (size_t i = 0; i < 5; ++i)
    {
        Block* block = new Block();
        block->setPos(x, i*52); // 2 space b/w blocks (50 height of block)
        scene->addItem(block);
    }
}

void Game::createBlockGrid() {
    for (size_t i = 0; i < 7; ++i)
    {
        createBlockCol(15 + i*52);
    }
}
