#include "AlienFlock.h"
#include "Alien.h"
#include <QPixmap>
#include <QTimer>
#include <QTextStream>
#include <QRandomGenerator>

AlienFlock::AlienFlock(int rows, int cols, QGraphicsScene *scene)
{
    this->rows = rows;
    this->cols = cols;
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
        for(int j=0; j<getCols(); j++){
            QPixmap pixmap = QPixmap(":/img/green-alien.png");
            Alien* alien = new Alien(i*getCols()+j, j*70, i*60, pixmap);
            connect(alien,&Alien::goodbye,this,&AlienFlock::alienShot);
            flock.push_back(alien);
            scene->addItem(alien);
        }
    }
    int width = flock.front()->getWidth();
    int height = flock.front()->getHeight();
    this->leftBorder = 0;
    this->rightBorder = cols*width+(cols-1)*(70-width);
}

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
                alien->setXCoordinate(alien->getXCoordinate()+dir);
                alien->setPos(QPointF(alien->getXCoordinate(), alien->getYCoordinate()));

                if(alien->getXCoordinate() < maxLeft)
                {
                    maxLeft = alien->getXCoordinate();
                }
                if(alien->getXCoordinate()+alien->getWidth() > maxRight)
                {
                    maxRight = alien->getXCoordinate()+alien->getWidth();
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
    connect(alienFlockShootTimer,&QTimer::timeout,[=](){
        int v = QRandomGenerator::global()->bounded(0, flock.size());
        Alien *alien = flock.at(v);
        AlienBullet *alienBullet = new AlienBullet(alien->getXCoordinate(), QPixmap(":/img/ab.png"));
        scene->addItem(alienBullet);
        alienBullet->move();
    });
    alienFlockShootTimer->start(600);
}

void AlienFlock::alienShot(int id){
    QTextStream out(stdout);
    for (std::vector<Alien*>::iterator it = flock.begin(); it != flock.end(); ++it){
        if((*it)->getId() == id){
            out << id << Qt::endl << Qt::endl;
            delete (*it);
            flock.erase(it);
        }
    }
}
