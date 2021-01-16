#include "BossAlien.h"

BossAlien::BossAlien()
{
    this->points = 300;
    this->HP = 120;
    this->setPixmap(QPixmap(":/img/ufo.png"));
    this->dir = 20;
};

BossAlien::~BossAlien()
{
    this->points = 300;
    this->HP = 120;
    this->setPixmap(QPixmap(":/img/ufo.png"));
    this->dir = 20;
};

int BossAlien::getHP()
{
    return this->HP;
}

void BossAlien::setHP(int HP){
    this->HP = HP;
}

void BossAlien::decreaseHP(){
    setHP(getHP()-20);

}

void BossAlien::move()
{
    if(dir > 0 && x()+ 20 > scene()->width()-400){
        dir = -20;
    }
    if (dir <0 && x()-20 < 0){
        dir = 20;
    }
    setPos(x()+dir,y());
}

void BossAlien::attack()
{
    ufoShootTimer = new QTimer(this);
    connect(ufoShootTimer,&QTimer::timeout,[=](){
        AlienBullet *alienBullet1 = new AlienBullet(QPixmap(":/img/ab.png"));
        AlienBullet *alienBullet2 = new AlienBullet(QPixmap(":/img/ab.png"));
        alienBullet1->setPos(x()+50, y()+90);
        alienBullet2->setPos(x()+350, y()+90);
        scene()->addItem(alienBullet1);
        scene()->addItem(alienBullet2);
        alienBullet1->move();
        alienBullet2->move();
    });
    ufoShootTimer->start(1000);
}

