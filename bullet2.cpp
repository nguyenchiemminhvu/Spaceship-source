#include "bullet2.h"

Bullet2::Bullet2(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    setRect(0,0,10,20);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

Bullet2::~Bullet2()
{
    this->deleteLater();
}

QRectF Bullet2::boundingRect() const
{
    return rect();
}

void Bullet2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::NoPen));
    painter->drawRect(option->rect);
    painter->drawPixmap(option->rect,QPixmap(":/images/bullet2.png"));
}

void Bullet2::move()
{
    setPos(pos().x(), pos().y() - oneMove);

    if(pos().y() <= 50)
    {
        this->deleteLater();
    }
}



