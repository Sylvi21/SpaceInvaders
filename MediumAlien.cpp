#include "MediumAlien.h"

MediumAlien::MediumAlien(int id) :
    Alien(id){
    this->id = id;
    this->points = 20;
    setPixmap(QPixmap(":/img/green-alien.png"));
};
