#include "ship.h"
#include "shoot.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Ship::keyPressEvent(QKeyEvent *reaction)
{


    if(reaction->key() == Qt::Key_Left)
    {
        setPos(x()-30,y());
    }
    else if (reaction->key() == Qt::Key_Right)
    {
        setPos(x()+30,y());
    }
    else if(reaction->key() == Qt::Key_Space)
    {
        Shoot * shoot = new Shoot();
        shoot->setPos(x()+45,y());
        scene()->addItem(shoot);
       }

}
