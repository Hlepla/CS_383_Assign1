#include "paddle.h"
#include "ball.h"
#include "opponent.h"
#include "mainwindow.h"
#include "wall.h"
#include "goal.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <math.h>
#include <QTimer>
#include <QTime>
#include <QWidget>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    qsrand(QTime::currentTime().msec()); // seed for random num generator

    QGraphicsScene scene;
    scene.setSceneRect(-300,-300,600,600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex); // ?
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing); // sets antialiasing
    view.setWindowTitle("CS383 Assgn_1");
    view.show();

    ball *b = new ball();
    Paddle *pointer1 = new Paddle(300,0); // set position of objects
    Opponent *pointer2 = new Opponent(300,0,b);
    Wall *T_w = new Wall(0,400);
    Wall *B_w = new Wall(0,-400);
    goal *l = new goal(800,10,300,600,b);
    goal *r = new goal(-500,10,300,600,b);
    pointer1->setFlag(QGraphicsItem::ItemIsFocusable);
    pointer1->QGraphicsItem::setFocus();

    scene.addItem(pointer1);
    scene.addItem(pointer2);
    scene.addItem(b);
    scene.addItem(T_w);
    scene.addItem(B_w);
    scene.addItem(l);
    scene.addItem(r);

    QTimer timer;
    QObject::connect(&timer,SIGNAL(timeout()),&scene, SLOT(advance())); // determines refresh rate
    timer.start(10); // 10 milisecs

    return a.exec();
}
