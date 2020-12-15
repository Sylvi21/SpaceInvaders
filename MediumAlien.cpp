#include "MediumAlien.h"

MediumAlien::MediumAlien(int id) :
    Alien(id){
    this->id = id;
    this->points = 20;
    this->setPixmap(QPixmap(":/img/green-alien.png"));
    this->state = AnimationState::DOWN;
};

void MediumAlien::animate(){
    if(state == AnimationState::UP){
        this->setPixmap(QPixmap(":/img/green-alien-up.png"));
        this->state = AnimationState::DOWN;
        return;
    } else {
        this->setPixmap(QPixmap(":/img/green-alien.png"));
        this->state = AnimationState::UP;
        return;
    }
}
