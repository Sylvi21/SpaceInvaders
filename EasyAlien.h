#ifndef EASYALIEN_H
#define EASYALIEN_H
#include "Alien.h"

class EasyAlien : public Alien {
        Q_OBJECT
    private:
        int id;
        int shotDamage;
        int points;
        AnimationState state;
    public:
        EasyAlien();
        EasyAlien(int id);
        int getWidth(){return 34;}
        void dying();
        void animate();
        signals:
            void goodbye(int alienId);
};

#endif // EASYALIEN_H
