#include "Level.h"
#include <QTimer>
#include <QTextStream>

Level::Level(AlienFlock *flock, Ship *spaceship, QGraphicsScene *scene){
    this->setState(LevelState::PREPARING);
    this->flock = flock;
    this->ship = spaceship;
    this->scene = scene;
    initAliens();
}

Level::~Level(){
    flock = nullptr;
}

void Level::initAliens(){
  //  alienFlock =  new AlienFlock(3, 5, scene);
    flock->createAliens();
    flock->move();
    flock->attack();
}

void Level::setState(LevelState state){
    this->state = state;
}

LevelState Level::getState(){
    return state;
}


void Level::play(){
    QTextStream out(stdout);
    this->setState(LevelState::RUNNING);

    QTimer *levelTimer = new QTimer(this);
    connect(levelTimer,&QTimer::timeout,[=](){
        QTextStream out(stdout);
        out<<"Loopie levelie"<<Qt::endl;
        if(flock->isEmpty())
            this->setState(LevelState::WON);
        out<<flock->isEmpty()<<Qt::endl;

    });
    levelTimer->start(1000);
}
