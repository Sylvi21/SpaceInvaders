#include "HardAlien.h"

HardAlien::HardAlien(int id, QPixmap pixmap) :
    Alien(id, pixmap){
    this->id = id;
    setPixmap(pixmap);
};
