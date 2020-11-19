#ifndef SHOOT_H
#define SHOOT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Shoot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shoot();
public slots:
    void move();
};

#endif // SHOOT_H
