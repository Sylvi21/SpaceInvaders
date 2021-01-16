#ifndef BOSSALIEN_H
#define BOSSALIEN_H
#include <QGraphicsScene>
#include <QTimer>
#include "Alien.h"
#include "AlienBullet.h"

class BossAlien : public QObject, public QGraphicsPixmapItem {
        Q_OBJECT
    private:
        QTimer *ufoShootTimer;
        QTimer *ufoMoveTimer;
        int shotDamage;
        int HP;
        int points;
        int dir;
    public:
        BossAlien();
        ~BossAlien();
        int getHP();
        void setHP(int HP);
        void move();
        void dying();
        void attack();
        void decreaseHP();
        signals:
            void goodbye(int alienId);
};
#endif // BOSSALIEN_H
