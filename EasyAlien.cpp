#include "EasyAlien.h"

EasyAlien::EasyAlien(int id, QPixmap pixmap) :
    Alien(id, pixmap){
    this->id = id;
    setPixmap(pixmap);
};
