#ifndef MEDIUMLEVEL_H
#define MEDIUMLEVEL_H
#include <QList>
#include <QGraphicsScene>
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
    LevelState state;
    QTimer *levelTimer;
    QTimer *alienFlockShootTimer;
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
    MediumLevel(Ship *spaceship, QGraphicsScene *scene);
    ~MediumLevel();
    void play();
};
#endif // MEDIUMLEVEL_H
