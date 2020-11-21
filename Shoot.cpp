#include "Shoot.h"
#include <QTimer>
#include <QGraphicsScene>
#include "Alien.h"
#include "Ship.h"



Shoot::Shoot(int x)
{
   this->xCoordinate = x;

   setPixmap(QPixmap(":/img/shoot.png"));
   setPos(this->xCoordinate, 500);
}


void Shoot::move(){
    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer,&QTimer::timeout,[=](){
        if(this->y() > 0){
            setPos(QPointF(getXCoordinate(), this->y()-1));
            checkForCollision();
        } else{
            delete this;
        }
    });
    shootTimer->start(3);
}

void Shoot::checkForCollision(){
    QList<QGraphicsItem *> collidingItems = this->collidingItems() ;

    foreach(QGraphicsItem *item, collidingItems)
    {
        Alien *alien = dynamic_cast<Alien *>(item);
        if (alien)
        {
            alien->dying();
            delete this;

        }
    }
}
