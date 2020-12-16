#include "Ship.h"
#include "Shoot.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>



Ship::Ship(){
    this->xCoordinate = 590;
    health = 3;
    weapon = 0;
    reload = 0;
    ammo = 0;
    shieldMode = 0;
    shieldDuration = 0;
}

void Ship::keyPressEvent(QKeyEvent *reaction)
{
    if(reaction->key() == Qt::Key_Left&&x()-20>0)
    {
        setPos(x()-30,y());
        this->xCoordinate=xCoordinate-30;

    }
    else if (reaction->key() == Qt::Key_Right&&x()+80<1200)
    {
        setPos(x()+30,y());
        this->xCoordinate=xCoordinate+30;

    }
    else if(reaction->key() == Qt::Key_Space&&weapon==0&&reload==0)
    {
        reload = 1;
        QTimer *reloadTimer = new QTimer();
        connect(reloadTimer,&QTimer::timeout,[=](){
        reload = 0;
        reloadTimer->stop();
        });
        reloadTimer->start(500);
        Shoot *shoot = new Shoot(this->getXCoordinate());
        scene()->addItem(shoot);
        shoot->move();
    }
    else if(reaction->key() == Qt::Key_Space&&weapon==1&&reload==0)
    {
        reload = 1;
        QTimer *reloadTimer = new QTimer();
        connect(reloadTimer,&QTimer::timeout,[=](){
        reload = 0;
        reloadTimer->stop();
        });
        reloadTimer->start(500);
        if (ammo>0)
        {
        Shoot *shoot = new Shoot(this->getXCoordinate());
        Shoot *shoot2 = new Shoot(this->getXCoordinate()+30);
        Shoot *shoot3 = new Shoot(this->getXCoordinate()-30);
        scene()->addItem(shoot);
        shoot->move();
        scene()->addItem(shoot2);
        shoot2->move();
        scene()->addItem(shoot3);
        shoot3->move();
        ammo--;
        }
        else if (ammo == 0) weapon=0;
    }

}

void Ship::decreaseHealth(){
    health--;
        if(health==0)
        {
            delete this;
        }
}


void Ship::changeWeapon(){
        weapon = 1;
        ammo = ammo+5;
}



void Ship::addShield(){
       if(shieldMode == 0)
       {
       shieldDuration = shieldDuration + 3000;
       setPixmap(QPixmap(":/img/shield.png"));
       shieldMode=1;
       QTimer *shieldTimer = new QTimer();
       connect(shieldTimer,&QTimer::timeout,[=](){
       shieldDuration = shieldDuration - 1000;
       if(shieldDuration == 0)
       {
       shieldTimer->stop();
       setPixmap(QPixmap(":/img/spaceship.png"));
       shieldMode = 0;
       }
       });
       shieldTimer->start(1000);
       }
       else if(shieldMode == 1)
       {
           shieldDuration = shieldDuration + 3000;
       }
}

int Ship::shieldStatus(){
return shieldMode;
}



