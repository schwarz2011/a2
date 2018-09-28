#include "myrect.h"
#include "gegner.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "spiel.h"
#include <QGlobal.h>
#include <QTime>

extern Spiel * spiel;


MyRect::MyRect(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/player.png"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x()+100<800)
        setPos(x()+10,y());
    }
}

void MyRect::create()
{
    //gegner erzeugen

    int random_number=0;

    random_number= qrand() % 700+1;

    spiel->gegner=new Gegner(random_number,0);

    spiel->gegner->timerstart();

    scene()->addItem(spiel->gegner);

    spiel->punkte->count();

}
