#ifndef BULLET3_H
#define BULLET3_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>
#include <typeinfo>
#include "enemy.h"
#include "score.h"

class Bullet3 : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum { oneMove = 10 };
    explicit Bullet3(QGraphicsItem *parent = 0);
    ~Bullet3();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void move();

private:
    QTimer* timer;
};

#endif // BULLET3_H
