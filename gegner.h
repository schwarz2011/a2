#ifndef GEGNER_H
#define GEGNER_H

#include <QGraphicsRectItem>
#include <QObject>

class Gegner: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Gegner(int x,int y);
    void timerstart();
public slots:
    void move();

};

#endif // GEGNER_H
