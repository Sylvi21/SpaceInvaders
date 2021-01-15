#include "StartWindow.h"
#include "ui_StartWindow.h"
#include "mainWindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
       hide();
       mainWindow = new MainWindow;
       mainWindow->show();

}
