#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPen>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <typeinfo>
#include "bullet.h"
#include "health.h"

class Enemy : public QObject, public QGraphicsRectItem
{

    Q_OBJECT
public:
    enum { oneMove = 10 };
    explicit Enemy(int h = 1,QGraphicsItem *parent = 0);
    ~Enemy();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void enemyPassTheDefense();
    void collidedWithPlayer();
    void getScore();

public slots:
    void move();
    void check_collides();
    void enemyStop();
    void takeBullet();
    void destroyEnemy();
    void increaseScore();

    void stopMoving();
    void keepMoving();

private:
    QTimer* timer;
    QTimer* check;
    Health* health;

    void setUpHealth(int h = 1);
};

#endif // ENEMY_H
