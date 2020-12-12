#include "MediumAlien.h"

MediumAlien::MediumAlien(int id, QPixmap pixmap) :
    Alien(id, pixmap){
    this->id = id;
    setPixmap(pixmap);
};
