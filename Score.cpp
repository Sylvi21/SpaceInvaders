#include "Score.h"
#include <QFont>
#include <QGraphicsTextItem>
#include <QDebug>
Score::Score(){
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",12));
}

void Score::increaseScore(){
    score = score + 10;
    setPlainText(QString("Score: ") + QString::number(score));
}

void checkForScore(){
//connect
}

int Score::getScore(){
    qDebug()<<"test";
    return score;
}

