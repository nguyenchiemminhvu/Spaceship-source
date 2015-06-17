#ifndef BULLET2_H
#define BULLET2_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QPainter>
#include <typeinfo>
#include "enemy.h"
#include "score.h"

class Bullet2 : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum { oneMove = 10 };
    explicit Bullet2(QGraphicsItem *parent = 0);
    ~Bullet2();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void move();

private:
    QTimer* timer;
};

#endif // BULLET2_H
