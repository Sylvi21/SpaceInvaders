#include "Alien.h"
#include "AlienBullet.h"
#include <QTextStream>

Alien::Alien() {
}

Alien::Alien(int id){
    this->id = id;
};

void Alien::dying(){
    emit goodbye(this);
}

void Alien::animate(){
    QTextStream out(stdout);
  //  out<<"hello from the animate"<<Qt::endl;
}
