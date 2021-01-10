#include "Barrier.h"
#include "AlienBullet.h"
#include <QTimer>
Barrier::Barrier()
{
    durability = 5;
}

void Barrier::decreaseDurability(){
    durability--;
    if (durability==4)
    {
        setPixmap(QPixmap(":/img/barrier4.png"));

    }
    else if (durability==3)
    {
        setPixmap(QPixmap(":/img/barrier3.png"));

    }
    else if (durability==2)
    {
        setPixmap(QPixmap(":/img/barrier2.png"));

    }
    else if (durability==1)
    {
        setPixmap(QPixmap(":/img/barrier1.png"));

    }
    else if(durability==0)
    {
        delete this;
    }
}
