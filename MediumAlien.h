#ifndef MEDIUMALIEN_H
#define MEDIUMALIEN_H
#include "Alien.h"

class MediumAlien : public Alien {
        Q_OBJECT
    private:
        int id;
        int shotDamage;

    public:
        MediumAlien();
        MediumAlien(int id, QPixmap pixmap);
        int getWidth(){return 46;}
};

#endif // MEDIUMALIEN_H
