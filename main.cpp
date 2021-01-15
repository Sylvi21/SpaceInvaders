#include "mainWindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <StartWindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        StartWindow start;
        start.show();
        return a.exec();
}
