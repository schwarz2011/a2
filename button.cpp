#include "button.h"
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include "spiel.h"
#include "newgegner.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QFile>
#include <QTextStream>

extern Spiel * spiel;

Button::Button(QString name,QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,50);

    text=new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().width()/2;
    text->setPos(xPos,yPos);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(text->toPlainText()=="Pause")
    {
        spiel->player->setFlag(QGraphicsItem::ItemIsFocusable,false);
        time=spiel->timer->remainingTime();
        if(time>1700 && time<2000)
        counterh++;
        if(time>1500 && time<1700)
        counterm++;
        if(time>900 && time<1500)
        counterl++;
        spiel->timer->stop();
        text->setPlainText(QString("Start"));
    }
   else if(text->toPlainText()=="Start")
   {
   spiel->player->setFlag(QGraphicsItem::ItemIsFocusable,true);
   spiel->player->setFocus();
   if(time<900)
   QTimer::singleShot(time,spiel->player,SLOT(create()));
   if(counterh>10)
   {
   QTimer::singleShot(300,spiel->player,SLOT(create()));
   counterh=0;
   }
   if(counterm>4)
   {
   QTimer::singleShot(500,spiel->player,SLOT(create()));
   counterm=0;
   }
   if(counterl>2)
   {
   QTimer::singleShot(500,spiel->player,SLOT(create()));
   counterl=0;
   }
   spiel->timer->start();

   text->setPlainText(QString("Pause"));
   }
   else if(text->toPlainText()=="Save")
    {
        spiel->saveItem = spiel->scene->items();
        QFile file("save.txt");
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << spiel->punkte->getPunktestand();
        foreach (QGraphicsItem *item, spiel->saveItem){

        out << ",";
        out << item->pos().x();
        out << ",";
        out << item->pos().y();

        }
        file.close();
        qDebug() << spiel->saveItem;
    }
    else if(text->toPlainText()=="Load")
    {
        spiel->timer->stop();
        spiel->button->text->setPlainText(QString("Start"));
        spiel->loadGame();
    }

}
