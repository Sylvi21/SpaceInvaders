#include "Shoot.h"
#include <QTimer>
#include "mainWindow.h"
#include "Alien.h"
#include "Barrier.h"
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
    shootTimer->start(2);
}

void Shoot::checkForCollision(){
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    foreach(QGraphicsItem *item, collidingItems)
    {
        Alien *alien = dynamic_cast<Alien *>(item);
        Barrier *barrier = dynamic_cast<Barrier *>(item);
        if (alien)
        {
            alien->dying();
            delete this;
        }
        if(barrier)
        {
            delete this;
        }
    }
}
