#include "ball.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QApplication>
#include <QKeyEvent>

ball::ball()
{
  this->x = 0;
  this->y = 0;
  this->speed = 1;
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

//void ball::Movement(int x, int y, int speed)
//{
  // nothing for now
//}

void ball::advance(int step)
{}
