#ifndef WALL_H
#define WALL_H
#include <QGraphicsObject>
#include <QKeyEvent>
#include <QObject>
#include <QWidget>

class Wall : public QGraphicsObject
{
 public:
  Wall(int pos_x, int pos_y);
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
 private:
  int x;
  int y;
};

#endif
