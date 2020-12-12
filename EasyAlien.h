#ifndef EASYALIEN_H
#define EASYALIEN_H
#include "Alien.h"

class EasyAlien : public Alien {
        Q_OBJECT
    private:
        int id;
        int shotDamage;

    public:
        EasyAlien();
        EasyAlien(int id, QPixmap pixmap);
        int getWidth(){return 34;}
};

#endif // EASYALIEN_H
