#ifndef SHIELDBUFF_H
#define SHIELDBUFF_H
//#include "Buff.h"
#include "Ship.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>

class ShieldBuff : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    private:
        QPixmap image;
        QTimer *shieldTimer;
    public:
        ShieldBuff(int x, int y);
        ~ShieldBuff();
        void move();
};

#endif // SHIELDBUFF_H
