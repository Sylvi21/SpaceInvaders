#include "HardAlien.h"

HardAlien::HardAlien(int id) :
    Alien(id){
    this->id = id;
    this->points = 30;
    this->setPixmap(QPixmap(":/img/cyan-alien.png"));
    this->state = AnimationState::DOWN;
};

void HardAlien::animate(){
    if(state == AnimationState::UP){
        this->setPixmap(QPixmap(":/img/cyan-alien-up.png"));
        this->state = AnimationState::DOWN;
        return;
    } else {
        this->setPixmap(QPixmap(":/img/cyan-alien.png"));
        this->state = AnimationState::UP;
        return;
    }

}
