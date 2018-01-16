
#ifndef BALL_H
#define BALL_H
#include <QGraphicsItem>

class ball : public QGraphicsItem
{
 public:
  ball();
  void Movement(int x,int y, int speed);
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *opt,
             QWidget *widget);

 private:
  int x;
  int y;
  int speed;

 protected:
  void advance(int step);
};

#endif
