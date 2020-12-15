#include "EasyAlien.h"

EasyAlien::EasyAlien(int id) :
    Alien(id){
    this->id = id;
    this->points = 10;
    this->setPixmap(QPixmap(":/img/yellow-alien.png"));
    this->state = AnimationState::DOWN;
};

void EasyAlien::animate(){
    if(state == AnimationState::UP){
        this->setPixmap(QPixmap(":/img/yellow-alien-up.png"));
        this->state = AnimationState::DOWN;
        return;
    } else {
        this->setPixmap(QPixmap(":/img/yellow-alien.png"));
        this->state = AnimationState::UP;
        return;
    }
}
