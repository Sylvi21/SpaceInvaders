#include "AlienBullet.h"
#include "Ship.h"
#include "Barrier.h"
AlienBullet::AlienBullet(int xCoordinate, QPixmap bulletImg){
    this->xCoordinate = xCoordinate;
    setPixmap(bulletImg);
};

void AlienBullet::move(){
    QTimer *bulletTimer = new QTimer(this);
    connect(bulletTimer,&QTimer::timeout,[=](){
        if(this->y() < scene()->height()){
            setPos(QPointF(getXCoordinate(), this->y()+1));
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

        if (ship)
        {
           // ship->decreaseHealth();
            delete this;

        }

        if(barrier)
        {
            delete this;
        }
    }
}

void AlienBullet::remove(){
    delete this;
}
