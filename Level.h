#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QRandomGenerator>
#include "Ship.h"
#include "Alien.h"
#include "EasyAlien.h"
#include "MediumAlien.h"
#include "HardAlien.h"
#include "LevelState.h"
#include "AlienBullet.h"
#include "ShieldBuff.h"
#include "MultishootBuff.h"

class Level : public QObject{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Ship *ship;
    QList<Alien*> flock;
    QTimer *levelTimer;
    LevelState state;
    const int COLS = 8;
    const int ROWS = 5;
    int leftBorder;
    int rightBorder;
    int dir;
    int descend;
    int timerInterval;
public slots:
    void alienShot(Alien *alien);
public:
    Level(Ship *spaceship, QGraphicsScene *scene);
    ~Level();
    void setState(LevelState state);
    LevelState getState();
    int getLeftBorder(){return leftBorder;}
    void setLeftBorder(int leftBorder){this->leftBorder = leftBorder;}
    int getRightBorder(){return rightBorder;}
    void setRightBorder(int rightBorder){this->rightBorder = rightBorder;}
    void initAliens();
    void play();
    void moveAliens();
    void generateBuffs(int x, int y);
    void attack();
    bool checkAlienCollisionWithShip();
};

#endif // LEVEL_H
