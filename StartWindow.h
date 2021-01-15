#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "mainWindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

public slots:
    void on_pushButton_clicked();

private:
    Ui::StartWindow *ui;
    MainWindow *mainWindow;
};

#endif // STARTWINDOW_H
