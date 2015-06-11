#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QPen>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <typeinfo>
#include "score.h"
#include "enemy.h"
#include "score.h"

class Bullet : public QObject, public QGraphicsRectItem
{

    Q_OBJECT
public:
    enum { oneMove = 10 };
    explicit Bullet(QGraphicsItem* parent = 0);
    ~Bullet();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void shotedAnEnemy();

public slots:
    void move();
};

#endif // BULLET_H
