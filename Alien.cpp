#include "Alien.h"
#include "AlienBullet.h"
#include "qpainter.h"

Alien::Alien(int id, int xCoordinate, int yCoordinate, QPixmap pixmap){
    this->id = id;
    this->height = pixmap.height();
    this->width = pixmap.width();
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
    setPixmap(pixmap);
};

void Alien::dying(){
    emit goodbye(this->getId());
}

void Alien::remove(){
    delete this;
}
