#include "worldwindow.h"
#include "ui_worldwindow.h"
#include "iostream"
#include "QMessageBox"

using namespace std;
WorldWindow::WorldWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorldWindow)
{
    ui->setupUi(this);
    connect(ui->generatePeople, SIGNAL (released()),this, SLOT (generatePeople()));
    connect(ui->generateGoodDeeds, SIGNAL (released()),this, SLOT (generateGoodDeeds()));
    connect(ui->generateSins, SIGNAL (released()),this, SLOT (generateSins()));

}

WorldWindow::~WorldWindow()
{
    delete ui;
}
void WorldWindow::generateSins(){
    Node *temp = world->peolpe.first;
    srand(time(NULL));
    while(temp){
        int percetages[7] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
        for(int t = 0; t<7 ; t++){
            temp->data->sins[t][1] = to_string(stoi(temp->data->sins[t][1])+percetages[t]);
        }
        temp = temp->next;
    }
    msgBox.setWindowTitle("Satanas haciendo de las suyas.");
    msgBox.setText(QString::number(world->peolpe.quantity)+" personas han pecado de manera exitosa.");
    msgBox.exec();
}
void WorldWindow::generateGoodDeeds(){
    Node *temp = world->peolpe.first;
    srand(time(NULL));
    while(temp){
        int percetages[7] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
        for(int t = 0; t<7 ; t++){
            temp->data->goodDeeds[t][1] = to_string(stoi(temp->data->goodDeeds[t][1])+percetages[t]);
        }
        temp = temp->next;
    }
    msgBox.setWindowTitle("Gracias a Dios.");
    msgBox.setText(QString::number(world->peolpe.quantity)+" personas hicieron su buena accion del dia.");
    msgBox.exec();
}
void WorldWindow::generatePeople(){
    QString quant = ui->people->toPlainText();
    world->generatePeople(quant.toInt());
    msgBox.setText("Se han agregado "+quant+" personas\nActualmente hay "+QString::number(world->peolpe.quantity));
    msgBox.setWindowTitle("Haciendo bebes!");
    msgBox.exec();
    ui->people->clear();
}

