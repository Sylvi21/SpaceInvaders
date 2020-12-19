#include "mainWindow.h"
#include <QFont>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/img/background.png")));
    setFixedSize(1200,800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    initScene();
    initSpaceship();
    initAudio();

    ui->graphicsView->setScene(scene);
    play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,800);
}

void MainWindow::initSpaceship()
{
    spaceship = new Ship();
    spaceship->setPixmap(QPixmap(":/img/spaceship.png"));
    spaceship->setPos(scene->width()/2 - spaceship->pixmap().width()/2, scene->height()-10 - spaceship->pixmap().height());
    spaceship->setFlag(QGraphicsItem::ItemIsFocusable);
    spaceship->setFocus();
    scene->addItem(spaceship);
}

void MainWindow::initAudio()
{
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/music.mp3"));
    music->setVolume(20);
    music->play();
}


void MainWindow::play()
{
    currentLevel = new EasyLevel(spaceship, scene);
    currentLevel->play();
    QTimer *mainTimer = new QTimer(this);
    connect(mainTimer,&QTimer::timeout,[=](){
        if (currentLevel->getState() == LevelState::WON)
        {
            delete currentLevel;
            levelNumber++;
            if(levelNumber == 1 || levelNumber == 2){
                currentLevel = new EasyLevel(spaceship, scene);
                currentLevel->play();
            } else if (levelNumber == 3 || levelNumber == 4){
                currentLevel = new MediumLevel(spaceship, scene);
                currentLevel->play();
            } else {
                currentLevel = new HardLevel(spaceship, scene);
                currentLevel->play();
           }
        }
        if (currentLevel->getState() == LevelState::FAILED){
            mainTimer->stop();
            delete currentLevel;
            //TODO show end window with points
        }
    });
    mainTimer->start(1000);
}

