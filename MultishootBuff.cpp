#include "MultishootBuff.h"

MultishootBuff::MultishootBuff(int x, int y){
    this->setX(x);
    this->setY(y);
    setPixmap(QPixmap(":/img/ms-orb.png"));
}

MultishootBuff::~MultishootBuff(){}

void MultishootBuff::move(){
    QTimer *shieldTimer = new QTimer(this);
    connect(shieldTimer,&QTimer::timeout,[=](){
        if(this->y() < scene()->height()){
            setPos(QPointF(this->x(), this->y()+1));
            checkForCollision();
        } else{
            delete this;
        }
    });
    shieldTimer->start(5);
}

void MultishootBuff::checkForCollision(){
    QList<QGraphicsItem *> collidingItems = this->collidingItems() ;

    foreach(QGraphicsItem *item, collidingItems)
    {
        Ship *ship= dynamic_cast<Ship *>(item);
        if (ship)
        {
           // ship->addShield();
            delete this;
        }
    }
}
