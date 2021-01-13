#ifndef HARDALIEN_H
#define HARDALIEN_H
#include "Alien.h"

class HardAlien : public Alien {
    Q_OBJECT
    private:
        int id;
        int shotDamage;
        int points;
        AnimationState state;
    public:
        HardAlien();
        HardAlien(int id);
        int getWidth(){return 50;}
        void dying();
        void animate();
        signals:
            void goodbye(int alienId);
};
#endif // HARDALIEN_H
