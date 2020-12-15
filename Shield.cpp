#include "Shield.h"
#include <QElapsedTimer>
#include <QKeyEvent>

Shield::Shield(int x)
{
    this->xCoordinate = x;
    setPixmap(QPixmap(":/img/shield.png"));
    this->setPos(this->xCoordinate-35, 720);
}

void Shield::decreaseDuration(){
    duration--;
    if(duration==0)
    {
        delete this;
    }}

int Shield::getDuration(){
return duration;
}
