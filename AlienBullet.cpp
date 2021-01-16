#include "AlienBullet.h"

AlienBullet::AlienBullet(QPixmap bulletImg){
    setPixmap(bulletImg);
};

AlienBullet::~AlienBullet(){
    delete bulletTimer;
    bulletTimer = nullptr;
}

void AlienBullet::move(){
    QSound::play(":/sound/alien-shot.wav");
    bulletTimer = new QTimer(this);
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
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    if(!collidingItems.empty())
    {
        QGraphicsItem *item = collidingItems.front();
        Ship *ship= dynamic_cast<Ship *>(item);
        Barrier *barrier= dynamic_cast<Barrier *>(item);

        if (ship)
        {
            if(ship->shieldStatus()==0)
            {
                ship->decreaseHealth();
            }
            delete this;
        }

        if(barrier)
        {
            barrier->decreaseDurability();
            delete this;
        }
    }
}
