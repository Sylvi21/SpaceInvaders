#include "Shoot.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Alien.h"
Shoot::Shoot()
{
   setPixmap(QPixmap(":/img/shoot.png"));
   QTimer *timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()),this,SLOT(move()));
   timer->start(2);
   if ( y() + 100 < 0 )
   {
    timer->stop();
    scene()->removeItem(this);
    this->deleteLater();
   }
}

void Shoot::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n;i++)
    {
        if(typeid(*(colliding_items[i]))== typeid(Alien))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
   setPos(x(),y()-1);
   if(pos().y()<0)
   {
       scene()->removeItem(this);
       delete this;
   }

}
