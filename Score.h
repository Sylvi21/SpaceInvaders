#ifndef SCORE_H
#define SCORE_H
#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsTextItem>
#include <QDebug>
#include "Shoot.h"

class Score: public QGraphicsTextItem
{
    Q_OBJECT
private:
    int score = 0;
public:
     Score();
     void increaseScore();
     int getScore();
signals:
     void addScore(Score *score);
};

#endif // SCORE_H
