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
#include <QMediaPlayer>
#include <QDir>
#include "graphicsscene.h"
#include "player.h"
#include "bullet.h"
#include "sourceenemy.h"
#include "warning.h"
#include "upgradeweapon.h"

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
    void playing();
    void endGame();

    void continueSpawnEnemy();
    void stopSpawnEnemy();
    void createWarning();
    void clearWarning();
    void createUpgradeWeapon();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    GraphicsScene* scene;
    Player* player;
    SourceEnemy* source_of_enemy;
    Warning* warning;
    QMediaPlayer* music;

    bool gamePause;

    void setUpMusicBackground();
    void setUpScene();
    void setUpPlayer();
    void addPlayerToScene();
    void setUpView();
    void setUpTimer();
    void setUpGame();
    void setUpSourceOfEnemy();
};

#endif // MAINWINDOW_H
