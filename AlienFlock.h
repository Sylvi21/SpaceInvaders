#ifndef ALIENFLOCK_H
#define ALIENFLOCK_H
#include "Alien.h"
#include <QGraphicsItemGroup>

class AlienFlock : QGraphicsItemGroup {
private:
    Alien* flock[32];
public:
    AlienFlock(){
        createAliens();
    };
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void createAliens();
    void move();
    void shoot(int id);
    void remove(Alien* alien);
};

#endif // ALIENFLOCK_H
