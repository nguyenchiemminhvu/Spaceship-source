#ifndef WARNING_H
#define WARNING_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class Warning : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Warning(QString warning = "", QGraphicsItem *parent = 0);
    ~Warning();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void changeState();

private:
    QString warning;
    bool state;

    QTimer* timer;
};

#endif // WARNING_H
