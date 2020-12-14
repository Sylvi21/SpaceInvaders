#include "EasyLevel.h"

EasyLevel::EasyLevel(Ship *spaceship, QGraphicsScene *scene) :
    Level(spaceship, scene){
    this->setState(LevelState::PREPARING);
    this->ship = spaceship;
    this->scene = scene;
    initAliens();
    initBarrier();
}

void EasyLevel::initBarrier()
{
    barrier = new Barrier();
    barrier2 = new Barrier();
    barrier->setPixmap(QPixmap(":/img/barrier.png"));
    barrier->setPos(scene->width()/5 - barrier->pixmap().width()/5, scene->height()-100 - barrier->pixmap().height());
    barrier2->setPixmap(QPixmap(":/img/barrier.png"));
    barrier2->setPos(scene->width()*4/5  - barrier2->pixmap().width()*4/5, scene->height()-100 - barrier2->pixmap().height());
    scene->addItem(barrier);
    scene->addItem(barrier2);
}
