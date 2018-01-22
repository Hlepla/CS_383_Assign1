
#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>
#include <QWidget>

class Paddle : public QGraphicsItem
{
 public:
  Paddle(int x, int y);
  void set_direction(int input);
  int get_direction();
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);


 protected:
    void advance(int step);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

 private:
    float x;
    float y;
    float speed;
    int input;
};

#endif // PADDLE_,
