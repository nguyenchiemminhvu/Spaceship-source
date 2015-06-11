#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QObject>
#include <QPointF>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = 0);
    ~GraphicsScene();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
signals:
    void lastPosition(QPointF);
    void shoot();

public slots:

};

#endif // GRAPHICSSCENE_H
