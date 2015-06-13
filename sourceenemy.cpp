#include "sourceenemy.h"

SourceEnemy::SourceEnemy(int num, QObject *parent)
    : QObject(parent)
{
    num_of_enemy = num;
}

SourceEnemy::~SourceEnemy()
{
    this->deleteLater();
}

void SourceEnemy::decreaseNumOfEnemy()
{
    if(num_of_enemy > 1)
    {
        num_of_enemy--;
    }
    else
    {
        emit outOfEnemy();
    }
}

