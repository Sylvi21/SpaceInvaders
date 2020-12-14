#include "Alien.h"
#include "AlienBullet.h"

Alien::Alien() {
}

Alien::Alien(int id){
    this->id = id;
};

void Alien::dying(){
    emit goodbye(this);
}
