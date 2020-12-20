#ifndef SCORE_H
#define SCORE_H
#include <QObject>
#include <QGraphicsTextItem>
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
