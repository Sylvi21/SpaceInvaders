#ifndef SHOOT_H
#define SHOOT_H

#include <QGraphicsRectItem>
#include <QObject>

class Shoot: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Shoot();
public slots:
    void move();
};

#endif // SHOOT_H
