#include "ShieldBuff.h"

ShieldBuff::ShieldBuff(int x, int y){
    this->setX(x);
    this->setY(y);
    setPixmap(QPixmap(":/img/shield-orb.png"));
}

ShieldBuff::~ShieldBuff(){}

void ShieldBuff::move(){
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

void ShieldBuff::checkForCollision(){
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    if(!collidingItems.empty())
    {
        QGraphicsItem *item = collidingItems.front();
        Ship *ship= dynamic_cast<Ship *>(item);
        if (ship)
        {
            ship->addShield();
            delete this;
        }
    }
}
