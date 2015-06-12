#ifndef EMP_H
#define EMP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QPainter>
#include "enemy.h"
#include <typeinfo>

class EMP : public QObject, public QGraphicsEllipseItem
{

    Q_OBJECT
public:
    explicit EMP(QPointF center, qreal radius = 25, QGraphicsItem* parent = 0);
    ~EMP();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void killAnEnemy();

public slots:
    void increaseRadius();

private:
    QPointF center;
    qreal radius;
    QTimer* timer;
};

class CountEMP : public QGraphicsTextItem
{

    Q_OBJECT
public:
    explicit CountEMP(QGraphicsItem* parent = 0);
    ~CountEMP();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getNumOfEMP();
    void setNumOfEMP(int num = 3);

signals:

public slots:
    void increaseEMP();
    void decreaseEMP();

private:
    int num_of_EMP;

    QTimer* timer;
};

#endif // EMP_H
