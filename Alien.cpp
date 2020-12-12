#include "Alien.h"
#include "AlienBullet.h"
#include "qpainter.h"

Alien::Alien(int id, QPixmap pixmap){
    this->id = id;
    setPixmap(pixmap);
};

void Alien::dying(){
    emit goodbye(this->getId());
}

void Alien::remove(){
    delete this;
}
