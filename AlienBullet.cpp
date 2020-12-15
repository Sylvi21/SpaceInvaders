#include "AlienBullet.h"
#include "Ship.h"
#include "Barrier.h"
#include "Shield.h"

AlienBullet::AlienBullet(QPixmap bulletImg){
    setPixmap(bulletImg);
};

void AlienBullet::move(){
    QTimer *bulletTimer = new QTimer(this);
    connect(bulletTimer,&QTimer::timeout,[=](){
        if(this->y() < scene()->height()){
            setPos(QPointF(this->x(), this->y()+1));
            checkForCollision();
        } else{
            delete this;
        }
    });
    bulletTimer->start(5);
}

void AlienBullet::checkForCollision(){
    QList<QGraphicsItem *> collidingItems = this->collidingItems() ;

    foreach(QGraphicsItem *item, collidingItems)
    {
        Ship *ship= dynamic_cast<Ship *>(item);
        Barrier *barrier= dynamic_cast<Barrier *>(item);
        Shield *shield= dynamic_cast<Shield *>(item);

        if (ship)
        {
            ship->decreaseHealth();
            delete this;

        }
        if (shield)
        {
            delete this;
        }

        if(barrier)
        {
            barrier->decreaseDurability();
            delete this;
        }
    }
}

void AlienBullet::remove(){
    delete this;
}
