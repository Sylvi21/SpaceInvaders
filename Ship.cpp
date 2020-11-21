#include "Ship.h"
#include "Shoot.h"
#include <QKeyEvent>
#include <QGraphicsScene>
Ship::Ship(){
    this->xCoordinate = 390;
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
    else if(reaction->key() == Qt::Key_Space)
    {
        Shoot *shoot = new Shoot(this->getXCoordinate());
        scene()->addItem(shoot);
        shoot->move();
    }

}
