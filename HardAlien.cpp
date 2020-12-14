#include "HardAlien.h"

HardAlien::HardAlien(int id) :
    Alien(id){
    this->id = id;
    this->points = 30;
    setPixmap(QPixmap(":/img/cyan-alien.png"));
};
