#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainscene(new QGraphicsScene(0, 0, 500, 500)),
    player_snake(new Snake),
    timer(new QTimer)
{
    ui->setupUi(this);
    setFocus();

    for (auto i = player_snake->getBlocks().begin(); i < player_snake->getBlocks().end(); i++) {
        mainscene->addItem(*i);
    }

    ui->graphicsView->setScene(mainscene);

    connect(timer, SIGNAL(timeout()), player_snake, SLOT(move()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        player_snake->GoUp();
    }
    if (event->key() == Qt::Key_Down) {
        player_snake->GoDown();
    }
    if (event->key() == Qt::Key_Left) {
        player_snake->GoLeft();
    }
    if (event->key() == Qt::Key_Right) {
        player_snake->GoRight();
    }
}
