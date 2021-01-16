#include "MultishootBuff.h"

MultishootBuff::MultishootBuff(int x, int y){
    this->setX(x);
    this->setY(y);
    setPixmap(QPixmap(":/img/ms-orb.png"));
    this->msTimer = NULL;
}

MultishootBuff::~MultishootBuff(){
    delete msTimer;
}

void MultishootBuff::move()
{
    msTimer = new QTimer(this);
    connect(msTimer,&QTimer::timeout,[=](){
        if(y() < 800){
            setPos(QPointF(this->x(), this->y()+1));
        } else{
            delete this;
        }
    });
    msTimer->start(5);
}
