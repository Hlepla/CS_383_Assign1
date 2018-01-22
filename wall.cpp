#include "wall.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsScene>
#include <typeinfo>

Wall::Wall(int pos_x,int pos_y)
{
  this->x = pos_x;
  this->y = pos_y;
  setPos(x,y);
}

QRectF Wall::boundingRect() const
{
  return QRectF(-500,-100,1000,10);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
  painter->setBrush(Qt::black);
  painter->drawRect(QRectF(-500,-100,1000,10));
}

