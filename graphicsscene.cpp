#include "graphicsscene.h"

GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

GraphicsScene::~GraphicsScene()
{
    this->deleteLater();
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //check if user move the mouse over the scene
    if(event->lastScenePos().x() > 15 && event->lastScenePos().x() < 485 && event->lastScenePos().y() > 15 && event->lastScenePos().y() < 585)
        emit lastPosition(event->lastScenePos());
}
