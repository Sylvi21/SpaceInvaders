#ifndef ALIENFLOCK_H
#define ALIENFLOCK_H
#include "Alien.h"
#include "AlienBullet.h"
#include <QGraphicsScene>
#include <vector>

class AlienFlock : public QObject {
private:
    std::vector <Alien*> flock;
    QGraphicsScene *scene;

    int rows;
    int cols;
    int leftBorder = 800;
    int rightBorder = 0;
public slots:
    void alienShot(Alien *alien);
signals:
    void bullsEye();
public:
    AlienFlock(int rows, int cols, QGraphicsScene *scene);
    ~AlienFlock();
    int dir = 20;
    int getRows(){return rows;}
    void setRows(int rows){this->rows = rows;}
    int getCols(){return cols;}
    void setCols(int cols){this->cols = cols;}
    int getLeftBorder(){return leftBorder;}
    void setLeftBorder(int leftBorder){this->leftBorder = leftBorder;}
    int getRightBorder(){return rightBorder;}
    void setRightBorder(int rightBorder){this->rightBorder = rightBorder;}
    void createAliens();
    void draw();
    void move();
    void attack();
    void remove(Alien* alien);
};

#endif // ALIENFLOCK_H
