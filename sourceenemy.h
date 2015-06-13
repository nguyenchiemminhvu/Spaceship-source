#ifndef SOURCEENEMY_H
#define SOURCEENEMY_H

#include <QObject>

class SourceEnemy : public QObject
{
    Q_OBJECT
public:
    explicit SourceEnemy(int num = 50,QObject *parent = 0);
    ~SourceEnemy();

signals:
    void outOfEnemy();

public slots:
    void decreaseNumOfEnemy();

private:
    int num_of_enemy;
};

#endif // SOURCEENEMY_H
