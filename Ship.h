#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QSound>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>
#include "Shoot.h"

class Ship:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int xCoordinate;
    int health;
    int life;
    int weapon;
    int reload;
    int ammo;
    int shieldMode;
    int shieldDuration;
    QTimer *reloadTimer;
public:
    Ship();
    ~Ship();
    int getXCoordinate(){return this->xCoordinate;}
    void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;}
    void keyPressEvent(QKeyEvent *move);
    void decreaseHealth();
    void changeWeapon();
    void addShield();
    int shieldStatus();
    void reloadWeapon();
    int showHealth();
    int showLife();

};

#endif // SHIP_H
