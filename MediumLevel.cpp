#include "MediumLevel.h"

MediumLevel::MediumLevel(Ship *spaceship, QGraphicsScene *scene) :
    Level(spaceship, scene){
    this->setState(LevelState::PREPARING);
    this->ship = spaceship;
    this->scene = scene;
    initAliens();
}
