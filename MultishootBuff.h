#ifndef MULTISHOOTBUFF_H
#define MULTISHOOTBUFF_H
#include "Buff.h"
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

