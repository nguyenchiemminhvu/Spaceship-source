#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>

class Health : public QObject
{
    Q_OBJECT
public:
    explicit Health(int h = 1, QObject *parent = 0);
    ~Health();

    int getHealth();
    int getHealthBefore();
    void setHealth(int h = 1);

signals:
    void die();

public slots:
    void decreaseHealth(int damage = 1);
    void decreaseHealth2(int damage = 2);
    void decreaseHealth3(int damage = 3);

private:
    int health;
    int health_before;
};

#endif // HEALTH_H
