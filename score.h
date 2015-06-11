#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QFont>
#include <QStyleOptionGraphicsItem>

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Score(QGraphicsItem* parent = 0);
    ~Score();
    int getScore();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void increaseScore(int s = 1);
    void decreaseScore(int s = 5);

private:
    int score;
};

#endif // SCORE_H
