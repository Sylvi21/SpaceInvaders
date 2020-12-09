#ifndef BARRIER_H
#define BARRIER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Barrier: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Barrier();
};

#endif // BARRIER_H
