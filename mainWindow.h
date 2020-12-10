#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainWindow.h"
#include "AlienFlock.h"
#include "Ship.h"
#include "AlienBullet.h"
#include "Score.h"
#include "Barrier.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "Alien.h"
#include <QMediaPlayer>
#include "Level.h"
#include "LevelState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        QGraphicsScene *scene;
        Ship *spaceship;
        AlienFlock *alienFlock;
        Score *score;
        Barrier *barrier;
        Barrier *barrier2;
        Level *currentLevel;

        int levelNumber = 0;
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void initScene();
        void initSpaceship();
        void initAudio();
        void initScore();
        void initBarrier();
        void play();

};
#endif // MAINWINDOW_H
