#include "newgegner.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "spiel.h"
#include <stdlib.h> //rand()

extern Spiel *spiel;

Newgegner::Newgegner(QPointF pos):QObject(), QGraphicsRectItem()
{
    //random Position
    //int random_number = rand() % 700;
    setPos(pos);


    //draw

    setRect(0,0,100,100);


    //connect

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

void Newgegner::move()
{
    if(spiel->timer->isActive())
    {
    setPos(x(),y()+5);
    if(pos().y() > 598){
        scene()->removeItem(this);
        delete this;

    }

  }
}
