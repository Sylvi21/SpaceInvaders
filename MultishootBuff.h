#ifndef MULTISHOOTBUFF_H
#define MULTISHOOTBUFF_H
<<<<<<< HEAD
//#include "Buff.h"
=======
#include "Buff.h"
>>>>>>> 30a0d2d6c1bed7f8d2acdae491f42806b76bae7a
#include "Ship.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>

class MultishootBuff : public QObject, public QGraphicsPixmapItem{
       Q_OBJECT
       private:
           QPixmap image;
       public:
           MultishootBuff(int x, int y);
           ~MultishootBuff();

           void move();
           void checkForCollision();
};

#endif // MULTISHOOTBUFF_H

