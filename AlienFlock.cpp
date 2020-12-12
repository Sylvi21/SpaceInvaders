#include "AlienFlock.h"
#include "Alien.h"
#include "EasyAlien.h"
#include "MediumAlien.h"
#include "HardAlien.h"
#include <QPixmap>
#include <QTimer>
#include <QTextStream>
#include <QRandomGenerator>

AlienFlock::AlienFlock(QGraphicsScene *scene)
{
    this->rows = 5;
    this->cols = 8;
    this->scene = scene;
};

AlienFlock::~AlienFlock()
{
    for (auto alien : flock)
       {
            alien = nullptr;
            alien->remove();
       }
       flock.clear();
};


void AlienFlock::createAliens()
{
    for(int i=0; i<getRows(); i++){
        QPixmap pixmap;
        Alien* alien;
        if(i == 0)
            pixmap = QPixmap(":/img/cyan-alien.png");
                else if(i == 1 || i == 2)
            pixmap = QPixmap(":/img/green-alien.png");
        else
            pixmap = QPixmap(":/img/yellow-alien.png");


        for(int j=0; j<getCols(); j++){
            if(i == 0)
                alien = new HardAlien(i*getCols()+j, pixmap);
            else if(i == 1 || i == 2)
                alien = new MediumAlien(i*getCols()+j, pixmap);
            else
                alien = new EasyAlien(i*getCols()+j, pixmap);

            alien->setPos(j*70, i*60);
            connect(alien,&Alien::goodbye,this,&AlienFlock::alienShot);
            flock.push_back(alien);
            scene->addItem(alien);
        }
    }
    int width = 50;
    int height = 34;
    this->leftBorder = 0;
    this->rightBorder = cols*width+(cols-1)*(70-width);
}

/*
void AlienFlock::createAliens()
{
    for(int i=0; i<getRows(); i++){
        for(int j=0; j<getCols(); j++){
            QPixmap pixmap = QPixmap(":/img/green-alien.png");
            Alien* alien = new Alien(i*getCols()+j, pixmap);
            alien->setPos(j*70, i*60);
            connect(alien,&Alien::goodbye,this,&AlienFlock::alienShot);
            flock.push_back(alien);
            scene->addItem(alien);
        }
    }
    int width = 50;
    int height = 34;
    this->leftBorder = 0;
    this->rightBorder = cols*width+(cols-1)*(70-width);
}
*/

void AlienFlock::move()
{
    QTimer *alienFlockTimer = new QTimer(this);
    connect(alienFlockTimer,&QTimer::timeout,[=](){
        QTextStream out(stdout);
        int maxLeft = 800, maxRight = 0;
        int counter = 0;
        if(getRightBorder()+20 > scene->width()-30)
            dir=-20;
        if (getLeftBorder()-20 < 30)
            dir = 20;
        for (Alien *alien : flock){
            if(alien != NULL){
                alien->setX(alien->x()+dir);
                alien->setPos(QPointF(alien->x(), alien->y()));

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
    });
    alienFlockTimer->start(300);
}

void AlienFlock::attack()
{
    QTimer *alienFlockShootTimer = new QTimer(this);
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
    alienFlockShootTimer->start(600);
}

void AlienFlock::alienShot(int id){
    QTextStream out(stdout);
    for (std::vector<Alien*>::iterator it = flock.begin(); it != flock.end(); ++it){
        if((*it)->getId() == id){
            out << id << Qt::endl << Qt::endl;
            generateBuffs((*it)->x(), (*it)->y());
            delete (*it);
            flock.erase(it);
            if(flock.empty())
                this->empty = true;
            return;
        }
    }
}

void AlienFlock::generateBuffs(int x, int y){
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

bool AlienFlock::isEmpty(){
    return empty;
}
