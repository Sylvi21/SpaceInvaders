#ifndef ALIENBULLET_H
#define ALIENBULLET_H
#include "Alien.h"
#include "Ship.h"
#include "Barrier.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>

class AlienBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    public:
        AlienBullet(QPixmap bulletImg);
        void move();
        void checkForCollision();
        void remove();
};

#endif // ALIENBULLET_H
