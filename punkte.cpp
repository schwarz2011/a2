#include "punkte.h"
#include <QFont>
#include <QTimer>

Punkte::Punkte(QGraphicsItem *parten): QGraphicsTextItem()
{
  //initialisierung
  Punktestand =0;

  //text anzeigen
  setPlainText(QString("Punkte:")+ QString::number(Punktestand));
  setFont(QFont(("times"),16));
}

void Punkte::count()
{
    Punktestand++;
    setPlainText(QString("Punkte:")+ QString::number(Punktestand));
}

int Punkte::getPunktestand()
{
    return this->Punktestand;
}

void Punkte::setPunktestand(int Punkte)
{
  Punktestand=Punkte;
  setPlainText(QString("Punkte:")+ QString::number(Punkte));
}

