#ifndef SPIEL_H
#define SPIEL_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Punkte.h"
#include "myrect.h"
#include "leben.h"
#include "button.h"
#include <QTimer>
#include <gegner.h>


class Spiel:public QGraphicsView
{
public:
    Spiel(QWidget *parent=0);
    void loadGame();

    QGraphicsScene * scene;
    MyRect * player;
    Punkte * punkte;
    Leben * leben;
    QTimer * timer;
    Button * button;
    Button * loade;
    Button * save;
    QList<QGraphicsItem*> allItems;
    QList<QGraphicsItem*> saveItem;
    Gegner *gegner;

};

#endif // SPIEL_H
