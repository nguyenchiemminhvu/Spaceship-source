#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPen>
#include <QPainter>
#include <QTimer>
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "emp.h"

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum { oneMove = 15 };
    explicit Player(QGraphicsItem* parent = 0);
    ~Player();

    void addScoreToScene();
    void addHealthToScene();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void pause();
    void resume();

public slots:
    void shoot();
    void toggleEMP();
    void moveToPosition(QPointF point);
    void killAnEnemy();
    void onEnemyPassTheDefense();
    void spawnEnemy();

    void onPause();
    void onResume();

private:
    Score* score;
    QTimer* timer;

    int num_of_EMP;
    bool isPaused;
};

#endif // PLAYER_H
