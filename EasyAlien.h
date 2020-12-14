#ifndef EASYALIEN_H
#define EASYALIEN_H
#include "Alien.h"

class EasyAlien : public Alien {
        Q_OBJECT
    private:
        int id;
        int shotDamage;
        int points;

    public:
        EasyAlien();
        EasyAlien(int id, QPixmap pixmap);
        int getWidth(){return 34;}
        void dying();
        signals:
            void goodbye(int alienId);
};

#endif // EASYALIEN_H
