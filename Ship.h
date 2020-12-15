#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Ship:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int xCoordinate;
    int health;
    int weapon;
    int ammo;
public:
    Ship();
public:
    int getXCoordinate(){return this->xCoordinate;}
    void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;}
    void keyPressEvent(QKeyEvent *move);
    void decreaseHealth();
    void changeWeapon();
    void addShield();
};

#endif // SHIP_H
