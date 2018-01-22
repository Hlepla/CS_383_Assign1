#include "opponent.h"
#include "ball.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QKeyEvent>
#include <QWidget>
#include <QDebug>

Opponent::Opponent(int org_x, int org_y, QGraphicsItem *track)
{
  this->x_cord = org_x;
  this->y_cord = org_y;
  this->speed = 0;
  this->track = track;
}

void Opponent::advance(int step)
{
  ball derived_cordx,derived_cordy;

  if(!step)
    return;

  float ball_y = track->scenePos().y();
  setPos(QPointF(-x_cord,ball_y));
  update();
}

QRectF Opponent::boundingRect()const
{
  return QRectF(-10/2,-100/2,10,100);
}

void Opponent::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
  painter->setBrush(Qt::black);
  painter->drawRect(QRectF(-10/2,-100/2,10,100));
}
