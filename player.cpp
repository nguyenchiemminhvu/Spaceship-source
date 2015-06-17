#include "player.h"

Player::Player(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    //initialize
    setRect(0,0,50,50);
    score = new Score();
    emp = new CountEMP();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));

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

void Player::addCounterEMP()
{
    scene()->addItem(emp);
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

        Bullet3* bullet = new Bullet3();

        //set the position of bullet center of player character
        bullet->setPos(pos().x() + 20,y());
        scene()->addItem(bullet);
    }
}

void Player::toggleEMP()
{
    if(emp->getNumOfEMP() > 0)  {

        EMP* new_emp = new EMP(QPointF(pos().x() + 25, pos().y() + 25));
        connect(new_emp,SIGNAL(killAnEnemy()),this,SLOT(killAnEnemy()));
        scene()->addItem(new_emp);
        emp->decreaseEMP();
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

void Player::LevelUp()
{

}
