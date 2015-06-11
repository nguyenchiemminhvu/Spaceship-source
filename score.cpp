#include "score.h"

Score::Score(QGraphicsItem* parent)
    : QGraphicsTextItem(parent)
{
    score = 0;
}

Score::~Score()
{
    this->deleteLater();
}

int Score::getScore()
{
    return score;
}

QRectF Score::boundingRect() const
{
    return QRectF(QPoint(0,0),QSize(250,21));
}

void Score::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //draw score at top left of the scene
    painter->setFont(QFont("Time New Roman",15,-1,true));
    painter->setPen(Qt::green);
    painter->drawText(boundingRect(),"Score: " + QString::number(score));
    painter->drawRect(boundingRect());
}

void Score::increaseScore(int s)
{
    score += s;
    update();
}

void Score::decreaseScore(int s)
{
    if(score - s >= 0)
        score -= s;
    else
        score = 0;
    update();
}
