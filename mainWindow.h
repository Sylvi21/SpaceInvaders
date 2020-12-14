#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainWindow.h"
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
#include "EasyLevel.h"
#include "MediumLevel.h"
#include "HardLevel.h"

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
        Score *score;
        Level *currentLevel;
        int levelNumber = 0;
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void initScene();
        void initSpaceship();
        void initAudio();
        void initScore();
        void play();

};
#endif // MAINWINDOW_H
