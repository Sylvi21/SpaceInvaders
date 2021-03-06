#include "Shoot.h"
#include <QDebug>
Shoot::Shoot(int x)
{
   this->xCoordinate = x;

   setPixmap(QPixmap(":/img/shoot.png"));
   setPos(this->xCoordinate, 720);
}

Shoot::~Shoot()
{
    delete shootTimer;
    shootTimer = NULL;
}

void Shoot::move(){
    QSound::play(":/sound/alien-shot.wav");
    shootTimer = new QTimer(this);
    connect(shootTimer,&QTimer::timeout,[=](){
        if(this->y() > 0){
            setPos(QPointF(getXCoordinate(), this->y()-1));
            checkForCollision();
        } else {
            delete this;
        }
    });
    shootTimer->start(2);
}

void Shoot::checkForCollision(){
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    if(!collidingItems.empty())
    {
        QGraphicsItem *item = collidingItems.front();
        Alien *alien = dynamic_cast<Alien *>(item);
        Barrier *barrier = dynamic_cast<Barrier *>(item);
        BossAlien *boss = dynamic_cast<BossAlien*>(item);
        if (alien)
        {
            QSound::play(":/sound/alien-hit.wav");
            shootTimer->stop();
            alien->dying();
            delete this;
        }
        if (barrier)
        {
            delete this;
        }
        if (boss)
        {
            boss->decreaseHP();
            delete this;
        }
    }
}
