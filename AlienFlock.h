#ifndef ALIENFLOCK_H
#define ALIENFLOCK_H
#include "Alien.h"
#include <QGraphicsScene>
#include <vector>

class AlienFlock : public QObject {
private:
    std::vector <Alien*> flock;
    QGraphicsScene *scene;
    int rows;
    int cols;
    int leftBoarder = 0;
    int rightBoarder = 0;
public:
    AlienFlock(int rows, int cols, QGraphicsScene *scene){
        this->rows = rows;
        this->cols = cols;
        this->scene = scene;
        createAliens();
        draw();
    };
    ~AlienFlock(){
        for (auto alien : flock)
           {
                alien = nullptr;
                alien->remove();
           }
           flock.clear();
    };
    int getRows(){return rows;}
    void setRows(int rows){this->rows = rows;}
    int getCols(){return cols;}
    void setCols(int cols){this->cols = cols;}
    int getLeftBoarder(){return leftBoarder;}
    void setLeftBoarder(int leftBoarder){this->leftBoarder = leftBoarder;}
    int getRightBoarder(){return rightBoarder;}
    void setRightBoarder(int rightBoarder){this->rightBoarder = rightBoarder;}
    void createAliens();
    void draw();
    void move();
    void shoot(int id);
    void remove(Alien* alien);
};

#endif // ALIENFLOCK_H
