#include "spiel.h"
#include <QGraphicsTextItem>
#include "gegner.h"
#include <QFont>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QListWidget>
#include <QList>

Spiel::Spiel(QWidget *parent)
{
    //Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,798,598);


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Leben
    leben = new Leben();
    leben->setPos(leben->x()+650,leben->y());
    scene->addItem(leben);


    //Player
    player = new MyRect();
    player->setPos(400,495);
    scene->addItem(player);    
    player->setFlag(QGraphicsItem::ItemIsFocusable,false);
    //player->setFocus();
    //player->setFlag(QGraphicsItem::ItemIsFocusable,false);


    //Punktestand
    punkte = new Punkte();
    scene->addItem(punkte);

    //Start/Pause Button
    button = new Button(QString("Start"));
    button->setPos(0,550);
    scene->addItem(button);

    //Load Button
    loade = new Button(QString("Load"));
    loade->setPos(700,550);
    scene->addItem(loade);

    //Save Button
    save = new Button(QString("Save"));
    save->setPos(700,500);
    scene->addItem(save);

    //Gegner
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(create()));
    timer->setInterval(2000);

    //Show
    show();
}

void Spiel::loadGame()
{

    allItems = scene->items();
    for (int i = 0; i < allItems.size()-9; i++)
    {
        QGraphicsItem *item = allItems[i];
        scene->removeItem(item);
        delete item;
}

    QString s;
    QFile file("save.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream out(&file);
    out >> s;
    QStringList strlist=s.split(",",QString::SkipEmptyParts);

    file.close();

        int i=0;

        punkte->setPunktestand(strlist[0].toInt());

        for(int i = 1; i < strlist.size()-18; i++){

        if(i==1)
        {
        gegner = new Gegner(strlist[i].toInt(),strlist[i+1].toInt());
        gegner->timerstart();
        scene->addItem(gegner);
       }
       else if(i==3)
       {
            gegner = new Gegner(strlist[i].toInt(),strlist[i+1].toInt());
            gegner->timerstart();
            scene->addItem(gegner);
        }
       else if(i==5)
        {
            gegner= new Gegner(strlist[i].toInt(),strlist[i+1].toInt());
            gegner->timerstart();
            scene->addItem(gegner);
        }
        else if(i==7)
        {
            gegner = new Gegner(strlist[i].toInt(),strlist[i+1].toInt());
            gegner->timerstart();
            scene->addItem(gegner);
        }
        else if(i==9)
        {
            gegner = new Gegner(strlist[i].toInt(),strlist[i+1].toInt());
            gegner->timerstart();
            scene->addItem(gegner);
        }
        else if(i==11)
        {
            gegner = new Gegner(strlist[i].toInt(),strlist[i+1].toInt());
            gegner->timerstart();
            scene->addItem(gegner);
            break;
        }
        i++;

        }

        for(int i = strlist.size()-1; i > 0; i--){

        if(i==strlist.size()-3){
        player->setPos(strlist[i-1].toInt(),strlist[i].toInt());
        break;
        }
        }

}
