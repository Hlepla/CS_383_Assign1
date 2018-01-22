#include "ball.h"
#include "paddle.h"
#include "wall.h"
#include "opponent.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <typeinfo>

ball::ball()
{
  this->x = 0;
  this->y = 0;
  this->speed = 1;
  this->x_change = 1;
  this->y_change = 0;
}

QRectF ball::boundingRect()const
{
  return QRectF(-10/2,-10/2,10,10);
}

void ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
  painter->setBrush(Qt::black);
  painter->drawRect(QRectF(-10/2,-10/2,10,10));
}

void ball::reset()
{
  this->x=0;
  this->y=0;
  this->x_change = 1;
  this->y_change = ((qrand() %100) -50)/1500.0;
    setPos(x,y);
}

void ball::advance(int step)
{
  if(!step)
    return;

  QList<QGraphicsItem *> nearItem = collidingItems();
  foreach (QGraphicsItem *item, nearItem)
    {
      if(typeid(*item) == typeid(Paddle) || typeid(*item) == typeid(Opponent))
        {
          QPointF Cord = item->scenePos();
          float dis = Cord.y() - y;
          float cons = 0.015;
          y_change = y_change - (cons*dis);
          x_change = -x_change*1.1;
        }
      else
      y_change = -y_change;
      break;
    }
  x+=this->x_change*speed;
  y+=this->y_change*speed;
  setPos(x,y);
  update(); 
}
