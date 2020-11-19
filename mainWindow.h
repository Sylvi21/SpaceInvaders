#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainWindow.h"
#include "AlienFlock.h"
#include "Ship.h"
#include "AlienBullet.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

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
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void initScene();
        void initSpaceship();
        void initAliens();
        void initAudio();


};
#endif // MAINWINDOW_H
