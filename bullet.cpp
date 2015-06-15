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
    setPos(x(),y() - oneMove);

    //check if the bullet get over the top of scene
    if(y() <= 50)
    {
        this->deleteLater();
    }
}
