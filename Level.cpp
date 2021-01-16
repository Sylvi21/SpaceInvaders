#include "Level.h"
#include <QTimer>
#include <QTextStream>

Level::Level(Ship *spaceship, QGraphicsScene *scene){
    this->setState(LevelState::PREPARING);
    this->ship = spaceship;
    this->scene = scene;
    this->leftBorder = 800;
    this->rightBorder = 0;
    this->dir = 20;
    this->descend = 0;
}

Level::~Level(){
    for (auto alien : flock)
       {
            delete alien;
            alien = nullptr;
       }
       flock.clear();
       scene->clear();
}

void Level::initAliens(){
    for(int i=0; i< ROWS; i++){
        for(int j=0; j< COLS; j++){
            if(i == 0){
                HardAlien *alien = new HardAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&Level::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
            else if(i == 1 || i == 2){
                MediumAlien *alien = new MediumAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&Level::alienShot);
                alien->setPos(j*70, i*60);
                flock.push_back(alien);
                scene->addItem(alien);
            }
            else {
                EasyAlien *alien = new EasyAlien(i*COLS+j);
                connect(alien,&Alien::goodbye,this,&Level::alienShot);
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

void Level::setState(LevelState state){
    this->state = state;
}

LevelState Level::getState(){
    return state;
}

void Level::alienShot(Alien *alien){
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

void Level::moveAliens()
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

void Level::attack()
{
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

void Level::generateBuffs(int x, int y){
    int v = QRandomGenerator::global()->bounded(0, 10);
    if(v == 0){
        ShieldBuff *shieldBuff = new ShieldBuff(x, y);
        scene->addItem(shieldBuff);
        shieldBuff->move();
    } else if (v == 1){
        MultishootBuff *multishootBuff = new MultishootBuff(x, y);
        scene->addItem(multishootBuff);
        multishootBuff->move();
    } else return;
}

bool Level::checkAlienCollisionWithShip(){
    QList<QGraphicsItem *> collidingItems = ship->collidingItems() ;
    foreach(QGraphicsItem *item, collidingItems)
    {
        Alien *alien = dynamic_cast<Alien *>(item);
        MultishootBuff *msBuff = dynamic_cast<MultishootBuff *>(item);
        ShieldBuff *shieldBuff = dynamic_cast<ShieldBuff *>(item);
        if (alien)
        {
            return true;
        }
        if (msBuff){
            QSound::play(":/sound/mus-buff.wav");
            ship->changeWeapon();
            delete msBuff;
            msBuff = nullptr;
            return false;
        }
        if (shieldBuff){
            QSound::play(":/sound/shield-buff.wav");
            ship->addShield();
            delete shieldBuff;
            shieldBuff = nullptr;
            return false;
        }
    }
    return false;
}
