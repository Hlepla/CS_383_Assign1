#include "paddle.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QKeyEvent>
#include <QWidget>

Paddle::Paddle(int x, int y)
{
  this->x = x;
  this->y = y;
  this->speed = 1;
  this->input = 0;
}

void Paddle::set_direction(int input)
{
  this->input = input;
}

int Paddle::get_direction()
{
  return this->input;
}

void Paddle::advance(int step)
{
  if(!step)
    return;

  //this->y += this->get_direction();
  setPos(QPointF(0,y-=10 *this->get_direction()));
  update();
  this->setFocus();
}

void Paddle::keyPressEvent(QKeyEvent *event)
{
  qDebug("test");
  switch(event->key())
    {
    case Qt::Key_Up:
      this->set_direction(1);
      break;

    case Qt::Key_Down:
      this->set_direction(-1);
      break;
    }
}

void Paddle::keyReleaseEvent(QKeyEvent *event)
{
  this->set_direction(0);
}
QRectF Paddle::boundingRect()const
{
  return QRectF(-10/2,-100/2,10,100);
}
void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
  painter->setBrush(Qt::black);
  painter->drawRect(QRectF(-10/2,-100/2,10,100));
}
