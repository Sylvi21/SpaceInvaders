#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
class Score: public QGraphicsTextItem
{
private:
    int score = 0;
public:
     Score();
     void increaseScore();
     void checkForScore();
     int getScore();

};

#endif // SCORE_H
