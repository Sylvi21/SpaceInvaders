#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsRectItem>

class Ship: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent *move);
};

#endif // SHIP_H
