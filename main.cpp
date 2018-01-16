#include "paddle.h"
#include "ball.h"
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <math.h>
#include <QTimer>
#include <QTime>
#include <QWidget>


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    qsrand(QTime::currentTime().msec()); // seed for random num generator

    QGraphicsScene scene;
    scene.setSceneRect(-300,-300,600,600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex); // ? we dont know

    QGraphicsView view(&scene); // not sure what this does rn
    view.setRenderHint(QPainter::Antialiasing); // sets antialiasing
    view.setWindowTitle("CS383 Assgn_1");
    view.show();

    Paddle *pointer1= new Paddle(-10,0);
    ball *b = new ball;

    pointer1->setFlag(QGraphicsItem::ItemIsFocusable);
    pointer1->QGraphicsItem::setFocus();

    scene.addItem(pointer1);
    scene.addItem(b);

    QTimer timer;
    QObject::connect(&timer,SIGNAL(timeout()),&scene, SLOT(advance())); // determines refresh rate
    timer.start(10); // 10 milisecs

    return a.exec();
}
