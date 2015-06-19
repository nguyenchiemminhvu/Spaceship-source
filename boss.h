#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPropertyAnimation>
#include "health.h"
#include "bullet.h"
#include "bullet2.h"
#include "bullet3.h"

class Boss : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Boss(QGraphicsItem *parent = 0);
    ~Boss();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void setStartPos();
    void attack();
    void defense();
    void offensive();
    void checkCollided();

private:
    QTimer* check;
    Health* health;
    bool isDefense;
};

#endif // BOSS_H
