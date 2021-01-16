#include "ShieldBuff.h"

ShieldBuff::ShieldBuff(int x, int y){
    this->setX(x);
    this->setY(y);
    setPixmap(QPixmap(":/img/shield-orb.png"));
    this->shieldTimer = NULL;
}

ShieldBuff::~ShieldBuff(){
    delete shieldTimer;
}

void ShieldBuff::move(){
    shieldTimer = new QTimer(this);
    connect(shieldTimer,&QTimer::timeout,[=](){
        if(y() < 800){
            setPos(QPointF(this->x(), this->y()+1));
        } else{
            delete this;
        }
    });
    shieldTimer->start(5);
}
