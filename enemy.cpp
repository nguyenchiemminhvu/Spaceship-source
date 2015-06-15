#include "enemy.h"

Enemy::Enemy(int h,QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    setRect(0, 25, 50, 50);

    //setup health for enemy
    setUpHealth(h);
    //set random position
    setPos(rand()%430 + oneMove, 0);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(90);

    //setup the timer to check collides every 0.1 second
    check = new QTimer(this);
    connect(check,SIGNAL(timeout()),this,SLOT(check_collides()));
    check->start(10);
}

Enemy::~Enemy()
{
    this->deleteLater();
}

QRectF Enemy::boundingRect() const
{
    return rect();
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    //draw enemy
    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->drawRect(option->rect);
    painter->drawPixmap(option->rect,QPixmap(":/images/enemy.png"));
}

void Enemy::move()
{
    //check if enemy collides with player
    if(collidesWithItem(scene()->focusItem()))
    {
        destroyEnemy();
        delete scene()->focusItem();
        emit collidedWithPlayer();
        return;
    }

    setPos(pos().x(), pos().y() + oneMove);

    //check if enemy move over the scene
    if(pos().y() + rect().height() >= 600)
    {
        destroyEnemy();
        emit enemyPassTheDefense();
    }
}

void Enemy::check_collides()
{
    //check if enemy collides with bullet
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

void Enemy::enemyStop()
{
    timer->stop();
}

void Enemy::takeBullet()
{
    health->decreaseHealth();
}

void Enemy::destroyEnemy()
{
    this->deleteLater();
}

void Enemy::increaseScore()
{
    emit getScore();
}

void Enemy::stopMoving()
{
    timer->stop();
}

void Enemy::keepMoving()
{
    timer->start(90);
}

void Enemy::setUpHealth(int h)
{

    //create health for each enemy
    health = new Health(h,this);
    connect(health,SIGNAL(die()),this,SLOT(destroyEnemy()));
    connect(health,SIGNAL(die()),this,SLOT(increaseScore()));
}
