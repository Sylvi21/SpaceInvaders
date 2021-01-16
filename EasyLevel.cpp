#include "EasyLevel.h"

EasyLevel::EasyLevel(Ship *spaceship, QGraphicsScene *scene) :
    Level(spaceship, scene){
    this->setState(LevelState::PREPARING);
    this->ship = spaceship;
    this->scene = scene;
    this->leftBorder = 800;
    this->rightBorder = 0;
    this->dir = 20;
    this->descend = 0;
    this->timerInterval = 400;
    initAliens();
    initBarrier();
}

EasyLevel::~EasyLevel()
{
    delete alienFlockShootTimer;
    alienFlockShootTimer = nullptr;
    delete levelTimer;
    levelTimer = nullptr;
    if(barrier){
        barrier = nullptr;
        delete barrier;
    }
    if(barrier2){
        barrier2 = nullptr;
        delete barrier2;
    }
}

void EasyLevel::initAliens(){
    for(int i=0; i< ROWS; i++){
        for(int j=0; j< COLS; j++){
            if(i == 0){
                HardAlien *alien = new HardAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&EasyLevel::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
            else if(i == 1 || i == 2){
                MediumAlien *alien = new MediumAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&EasyLevel::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
            else {
                EasyAlien *alien = new EasyAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&EasyLevel::alienShot);
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

void EasyLevel::initBarrier()
{
    barrier = new Barrier();
    barrier2 = new Barrier();
    barrier->setPixmap(QPixmap(":/img/barrier5.png"));
    barrier->setPos(scene->width()/5 - barrier->pixmap().width()/5, scene->height()-100 - barrier->pixmap().height());
    barrier2->setPixmap(QPixmap(":/img/barrier5.png"));
    barrier2->setPos(scene->width()*4/5  - barrier2->pixmap().width()*4/5, scene->height()-100 - barrier2->pixmap().height());
    scene->addItem(barrier);
    scene->addItem(barrier2);
}

void EasyLevel::play(){
    setState(LevelState::RUNNING);
    attack();
    levelTimer = new QTimer(this);
    connect(levelTimer,&QTimer::timeout,[=](){
        moveAliens();
        if (checkAlienCollisionWithShip()){
            levelTimer->stop();
            setState(LevelState::FAILED);
        }
    });
    levelTimer->start(timerInterval);
}

void EasyLevel::moveAliens()
{
        QTextStream out(stdout);
        int maxLeft = 800, maxRight = 0;
        int counter = 0;
        if(getRightBorder()+20 > scene->width()-30){
            dir=-20;
            if(flock.size() < 15)
                descend = 10;
        }
        if (getLeftBorder()-20 < 30){
            dir = 20;
            descend = 5;
            if(flock.size() < 15)
                descend = 35;
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

void EasyLevel::attack()
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

void EasyLevel::alienShot(Alien *alien){
    QTextStream out(stdout);
    for (QList<Alien*>::iterator it = flock.begin(); it != flock.end(); ++it){
        if((*it) == alien){
            generateBuffs((*it)->x(), (*it)->y());
            delete (*it);
            (*it) = NULL;
            flock.erase(it);
            if(flock.size() < 10){
                timerInterval *= 0.75;
                levelTimer->setInterval(timerInterval);
            }
            if(flock.empty())
                setState(LevelState::WON);
            return;
        }
    }
}
