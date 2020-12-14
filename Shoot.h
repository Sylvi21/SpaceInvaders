#ifndef SHOOT_H
#define SHOOT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Score.h"

class Shoot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int xCoordinate;
public:
    Shoot(int x);
    void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;};
    int getXCoordinate(){return xCoordinate;};
    void move();
    void checkForCollision();
};

#endif // SHOOT_H
