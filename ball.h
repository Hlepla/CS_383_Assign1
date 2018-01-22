
#ifndef BALL_H
#define BALL_H
#include <QGraphicsItem>

class ball : public QGraphicsItem
{

 public:
float x;
float y;
ball();
void reset();
void Movement(QGraphicsItem *item);
QRectF boundingRect() const;
void paint(QPainter *painter, const QStyleOptionGraphicsItem *opt,
             QWidget *widget);


private:
float speed;
float x_change;
float y_change;
protected:
void advance(int step);

};

#endif
