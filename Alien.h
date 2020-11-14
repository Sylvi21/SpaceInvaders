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
        Alien(int id, int height, int width,int xCoordinate, int yCoordinate, QPixmap pixmap){
            this->id = id;
            this->height = height;
            this->width = width;
            this->xCoordinate = xCoordinate;
            this->yCoordinate = yCoordinate;
            setPixmap(pixmap);
        };

        int getId(){return this->id;}
        void setId(int id);
        int getHeight(){return this->height;}
        int getWidth(){return this->width;}
        int getXCoordinate(){return this->xCoordinate;}
        int getYCoordinate(){return this->yCoordinate;};
        void shoot();
        void hasCollided();
        void remove();
};

#endif // ALIEN_H
