#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTextDocument>
#include <QTimer>
#include "graphicsscene.h"
#include "player.h"
#include "bullet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);

signals:
    void pause();
    void resume();

public slots:
    void continueSpawnEnemy();
    void stopSpawnEnemy();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    GraphicsScene* scene;
    Player* player;

    bool gamePause;

    void setUpScene();
    void setUpPlayer();
    void addPlayerToScene();
    void setUpView();
    void setUpTimer();
    void setUpGame();
};

#endif // MAINWINDOW_H
