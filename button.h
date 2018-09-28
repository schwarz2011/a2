#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsRectItem
{
public:
    Button(QString name, QGraphicsItem *parent=0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsTextItem* text;
    int time=2000;
    int counterh=0;
    int counterl=0;
    int counterm=0;
};

#endif // BUTTON_H
