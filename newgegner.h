#ifndef NEWGEGNER_H
#define NEWGEGNER_H


#include <QGraphicsRectItem>
#include <QObject>

class Newgegner: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Newgegner(QPointF pos);
public slots:
    void move();

};
#endif // NEWGEGNER_H
