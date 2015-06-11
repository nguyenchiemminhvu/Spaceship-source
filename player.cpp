#include "player.h"

Player::Player(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    //initialize
    setRect(0,0,50,50);
    score = new Score();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));

    num_of_EMP = 3;
    isPaused = false;
}

Player::~Player()
{
    this->deleteLater();
}

void Player::addScoreToScene()
{
    scene()->addItem(score);
}

QRectF Player::boundingRect() const
{
    return rect();
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->drawRect(boundingRect());
    painter->drawPixmap(option->rect,QPixmap(":/images/spaceship.jpg"));
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        shoot();
        timer->start(200);
    }
    else if(event->button() == Qt::RightButton)
    {
        toggleEMP();
    }
}

void Player::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    timer->stop();
}

void Player::shoot()
{
    if(isPaused == false)   {

        Bullet* bullet = new Bullet();

        //set the position of bullet center of player character
        bullet->setPos(pos().x() + 20,y());
        scene()->addItem(bullet);
    }
}

void Player::toggleEMP()
{
    if(num_of_EMP > 0)  {

        EMP* emp = new EMP(QPointF(pos().x() + 25, pos().y() + 25));
        connect(emp,SIGNAL(killAnEnemy()),this,SLOT(killAnEnemy()));
        scene()->addItem(emp);
        num_of_EMP--;
    }
}

void Player::moveToPosition(QPointF position)
{
    //if the game is pause, user can't move the character
    if(isPaused == false)   {

        setPos(position.x() - rect().width() / 2, position.y() - rect().height() / 2);
    }
}

void Player::killAnEnemy()
{
    score->increaseScore();
}

void Player::onEnemyPassTheDefense()
{
    score->decreaseScore();
}

void Player::spawnEnemy()
{
    Enemy* son_of_a_bitch = new Enemy(3);
    connect(son_of_a_bitch,SIGNAL(enemyPassTheDefense()),this,SLOT(onEnemyPassTheDefense()));
    connect(son_of_a_bitch,SIGNAL(getScore()),this,SLOT(killAnEnemy()));
    connect(this,SIGNAL(pause()),son_of_a_bitch,SLOT(stopMoving()));
    connect(this,SIGNAL(resume()),son_of_a_bitch,SLOT(keepMoving()));

    scene()->addItem(son_of_a_bitch);
}

void Player::onPause()
{
    isPaused = true;
    emit pause();
}

void Player::onResume()
{
    isPaused = false;
    emit resume();
}
