#ifndef BARRIER_H
#define BARRIER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Barrier: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int durability;
public:
    Barrier();
    void decreaseDurability();
    void checkForCollision();
};

#endif // BARRIER_H
