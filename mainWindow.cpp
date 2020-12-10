#include "mainWindow.h"
#include <QDeadlineTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/img/background.png")));
    setFixedSize(800,600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    initScene();
    initSpaceship();
  //  initAliens();
    initAudio();
    initScore();
    initBarrier();


    ui->graphicsView->setScene(scene);
    play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
}

void MainWindow::initSpaceship(){
    spaceship = new Ship();
    spaceship->setPixmap(QPixmap(":/img/spaceship.png"));
    spaceship->setPos(scene->width()/2 - spaceship->pixmap().width()/2, scene->height()-10 - spaceship->pixmap().height());
    spaceship->setFlag(QGraphicsItem::ItemIsFocusable);
    spaceship->setFocus();
    scene->addItem(spaceship);
}

void MainWindow::initAudio(){
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/music.mp3"));
    music->setVolume(30);
    music->play();
}


void MainWindow::initScore()
{
    score = new Score();
    scene->addItem(score);
    //score->checkForScore();
}

void MainWindow::initBarrier()
{
    barrier = new Barrier();
    barrier2 = new Barrier();
    barrier->setPixmap(QPixmap(":/img/barrier.png"));
    barrier->setPos(scene->width()/5 - barrier->pixmap().width()/5, scene->height()-100 - barrier->pixmap().height());
    barrier2->setPixmap(QPixmap(":/img/barrier.png"));
    barrier2->setPos(scene->width()*4/5  - barrier2->pixmap().width()*4/5, scene->height()-100 - barrier2->pixmap().height());
    scene->addItem(barrier);
    scene->addItem(barrier2);
}

void MainWindow::play(){
  //  int levelNumber = 0;
    alienFlock =  new AlienFlock(3, 5, scene);
    currentLevel = new Level(alienFlock, spaceship, scene);
    currentLevel->play();
    QTimer *alienFlockTimer = new QTimer(this);
    connect(alienFlockTimer,&QTimer::timeout,[=](){
        QTextStream out(stdout);
        out<<"Loopie"<<Qt::endl;
        if (currentLevel->getState() == LevelState::WON)
        {
            delete currentLevel;
            levelNumber++;
            switch(levelNumber)
            {
                case 1: {
                    alienFlock =  new AlienFlock(3, 5, scene);
                    currentLevel = new Level(alienFlock, spaceship, scene);
                    currentLevel->play();
                    break;
                }
                case 2: {
                    alienFlock =  new AlienFlock(4, 6, scene);
                    currentLevel = new Level(alienFlock, spaceship, scene);
                    currentLevel->play();
                    break;
                }
                case 3: {
                    alienFlock =  new AlienFlock(5, 7, scene);
                    currentLevel = new Level(alienFlock, spaceship, scene);
                    currentLevel->play();
                    break;
                }

            }
        }
    });
    alienFlockTimer->start(1000);
  /*  while(true)
    {
        if (currentLevel->getState() == LevelState::WON)
        {
            delete currentLevel;
            levelNumber++;
            switch(levelNumber)
            {
                case 1: {
                    alienFlock =  new AlienFlock(3, 5, scene);
                    currentLevel = new Level(alienFlock, spaceship, scene);
                    break;
                }
                case 2: {
                    alienFlock =  new AlienFlock(4, 6, scene);
                    currentLevel = new Level(alienFlock, spaceship, scene);
                    break;
                }
                case 3: {
                    alienFlock =  new AlienFlock(5, 7, scene);
                    currentLevel = new Level(alienFlock, spaceship, scene);
                    break;
                }

            }
        }
    }*/
}
  /*  alienFlock =  new AlienFlock(3, 5, scene);
    Level *firstLevel = new Level(alienFlock, spaceship, scene);
    firstLevel->setState(LevelState::RUNNING);
    QDeadlineTimer deadline(20000);
    while(firstLevel->getState() == LevelState::RUNNING && !deadline.hasExpired()){

    }
    if(firstLevel->getState() == LevelState::WON && !deadline.hasExpired()){
        delete firstLevel;
        QDeadlineTimer deadline(20000);
        alienFlock =  new AlienFlock(4, 6, scene);
        Level *secondLevel = new Level(alienFlock, spaceship, scene);
        secondLevel->setState(LevelState::RUNNING);
    } else return;*/

