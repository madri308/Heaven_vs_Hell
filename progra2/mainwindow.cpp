#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "world.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    World *world = new World();
}

MainWindow::~MainWindow()
{
    delete ui;
}
