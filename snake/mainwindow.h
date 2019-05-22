#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsScene;
class QTimer;
class QKeyEvent;
class Snake;
class Food;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void game_move();

private:
    void CheckFood();

    Ui::MainWindow *ui;

    QGraphicsScene *mainscene;
    QTimer         *timer;
    Snake          *player_snake;
    Food           *food;
};

#endif // MAINWINDOW_H
