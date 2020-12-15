#include "Ship.h"
#include "Shoot.h"
#include "Shield.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>

Ship::Ship(){
    this->xCoordinate = 590;
    health = 5;
    weapon = 0;
    ammo = 0;
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
    else if(reaction->key() == Qt::Key_Space&&weapon==0)
    {
        Shoot *shoot = new Shoot(this->getXCoordinate());
        scene()->addItem(shoot);
        shoot->move();
    }
    else if(reaction->key() == Qt::Key_Space&&weapon==1)
    {
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
        Shield *shield = new Shield(this->getXCoordinate());
        scene()->addItem(shield);
        QTimer *shieldTimer = new QTimer(this);
        connect(shieldTimer,&QTimer::timeout,[=](){
            shield->decreaseDuration();
            if(shield->getDuration()>0)
            {
                shield->setXCoordinate(xCoordinate-35);
                shield->setPos(xCoordinate-35, 720);

            }

            });
        shieldTimer->start(1);
}

