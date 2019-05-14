#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "jsonparser.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string names[1000];
    string lastnames[1000];
    string religions[10];
    string countries[100];
    string jobs[50];
    jsonParser *m = new jsonParser();
}

MainWindow::~MainWindow()
{
    delete ui;
}
