#include "Ship.h"
#include "Shoot.h"
#include <QKeyEvent>
#include <QGraphicsScene>
Ship::Ship(){
    this->xCoordinate = 300;
}

void Ship::keyPressEvent(QKeyEvent *reaction)
{
    if(reaction->key() == Qt::Key_Left&&x()-20>0)
    {
        setPos(x()-30,y());
    }
    else if (reaction->key() == Qt::Key_Right&&x()+120<800)
    {
        setPos(x()+30,y());
    }
    else if(reaction->key() == Qt::Key_Space)
    {
        Shoot *shoot = new Shoot(this->getXCoordinate());
        scene()->addItem(shoot);
        shoot->move();
    }

}

