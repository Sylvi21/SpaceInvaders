#include "AlienFlock.h"
#include "Alien.h"

void AlienFlock::createAliens(){
    int id = 0;
    for(int i=0; i<5; i++){
        Alien* alien = new Alien(id, 12, 12, i+20, i+20, QPixmap(":/img/green-alien.png"));
        flock[i] = alien;
    }
}

void AlienFlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    int numOfAliens = (int) sizeof(flock);
    for(int i=0; i< numOfAliens; i++){
        flock[i]->paint(painter, option, widget);
    }
}
void AlienFlock::remove(Alien* alien){
    alien->remove();
}

