#ifndef HARDALIEN_H
#define HARDALIEN_H
#include "Alien.h"

class HardAlien : public Alien {
        Q_OBJECT
    private:
        int id;
        int shotDamage;

    public:
        HardAlien();
        HardAlien(int id, QPixmap pixmap);
        int getWidth(){return 50;}
};
#endif // HARDALIEN_H
