#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include "snake.h"
#include "food.h"

MainWindow::MainWindow(QWidget *parent) :
    // Список инициализации членов класса
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainscene(new QGraphicsScene(0, 0, 500, 500)),
    timer(new QTimer),
    player_snake(new Snake),
    food(new Food)
{
    ui->setupUi(this);
    setFocus();

    for (auto i = player_snake->getBlocks().begin(); i < player_snake->getBlocks().end(); i++)
    {
        mainscene->addItem(*i);
    }

    // Начальная позиция еды
    do
    {
        food->new_food_pos();
    } while (!food->collidingItems().empty());

    mainscene->addItem(food);

    ui->graphicsView->setScene(mainscene);

    connect(timer, SIGNAL(timeout()), this, SLOT(game_move()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::game_move()
{
    // Движение змейки
    player_snake->move();

    // Проверка на выход за границу сцены
    player_snake->CheckWall();

    // Проверка на столкновение с едой
    CheckFood();
}

void MainWindow::CheckFood()
{
    if (player_snake->getHeadPos() == food->pos())
    {
        player_snake->Enlarge();

        mainscene->addItem(player_snake->getBlocks().first());

        // Новая позиция еды
        do
        {
            food->new_food_pos();
        } while (!food->collidingItems().empty());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)    { player_snake->GoUp();    }
    if (event->key() == Qt::Key_Down)  { player_snake->GoDown();  }
    if (event->key() == Qt::Key_Left)  { player_snake->GoLeft();  }
    if (event->key() == Qt::Key_Right) { player_snake->GoRight(); }
}
