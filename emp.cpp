#include "emp.h"

EMP::EMP(QPointF center, qreal radius, QGraphicsItem* parent)
    : QGraphicsEllipseItem(parent)
{
    this->center = center;
    this->radius = radius;
    setRect(QRectF(center.x() - radius, center.y() - radius, radius * 2, radius * 2));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(increaseRadius()));
    timer->start(10);
}

EMP::~EMP()
{
    this->deleteLater();
}

QRectF EMP::boundingRect() const
{
    return QRectF(QPointF(center.x() - radius, center.y() - radius),QSize(radius*2, radius*2));
}

void EMP::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::gray,3));
    painter->drawEllipse(center,radius,radius);
}

void EMP::increaseRadius()
{
    radius += 10;
    setRect(QRectF(center.x() - radius, center.y() - radius, radius * 2, radius * 2));

    if(radius >= 200)
        this->deleteLater();

    //check if enemy inside EMP region
    QList<QGraphicsItem*> list_enemy = collidingItems();

    foreach (QGraphicsItem* item, list_enemy) {

        if(typeid(*item) == typeid(Enemy))  {

            delete item;
            emit killAnEnemy();
        }
    }

    update();
}
