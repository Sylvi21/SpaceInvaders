#include "HardLevel.h"

HardLevel::HardLevel(Ship *spaceship, QGraphicsScene *scene) :
    Level(spaceship, scene){
    this->setState(LevelState::PREPARING);
    this->ship = spaceship;
    this->scene = scene;
    this->leftBorder = 800;
    this->rightBorder = 0;
    this->dir = 20;
    this->descend = 0;
    this->timerInterval = 400;
    this->ufo = NULL;
    initAliens();
}

HardLevel::~HardLevel(){
    delete alienFlockShootTimer;
    alienFlockShootTimer = nullptr;
    delete levelTimer;
    levelTimer = nullptr;
    for (auto alien : flock)
       {
            delete alien;
            alien = nullptr;
       }
       flock.clear();
       scene->clear();
}

void HardLevel::initAliens()
{
    for(int i=0; i< ROWS; i++){
        for(int j=0; j< COLS; j++){
            if(i == 0){
                HardAlien *alien = new HardAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&HardLevel::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
            else if(i == 1 || i == 2){
                MediumAlien *alien = new MediumAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&HardLevel::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
            else {
                EasyAlien *alien = new EasyAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&HardLevel::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
        }
    }
    int width = 50;
    this->leftBorder = 0;
    this->rightBorder = COLS*width+(COLS-1)*(70-width);
}

void HardLevel::play(){
    setState(LevelState::RUNNING);
    attack();
    levelTimer = new QTimer(this);
    connect(levelTimer,&QTimer::timeout,[=](){
        if(this->getState() == LevelState::RUNNING){
            this->moveAliens();
            if (checkAlienCollisionWithShip()){
                levelTimer->stop();
                setState(LevelState::FAILED);
            }
        } if (getState() == LevelState::BOSSTIME){
            ufo->move();
            if(ufo->getHP() <= 0){
                setState(LevelState::WON);
            }
        }
    });
    levelTimer->start(timerInterval);
}

void HardLevel::moveAliens()
{
    int maxLeft = 800, maxRight = 0;
    int counter = 0;
    if(getRightBorder()+20 > scene->width()-30){
        dir=-20;
        descend = 5;
        if(flock.size() < 15)
            descend = 25;
    }
    if (getLeftBorder()-20 < 30){
        dir = 20;
        descend = 5;
        if(flock.size() < 15)
            descend = 25;
    }

    for (Alien *alien : flock){
        if(alien != NULL){
            alien->setX(alien->x()+dir);
            alien->animate();

            alien->setPos(QPointF(alien->x(), alien->y()+descend));

            if(alien->x() < maxLeft)
            {
                maxLeft = alien->x();
            }
            if(alien->x() + alien->getWidth() > maxRight)
            {
                maxRight = alien->x() + alien->getWidth();
            }
                counter++;
        }
    }
    setRightBorder(maxRight);
    setLeftBorder(maxLeft);
    descend = 0;
}

void HardLevel::attack()
{
    alienFlockShootTimer = new QTimer(this);
    alienFlockShootTimer = new QTimer(this);
    connect(alienFlockShootTimer,&QTimer::timeout,[=](){
        if(!flock.empty()){
            int v = QRandomGenerator::global()->bounded(0, flock.size());
            Alien *alien = flock.at(v);
            AlienBullet *alienBullet = new AlienBullet(QPixmap(":/img/ab.png"));
            alienBullet->setPos(alien->x(), alien->y());
            scene->addItem(alienBullet);
            alienBullet->move();
        }
    });
    alienFlockShootTimer->start(800);
}

void HardLevel::alienShot(Alien *alien){
    for (QList<Alien*>::iterator it = flock.begin(); it != flock.end(); ++it){
        if((*it) == alien){
            generateBuffs((*it)->x(), (*it)->y());
            delete (*it);
            (*it) = NULL;
            flock.erase(it);
            if(flock.size() < 15){
                timerInterval *= 0.9;
                levelTimer->setInterval(timerInterval);
            }
            if(flock.empty()){
                fightBoss();
                setState(LevelState::BOSSTIME);
            }
            return;
        }
    }
    return;
}

void HardLevel::fightBoss(){
    ufo = new BossAlien();
    ufo->setPos(10, 10);
    scene->addItem(ufo);
    ufo->attack();
}

bool HardLevel::checkIfUfoHit(){
    QList<QGraphicsItem *> collidingItems = ufo->collidingItems() ;

    foreach(QGraphicsItem *item, collidingItems)
    {
        Shoot *bullet = dynamic_cast<Shoot *>(item);
        if (bullet)
        {
            scene->removeItem(bullet);
            return true;
        }
    }
    return false;
}
