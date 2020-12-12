#ifndef ALIEN_H
#define ALIEN_H
#include <QGraphicsPixmapItem>

class Alien : public QObject, public QGraphicsPixmapItem {
        Q_OBJECT
    private:
        int id;
        int shotDamage;

    public:
        Alien();
        Alien(int id, QPixmap pixmap);
        int getWidth(){return 50;}
        int getId(){return this->id;}
        void setId(int id);
        void dying();
        void remove();
        signals:
            void goodbye(int alienId);
};

#endif // ALIEN_H
