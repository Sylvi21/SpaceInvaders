#include "EasyAlien.h"

EasyAlien::EasyAlien(int id) :
    Alien(id){
    this->id = id;
    this->points = 10;
    setPixmap(QPixmap(":/img/yellow-alien.png"));
};
