#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "world.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    World *world = new World();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void create();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
