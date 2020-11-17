#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Ship:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ship(QGraphicsItem * parent=0);
public:
    void keyPressEvent(QKeyEvent *move);
};

#endif // SHIP_H
