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

    AlienFlock *alienFlock =  new AlienFlock(3, 5, scene);
    alienFlock->move();

/*
    QGraphicsPixmapItem *pix = new QGraphicsPixmapItem(QPixmap(":/img/green-alien.png"));
    scene->addItem(pix);
    pix->setPos(QPointF(0,0) - QPointF(pix->boundingRect().width()/2,
                                               pix->boundingRect().height()/2));
*/

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

