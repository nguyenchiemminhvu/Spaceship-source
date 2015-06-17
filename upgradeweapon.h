#ifndef UPGRADEWEAPON_H
#define UPGRADEWEAPON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include "player.h"
#include "bullet.h"
#include "bullet2.h"
#include "bullet3.h"

class UpgradeWeapon: public QObject, public QGraphicsRectItem
{

    Q_OBJECT
public:
    explicit UpgradeWeapon(QGraphicsItem* parent = 0);
    ~UpgradeWeapon();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void upgrade();
    void deleted();

public slots:
    void move();
    void checkCollides();
    void deleteUpgrade();

private:

    QTimer* timer;
    QTimer* check;

    void setUpTimer();
    void setUpChecker();
};

#endif // UPGRADEWEAPON_H
