#include "mainWindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox message;
    message.setWindowTitle("Space Invaders");
    message.setText("Space Invaders - game \n Use arrows to move and spacebar to shoot");
    message.setInformativeText("Do you want to play?");
    message.setDetailedText("Space Invaders \n 2020 \n Brant Sylwia \n Charaziński Hubert");
    QPushButton *startButton = message.addButton(QMessageBox::Yes);
    QPushButton *quitButton = message.addButton(QMessageBox::No);
    message.exec();

    if (message.clickedButton() == startButton) {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else if (message.clickedButton() == quitButton) {
        message.close();
    }
    return 0;
}
