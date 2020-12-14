#include "HardAlien.h"

HardAlien::HardAlien(int id, QPixmap pixmap) :
    Alien(id, pixmap){
    this->id = id;
    this->points = 30;
    setPixmap(pixmap);
};
