#include "goal.h"
#include "ball.h"
#include <QRectF>
#include <QPainter>
#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QApplication>
#include <QGraphicsScene>
#include <typeinfo>
#include <QKeyEvent>

goal::goal(int x,int y,int w, int h, ball *b)
{
  this->x = x;
  this->y = y;
  this->width = w;
  this->height = h;
  this->detect_ball = b;
  setPos(x,y);
}

QRectF goal::boundingRect() const
{
  return QRectF(-300,-600,300,900);
}

void goal::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
  painter->setPen(Qt::white);
  painter->setBrush(Qt::white);
  painter->drawRect(QRectF(-300,-600,300,900));
}

void goal::advance(int step)
{
  if(!step)
    return;

  QList<QGraphicsItem *> nearItems = collidingItems();
  foreach (QGraphicsItem *item, nearItems) {
    if (typeid(*item) == typeid(ball)) {
      detect_ball->reset();
    }
  }
  setPos(x, y);
  update();
}
