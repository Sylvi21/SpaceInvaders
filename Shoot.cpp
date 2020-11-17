#include "Shoot.h"
#include <QTimer>
#include <QGraphicsScene>
Shoot::Shoot()
{
   setPixmap(QPixmap(":/img/shoot.png"));
   QTimer * timer = new QTimer(this);

   connect(timer, SIGNAL(timeout()),this,SLOT(move()));
   timer->start(1);
   if ( y() + 100 < 0 )
   {
  timer->stop();
  scene()->removeItem(this);
  this->deleteLater();
   }
}

void Shoot::move()
{

   setPos(x(),y()-1);
   if(pos().y()<0)
   {
       scene()->removeItem(this);
       delete this;
   }
}
