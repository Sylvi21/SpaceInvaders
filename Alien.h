#ifndef ALIEN_H
#define ALIEN_H
#include <QGraphicsPixmapItem>

class Alien : public QObject, public QGraphicsPixmapItem {
        Q_OBJECT
    private:
        int id;
        int shotDamage;
        int points;
    public:
        Alien();
        Alien(int id, QPixmap pixmap);
        int getWidth(){return 50;}
        int getId(){return this->id;}
        void setId(int id);
        int getPoints();
        void dying();
        signals:
            void goodbye(Alien *alien);
};

#endif // ALIEN_H
