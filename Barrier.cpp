#include "Barrier.h"
#include "AlienBullet.h"
#include <QTimer>
#include <QDebug>
Barrier::Barrier()
{
    durability = 5;
}

void Barrier::decreaseDurability(){
    durability--;
    qDebug()<<"decreased";
    if(durability==0)
    {
        delete this;
    }
}
