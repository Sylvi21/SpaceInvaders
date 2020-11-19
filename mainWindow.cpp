#include "mainWindow.h"
#include "Alien.h"
#include <QMediaPlayer>


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
    initAliens();
    initAudio();

    ui->graphicsView->setScene(scene);

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

void MainWindow::initAliens(){
    alienFlock =  new AlienFlock(3, 5, scene);
    alienFlock->move();
    alienFlock->attack();
}

void MainWindow::initAudio(){
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/music.mp3"));
    music->setVolume(30);
    music->play();
}
