#ifndef MEDIUMALIEN_H
#define MEDIUMALIEN_H
#include "Alien.h"

class MediumAlien : public Alien {
        Q_OBJECT
    private:
        int id;
        int shotDamage;
        int points;

    public:
        MediumAlien();
        MediumAlien(int id);
        int getWidth(){return 46;}
        void dying();
        signals:
            void goodbye(int alienId);
};

#endif // MEDIUMALIEN_H
