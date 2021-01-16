#ifndef HARDLEVEL_H
#define HARDLEVEL_H
#include <QList>
#include "Level.h"
#include "Ship.h"
#include "Alien.h"
#include "EasyAlien.h"
#include "MediumAlien.h"
#include "HardAlien.h"
#include "BossAlien.h"

class HardLevel : public Level {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Ship *ship;
    QList<Alien*> flock;
    LevelState state;
    QTimer *alienFlockShootTimer;
    QTimer *levelTimer;
    QTimer *bossTimer;
    BossAlien *ufo;
    const int COLS = 8;
    const int ROWS = 5;
    int leftBorder = 800;
    int rightBorder = 0;
    int timerInterval;
    int dir;
    int descend;
    void moveAliens();
    void initAliens();
    void attack();
public slots:
    void alienShot(Alien *alien);
    public:
        HardLevel(Ship *spaceship, QGraphicsScene *scene);
        ~HardLevel();
   //     LevelState getState();
   //     void setState(LevelState);
        void play();
        bool checkIfUfoHit();
        void fightBoss();
};

#endif // HARDLEVEL_H
