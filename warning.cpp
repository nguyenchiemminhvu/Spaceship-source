#include "warning.h"

Warning::Warning(QString warning, QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    this->warning = warning;
    state = true;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(changeState()));
    timer->start(500);
}

Warning::~Warning()
{
    this->deleteLater();
}

QRectF Warning::boundingRect() const
{
    return QRectF(QPointF(100,200),QSize(400,200));
}

void Warning::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setFont(QFont("Time New Roman",20));
    painter->setPen(QPen(Qt::red,3));

    if(state)   {
        painter->drawText(QPointF(100,250),QString("WARNING:"));
        painter->drawText(QPointF(100,300),QString(warning));
    }
}

void Warning::changeState()
{
    if(state)   {
        state = false;
        update();
    }
    else    {
        state = true;
        update();
    }
}
