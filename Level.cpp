#include "Level.h"
#include <QTimer>
#include <QTextStream>

Level::Level(Ship *spaceship, QGraphicsScene *scene){
    this->setState(LevelState::PREPARING);
    this->ship = spaceship;
    this->scene = scene;
}

void Level::initAliens()
{
    for(int i=0; i< ROWS; i++){
        QPixmap pixmap;
        Alien* alien;
        if(i == 0)
            pixmap = QPixmap(":/img/cyan-alien.png");
                else if(i == 1 || i == 2)
            pixmap = QPixmap(":/img/green-alien.png");
        else
            pixmap = QPixmap(":/img/yellow-alien.png");


        for(int j=0; j< COLS; j++){
            if(i == 0)
                alien = new HardAlien(i*COLS+j);
            else if(i == 1 || i == 2)
                alien = new MediumAlien(i*COLS+j);
            else
                alien = new EasyAlien(i*COLS+j);
            connect(alien,&Alien::goodbye,this,&Level::alienShot);
            alien->setPos(j*70, i*60);
            flock.push_back(alien);
            scene->addItem(alien);
        }
    }
    int width = 50;
    int height = 34;
    this->leftBorder = 0;
    this->rightBorder = COLS*width+(COLS-1)*(70-width);
}

Level::~Level(){
    for (auto alien : flock)
       {
            alien = nullptr;
            delete alien;
       }
       flock.clear();
}

void Level::setState(LevelState state){
    this->state = state;
}

LevelState Level::getState(){
    return state;
}

void Level::play(){
    QTextStream out(stdout);
    setState(LevelState::RUNNING);
    attack();
    QTimer *levelTimer = new QTimer(this);
    connect(levelTimer,&QTimer::timeout,[=](){
        QTextStream out(stdout);
        out<<"Loopie levelie"<<Qt::endl;
        moveAliens();
        out<<flock.isEmpty()<<Qt::endl;

    });
    levelTimer->start(600);
}

void Level::moveAliens()
{
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
}

void Level::attack()
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

void Level::alienShot(Alien *alien){
    QTextStream out(stdout);
    for (QList<Alien*>::iterator it = flock.begin(); it != flock.end(); ++it){
        if((*it) == alien){
            generateBuffs((*it)->x(), (*it)->y());
            delete (*it);
            flock.erase(it);
            if(flock.empty())
                setState(LevelState::WON);
            return;
        }
    }
}
