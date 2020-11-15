#include "AlienFlock.h"
#include "Alien.h"
#include <QPixmap>
#include <QTimer>
#include <QTextStream>

void AlienFlock::createAliens(){
    int curCol = 0, curRow = 0;
    int aliensNumber = getRows()*getCols();
    for(int i=0; i<getRows(); i++){
        for(int j=0; j<getCols(); j++){
            QPixmap pixmap = QPixmap(":/img/green-alien.png");
            Alien* alien = new Alien(i*j+j, j*70, i*60, pixmap);
            flock.push_back(alien);
            scene->addItem(alien);
        }
    }

}

void AlienFlock::draw(){
    for (auto alien : flock){
        alien->setPos(QPointF(alien->getXCoordinate(), alien->getYCoordinate()));

    }
}

void AlienFlock::move(){
    QTimer *alienFlockTimer = new QTimer(this);
    connect(alienFlockTimer,&QTimer::timeout,[=](){
        int dir = 20;
        QTextStream out(stdout);
        int curRow = 0, curCol = 0;
        for (Alien *alien : flock){
            if(curCol < cols){
                if(getLeftBoarder()+dir > scene->width() || getRightBoarder()+dir < 0)
                    dir*=-1;
                alien->setXCoordinate(alien->getXCoordinate()+dir);
                alien->setPos(QPointF(alien->getXCoordinate(), alien->getYCoordinate()));
                curCol++;
            }
            curCol = 0;
            curRow++;
        }
        draw();
    });
    alienFlockTimer->start(200);
}

void AlienFlock::remove(Alien* alien){
    alien->remove();
}

