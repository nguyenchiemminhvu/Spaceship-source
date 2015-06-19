#include "boss.h"

Boss::Boss(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    health->setHealth(500);
    isDefense = false;
    setRect(0,-100,100,100);

    check = new QTimer(this);
    connect(check,SIGNAL(timeout()),this,SLOT(checkCollided()));
    check->start(10);
}

Boss::~Boss()
{
    this->deleteLater();
}

QRectF Boss::boundingRect() const
{
    return rect();
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isDefense)
    {
        painter->setPen(Qt::white);
        painter->drawRect(option->rect);
    }
    else
    {
        painter->setPen(Qt::NoPen);
        painter->drawRect(option->rect);
    }
    painter->drawPixmap(option->rect,QPixmap(":/images/youngbuffalo.jpg"));
}

void Boss::setStartPos()
{
    setPos(200,100);
}

void Boss::attack()
{

}

void Boss::defense()
{
    health->setHealth(health->getHealth() + 50);

    QPropertyAnimation* animation = new QPropertyAnimation(this,"pos",this);

    connect(animation,SIGNAL(finished()),this,SLOT(setStartPos()));
    connect(animation,SIGNAL(finished()),animation,SLOT(deleteLater()));

    animation->setDuration(2000);
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(200,100));

    animation->start();
}

void Boss::offensive()
{

}

void Boss::checkCollided()
{
    if(collidesWithItem(scene()->focusItem()))  {

        delete scene()->focusItem();
    }

    QList<QGraphicsItem*> list_bullet = collidingItems();

    foreach (QGraphicsItem* item, list_bullet) {

        if(typeid(*item) == typeid(Bullet)) {

            delete item;
            health->decreaseHealth();
        }
        else if(typeid(*item) == typeid(Bullet2))   {

            delete item;
            health->decreaseHealth2();
        }
        else if(typeid(*item) == typeid(Bullet3))   {

            delete item;
            health->decreaseHealth3();
        }
    }
}
