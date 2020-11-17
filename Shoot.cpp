#include "shoot.h"
#include <QTimer>

Shoot::Shoot()
{
    setRect(0,0,10,30);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Shoot::move()
{
    setPos(x(),y()-10);
}
