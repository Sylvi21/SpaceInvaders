#include "Alien.h"
#include "Bullet.h"
#include "qpainter.h"
/*
QRectF Alien::boundingRect() const{
    return QRectF(xCoordinate, yCoordinate, xCoordinate+width, yCoordinate+height);
}

void Alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rec = boundingRect();
//    painter->setBrush(QBrush(Qt::black));
    painter->drawRect(rec);
}
*/
void Alien::shoot(){
 //   Bullet *alienBullet = new Bullet();
 //   alienBullet->move();
}

void Alien::remove(){
    delete this;
}
