#include "Score.h"
#include <QFont>
#include <QGraphicsTextItem>
Score::Score(){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",12));
}

void Score::increaseScore(){
    score = score + 10;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

