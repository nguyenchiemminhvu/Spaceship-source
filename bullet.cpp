#include "bullet.h"

Bullet::Bullet(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    setRect(0,0,10,20);

    //make the bullet move
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

Bullet::~Bullet()
{
    this->deleteLater();
}

QRectF Bullet::boundingRect() const
{
    return rect();
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    //draw the bullet
    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->drawRect(option->rect);
    painter->drawPixmap(option->rect,QPixmap(":/images/bullet.jpg"));
}

void Bullet::move()
{
    /*
    //check whether the bullet collides with an enemy, if true -> destroy both
    QList<QGraphicsItem*> list_item = collidingItems();

    foreach (QGraphicsItem* item, list_item) {

        if(typeid(*item) == typeid(Enemy))  {

            if(this->collidesWithItem(item))    {

                this->deleteLater();
                delete item;
                emit shotedAnEnemy();
                return;
            }
        }
    }
    */

    setPos(x(),y() - oneMove);

    //check if the bullet get over the top of scene
    if(y() <= 50)
    {
        this->deleteLater();
    }
}
