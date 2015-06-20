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


CountEMP::CountEMP(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    num_of_EMP = 3;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(increaseEMP()));

    timer->start(10000);
}

CountEMP::~CountEMP()
{
    this->deleteLater();
}

QRectF CountEMP::boundingRect() const
{
    return QRectF(QPointF(400,0),QSize(100,21));
}

void CountEMP::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::yellow);
    painter->setFont(QFont("Time New Roman",15,-1,true));
    painter->drawText(boundingRect(),QString("EMP: ") + QString::number(num_of_EMP));
}

int CountEMP::getNumOfEMP()
{
    return num_of_EMP;
}

void CountEMP::setNumOfEMP(int num)
{
    num_of_EMP = num;
}

void CountEMP::increaseEMP()
{
    if(num_of_EMP < 3)
        num_of_EMP++;
    update();
}

void CountEMP::decreaseEMP()
{
    if(num_of_EMP > 0)
        num_of_EMP--;
    update();
}


