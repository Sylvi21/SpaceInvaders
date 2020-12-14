#include "MediumAlien.h"

MediumAlien::MediumAlien(int id, QPixmap pixmap) :
    Alien(id, pixmap){
    this->id = id;
    this->points = 20;
    setPixmap(pixmap);
};
