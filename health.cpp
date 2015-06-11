#include "health.h"

Health::Health(int h, QObject *parent) :
    QObject(parent)
{
    health = h;
    health_before = h;
}

Health::~Health()
{
    this->deleteLater();
}

int Health::getHealth()
{
    return health;
}

int Health::getHealthBefore()
{
    return health_before;
}

void Health::setHealth(int h)
{
    health = h;
}

void Health::decreaseHealth(int damage)
{
    health -= damage;

    if(health <= 0)
        emit die();
}
