#include "Ship.h"
#include "Shoot.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>

Ship::Ship(){
    this->xCoordinate = 590;
    life =3;
    health = 3;
    weapon = 0;
    reload = 0;
    ammo = 0;
    shieldMode = 0;
    shieldDuration = 0;
}

Ship::~Ship(){
    delete reloadTimer;
    reloadTimer = NULL;
}

void Ship::keyPressEvent(QKeyEvent *reaction)
{
    if(reaction->key() == Qt::Key_Left&&x()-20>0)
    {
        setPos(x()-30,y());
        this->xCoordinate=xCoordinate-30;

    }
    else if (reaction->key() == Qt::Key_Right&&x()+80<1200)
    {
        setPos(x()+30,y());
        this->xCoordinate=xCoordinate+30;

    }
    else if(reaction->key() == Qt::Key_Space&&weapon==0&&reload==0)
    {
        reload = 1;
        reloadWeapon();
        Shoot *shoot = new Shoot(this->getXCoordinate());
        scene()->addItem(shoot);
        QSound::play(":/sound/ship-shot.wav");
        shoot->move();
    }
    else if(reaction->key() == Qt::Key_Space&&weapon==1&&reload==0)
    {
        reload = 1;
        reloadWeapon();
        if (ammo>0)
        {
        Shoot *shoot = new Shoot(this->getXCoordinate());
        Shoot *shoot2 = new Shoot(this->getXCoordinate()+30);
        Shoot *shoot3 = new Shoot(this->getXCoordinate()-30);
        QSound::play(":/sound/ship-shot.wav");
        scene()->addItem(shoot);
        shoot->move();
        scene()->addItem(shoot2);
        shoot2->move();
        scene()->addItem(shoot3);
        shoot3->move();
        ammo--;
        }
        else if (ammo == 0) weapon=0;
    }

}

void Ship::decreaseHealth(){
    health--;
        if(health==0)
        {
            life--;
            if(life==2)setPixmap(QPixmap(":/img/spaceship2.png"));
            else if(life==1)setPixmap(QPixmap(":/img/spaceship1.png"));
            health=3;
            if (life==0)
            {
            setPixmap(QPixmap(":/img/spaceship.png"));
            QMessageBox message;
            message.setWindowTitle("Space Invaders");
            message.setText("Game over");
            message.setInformativeText("Thanks for playing, if you want you can play again in sandbox mode");
            QPushButton *sandbox = message.addButton(QMessageBox::Ok);
            if (message.clickedButton() == sandbox) {
                message.close();
            }
            else if(message.clickedButton() != sandbox)
            {

            }
            message.exec();
        }
}
}

int Ship::showHealth(){
return health;
}

void Ship::changeWeapon(){
        weapon = 1;
        ammo = ammo+5;
}



void Ship::addShield(){
       if(shieldMode == 0)
       {
       shieldDuration = shieldDuration+1;
       if(life==3)setPixmap(QPixmap(":/img/shield3.png"));
       else if(life==2)setPixmap(QPixmap(":/img/shield2.png"));
       else if(life==1)setPixmap(QPixmap(":/img/shield1.png"));
       else setPixmap(QPixmap(":/img/shield.png"));
       shieldMode=1;
       QTimer *shieldTimer = new QTimer();
       connect(shieldTimer,&QTimer::timeout,[=](){
       shieldDuration--;
       if(shieldDuration == 0)
       {
       shieldTimer->stop();
       if(life==3)setPixmap(QPixmap(":/img/spaceship3.png"));
       else if(life==2)setPixmap(QPixmap(":/img/spaceship2.png"));
       else if(life==1)setPixmap(QPixmap(":/img/spaceship1.png"));
       else setPixmap(QPixmap(":/img/spaceship.png"));
       shieldMode = 0;
       }
       });
       shieldTimer->start(3000);
       }
       else if(shieldMode == 1)
       {
           shieldDuration++;
       }
}

int Ship::shieldStatus(){
return shieldMode;
}

void Ship::reloadWeapon(){
    reloadTimer = new QTimer();
    connect(reloadTimer,&QTimer::timeout,[=](){
    reload = 0;
    reloadTimer->stop();
    });
    reloadTimer->start(500);
}
