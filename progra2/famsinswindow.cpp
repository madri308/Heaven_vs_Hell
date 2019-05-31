#include "famsinswindow.h"
#include "ui_famsinswindow.h"
#include "QString"

FamSinsWindow::FamSinsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FamSinsWindow)
{
    ui->setupUi(this);
    this->list = ui->list;
}

FamSinsWindow::~FamSinsWindow()
{
    delete ui;
}

void FamSinsWindow::preOrder(Node *temp)
{

    if(temp != nullptr)
    {
        list->addItem("Nombre: "+QString::fromStdString(temp->data->name+" "+(temp->data->surname)));
        string s = "";
        string g = "";
        for(int i = 0;i<7;i++){
            if(i == 6){
                g = g+"      "+temp->data->goodDeeds[i][0]+": "+temp->data->goodDeeds[i][1];
                s = s+"      "+temp->data->sins[i][0]+": "+temp->data->sins[i][1];
            }else{
                g = g+"      "+temp->data->goodDeeds[i][0]+": "+temp->data->goodDeeds[i][1]+"\n";
                s = s+"      "+temp->data->sins[i][0]+": "+temp->data->sins[i][1]+"\n";
            }
        }
        list->addItem("Buenas acciones:");
        list->addItem(QString::fromStdString(g));
        list->addItem("Pecados:");
        list->addItem(QString::fromStdString(s));
        list->addItem("____________________________________________");

        preOrder(temp->left);
        preOrder(temp->right);
    }
}
