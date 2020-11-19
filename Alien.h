#ifndef ALIEN_H
#define ALIEN_H
#include <QGraphicsPixmapItem>

class Alien : public QGraphicsPixmapItem {
    private:
        int id;
        int height;
        int width;
        int xCoordinate;
        int yCoordinate;
    public:
        Alien();
        Alien(int id, int xCoordinate, int yCoordinate, QPixmap pixmap);

        int getId(){return this->id;}
        void setId(int id);
        int getHeight(){return this->height;}
        int getWidth(){return this->width;}
        int getXCoordinate(){return this->xCoordinate;}
        void setXCoordinate(int xCoordinate){this->xCoordinate = xCoordinate;}
        int getYCoordinate(){return this->yCoordinate;};
        void setYCoordinate(int yCoordinate){this->yCoordinate = yCoordinate;}
        void hasCollided();
        void remove();
};

#endif // ALIEN_H
