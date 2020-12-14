#ifndef FIRSTLEVEL_H
#define FIRSTLEVEL_H
#include <QList>
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
        EasyLevel(Ship *spaceship, QGraphicsScene *scene);
};

#endif // FIRSTLEVEL_H
