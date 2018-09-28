#include "gegner.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "spiel.h"
#include <stdlib.h> //rand()
//#include <time.h>
//#include <stdio.h>
#include <QGlobal.h>
#include <QTime>

extern Spiel *spiel;

Gegner::Gegner(int x, int y):QObject(), QGraphicsRectItem()
{
    setPos(x,y);
    setRect(0,0,100,100);

}

void Gegner::timerstart()
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Gegner::move()
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
