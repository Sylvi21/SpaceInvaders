#ifndef SHIELD_H
#define SHIELD_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Shield: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int xCoordinate;
    int duration = 3000;
public:
    Shield(int x);
    void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;};
    int getXCoordinate(){return xCoordinate;};
    void decreaseDuration();
    int getDuration();
};

#endif // SHIELD_H
