#include "upgradeweapon.h"

UpgradeWeapon::UpgradeWeapon(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    setRect(rand()%430 + 10, 0, 50, 50);

    setUpTimer();
    setUpChecker();
}

UpgradeWeapon::~UpgradeWeapon()
{
}

QRectF UpgradeWeapon::boundingRect() const
{
    return rect();
}

void UpgradeWeapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->drawPixmap(option->rect,QPixmap(":/images/upgrade.jpg"));
}

void UpgradeWeapon::move()
{
    setPos(pos().x(), pos().y() + 10);

    if(pos().y() + rect().height() >= 600)
        deleteUpgrade();
}

void UpgradeWeapon::stop()
{
    timer->stop();
}

void UpgradeWeapon::keepMoving()
{
    timer->start(90);
}

void UpgradeWeapon::checkCollides()
{
    if(collidesWithItem(scene()->focusItem()))  {

        deleteUpgrade();
        emit upgrade();
    }
}

void UpgradeWeapon::deleteUpgrade()
{
    this->deleteLater();
    emit deleted();
}

void UpgradeWeapon::setUpTimer()
{
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(90);
}

void UpgradeWeapon::setUpChecker()
{
    check = new QTimer(this);

    connect(check,SIGNAL(timeout()),this,SLOT(checkCollides()));
    check->start(10);
}
