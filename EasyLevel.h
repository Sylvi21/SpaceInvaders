#ifndef FIRSTLEVEL_H
#define FIRSTLEVEL_H
#include <QList>
#include <QGraphicsScene>
#include "Level.h"
#include "Ship.h"
#include "Alien.h"
#include "Barrier.h"

class EasyLevel : public Level {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Ship *ship;
    QList<Alien*> flock;
    QTimer *levelTimer;
    QTimer *alienFlockShootTimer;
    LevelState state;
    Barrier *barrier;
    Barrier *barrier2;
    const int COLS = 8;
    const int ROWS = 5;
    int leftBorder = 800;
    int rightBorder = 0;
    int timerInterval;
    int dir;
    int descend;
    void moveAliens();
    void initAliens();
    void initBarrier();
    void attack();
public slots:
    void alienShot(Alien *alien);
public:
    EasyLevel(Ship *spaceship, QGraphicsScene *scene);
    ~EasyLevel();
    void play();
};

#endif // FIRSTLEVEL_H
