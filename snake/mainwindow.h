#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <snake.h>
#include <QTimer>
#include <QKeyEvent>

class QGraphicsScene;

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *mainscene;
    Snake          *player_snake;
    QTimer         *timer;
};

#endif // MAINWINDOW_H
