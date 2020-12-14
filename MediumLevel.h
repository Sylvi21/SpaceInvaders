#ifndef MEDIUMLEVEL_H
#define MEDIUMLEVEL_H
#include <QList>
#include "Level.h"
#include "Ship.h"
#include "Alien.h"
#include "EasyAlien.h"
#include "MediumAlien.h"
#include "HardAlien.h"

class MediumLevel : public Level {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Ship *ship;
    QList<Alien*> flock;
    QTimer *timer;
    LevelState state;
    const int COLS = 8;
    const int ROWS = 5;
    int leftBorder = 800;
    int rightBorder = 0;
    public:
        MediumLevel(Ship *spaceship, QGraphicsScene *scene);
};
#endif // MEDIUMLEVEL_H
