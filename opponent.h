#ifndef OPPONENT_H
#define OPPONENT_H
#include "ball.h"
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>
#include <QWidget>
#include <QTime>

class Opponent : public ball
{
public:
Opponent(int x, int y, QGraphicsItem *track);
void AI();
QRectF boundingRect() const;
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
protected:
void advance(int step);
private:
int x_cord;
int y_cord;
QGraphicsItem *track;
QTime *timer;
int speed;

};

#endif //OPPONENT_H
