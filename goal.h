#ifndef GOAL_H
#define GOAL_H
#include "ball.h"
#include <QGraphicsObject>

class goal : public QGraphicsObject
{
 public:
  goal(int x,int y,int width,int height, ball *b);
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
 private:
  int x;
  int y;
  int width;
  int height;
  ball *detect_ball;

 protected:
  void advance(int step);
};

#endif
