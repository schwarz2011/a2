#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>


class MyRect:public QObject, public QGraphicsPixmapItem{
      Q_OBJECT
public:
     MyRect(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void create();
};

#endif // MYRECT_H
