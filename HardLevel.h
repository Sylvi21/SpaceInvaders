#ifndef HARDLEVEL_H
#define HARDLEVEL_H
#include <QList>
#include "Level.h"
#include "Ship.h"
#include "Alien.h"
#include "EasyAlien.h"
#include "MediumAlien.h"
#include "HardAlien.h"
#include "Barrier.h"

class HardLevel : public Level {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Ship *ship;
    QList<Alien*> flock;
    QTimer *timer;
    LevelState state;
    Barrier *barrier;
    Barrier *barrier2;
    const int COLS = 8;
    const int ROWS = 5;
    int leftBorder = 800;
    int rightBorder = 0;
    void initBarrier();
    void createAliens();
    void initBarriers();
    public:
        HardLevel(Ship *spaceship, QGraphicsScene *scene);
};
#endif // HARDLEVEL_H
