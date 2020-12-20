#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainWindow.h"
#include "Ship.h"
#include "AlienBullet.h"
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
#include "Score.h"

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
        Level *currentLevel;
        Score *score;
        int levelNumber = 0;
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void initScene();
        void initSpaceship();
        void initAudio();
        void play();
        void displayMainMenu();
        void initScore();
public slots:
    int setScore();

};
#endif // MAINWINDOW_H
