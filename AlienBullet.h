#ifndef ALIENBULLET_H
#define ALIENBULLET_H
#include "Alien.h"
#include "AlienFlock.h"
#include "Ship.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>

class AlienBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    private:
        int xCoordinate;
    public:
        signals:
            void bullsEye(AlienBullet *alienBullet);
    public:
        AlienBullet(int xCoordinate, QPixmap bulletImg);
        void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;};
        int getXCoordinate(){return xCoordinate;};
        void move();
        void checkForCollision();
        void remove();
};

#endif // ALIENBULLET_H
