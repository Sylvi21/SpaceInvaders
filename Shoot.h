#ifndef SHOOT_H
#define SHOOT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QSound>
#include "Alien.h"
#include "Barrier.h"
#include "BossAlien.h"

class Shoot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int xCoordinate;
    QTimer *shootTimer;
public:
    Shoot(int x);
    ~Shoot();
    void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;};
    int getXCoordinate(){return xCoordinate;};
    void move();
    void checkForCollision();
};

#endif // SHOOT_H
