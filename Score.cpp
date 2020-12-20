#include "Score.h"
#include <QFont>
#include <QGraphicsTextItem>
#include "Shoot.h"
#include <QDebug>

Score::Score(){
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",12));
}

void Score::increaseScore(){
    score = score + 10;
    emit addScore(this);
    qDebug()<<"test";
}

int Score::getScore(){
 return score;
}
