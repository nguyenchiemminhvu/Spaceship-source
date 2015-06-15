#include "bullet3.h"

Bullet3::Bullet3(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    setRect(0,0,10,20);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

Bullet3::~Bullet3()
{
    this->deleteLater();
}

QRectF Bullet3::boundingRect() const
{
    return rect();
}

void Bullet3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->drawRect(option->rect);
    painter->drawPixmap(option->rect,QPixmap(":/images/bullet3.png"));
}

void Bullet3::move()
{
    setPos(pos().x(), pos().y() - oneMove);

    if(pos().y() <= 50)
    {
        this->deleteLater();
    }
}

