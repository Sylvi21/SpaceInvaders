#include "Ship.h"
#include "Shoot.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>

Ship::Ship(){
    this->xCoordinate = 390;
    health = 3;
    weapon = 0;
    shield = 0;
}

void Ship::keyPressEvent(QKeyEvent *reaction)
{
    if(reaction->key() == Qt::Key_Left&&x()-20>0)
    {
        setPos(x()-30,y());
        this->xCoordinate=xCoordinate-30;

    }
    else if (reaction->key() == Qt::Key_Right&&x()+80<800)
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
        Shoot *shoot = new Shoot(this->getXCoordinate());
        Shoot *shoot2 = new Shoot(this->getXCoordinate()+30);
        Shoot *shoot3 = new Shoot(this->getXCoordinate()-30);
        scene()->addItem(shoot);
        shoot->move();
        scene()->addItem(shoot2);
        shoot2->move();
        scene()->addItem(shoot3);
        shoot3->move();
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
}

void Ship::addShield(){

}
