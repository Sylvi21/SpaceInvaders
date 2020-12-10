#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Ship.h"
#include "AlienFlock.h"
#include "Alien.h"
#include "LevelState.h"

class Level : public QObject{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Ship *ship;
    AlienFlock *flock;
    QTimer *timer;
    LevelState state;

public:
    Level(AlienFlock *flock, Ship *spaceship, QGraphicsScene *scene);
    ~Level();
    void setState(LevelState state);
    LevelState getState();
    void initAliens();
    void play();
};

#endif // LEVEL_H
