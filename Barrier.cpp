#include "Barrier.h"
#include "AlienBullet.h"
#include <QTimer>
Barrier::Barrier()
{
    durability = 5;
}

void Barrier::decreaseDurability(){
    durability--;
    if(durability==0)
    {
        delete this;
    }
}
