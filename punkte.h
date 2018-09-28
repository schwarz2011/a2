#ifndef PUNKTE_H
#define PUNKTE_H
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QObject>

class Punkte: public QGraphicsTextItem
{

public:
    Punkte(QGraphicsItem * parent=0);
    void count();
    int getPunktestand();
    void setPunktestand(int Punkte);
private:
    int Punktestand;

};


#endif // PUNKTE_H
