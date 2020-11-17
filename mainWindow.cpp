#include "mainWindow.h"
#include "Alien.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    setFixedSize(800, 600);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    Ship *spaceship = new Ship();
    spaceship->setRect(0,0,100,100);

    scene->addItem(spaceship);
    spaceship->setFlag(QGraphicsItem::ItemIsFocusable);
    spaceship->setFocus();

    AlienFlock *alienFlock =  new AlienFlock(3, 5, scene);
    alienFlock->move();

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

