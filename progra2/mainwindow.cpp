#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "world.h"
#include "iostream"
#include "worldwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->create, SIGNAL (released()),this, SLOT (create()));
}

void MainWindow::create(){
    QString quant = ui->people->toPlainText();
    world->generatePeople(quant.toInt());
    WorldWindow *w = new WorldWindow();
    w->world = this->world;
    w->show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
