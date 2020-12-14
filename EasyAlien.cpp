#include "EasyAlien.h"

EasyAlien::EasyAlien(int id, QPixmap pixmap) :
    Alien(id, pixmap){
    this->id = id;
    this->points = 10;
    setPixmap(pixmap);
};
