#include "worldwindow.h"
#include "ui_worldwindow.h"
#include "iostream"
#include "sstream"
#include "QMessageBox"
#include "QListWidget"
#include "demonwindow.h"
#include "avltree.h"
#include "QMovie"
#include "QTimer"
#include "famsinswindow.h"

using namespace std;
WorldWindow::WorldWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorldWindow)
{
    ui->setupUi(this);

    connect(ui->generatePeople, SIGNAL (released()),this, SLOT (generatePeople()));
    connect(ui->generateGoodDeeds, SIGNAL (released()),this, SLOT (generateGoodDeeds()));
    connect(ui->generateSins, SIGNAL (released()),this, SLOT (generateSins()));
    connect(ui->top10sins, SIGNAL (released()),this, SLOT (top10sins()));
    connect(ui->top5sins, SIGNAL (released()),this, SLOT (top5sins()));
    connect(ui->top10GD, SIGNAL (released()),this, SLOT (top10GD()));
    connect(ui->top5GD, SIGNAL (released()),this, SLOT (top5GD()));
    connect(ui->showDemon, SIGNAL (released()),this, SLOT (showDemon()));
    connect(ui->ask, SIGNAL (released()),this, SLOT (showFam()));
    connect(ui->CGD, SIGNAL (released()),this, SLOT (showContinentsInfo()));
    connect(ui->condemn, SIGNAL (released()),this, SLOT (condemn()));
    connect(ui->save, SIGNAL (released()),this, SLOT (save()));
}

WorldWindow::~WorldWindow()
{
    delete ui;
}
void WorldWindow::showHumans(){

    ui->humansCount->setText("Personas actualmente: "+QString::number(world->peolpe.quantity));
    Node *temp = world->peolpe.first;
    QListWidget *list = ui->list;
    list->clear();
    while(temp){
        QVBoxLayout *container = new QVBoxLayout;

        QLabel *l1 = new QLabel;
        l1->setText(QString::fromStdString(temp->data->name));
        container->addWidget(l1);

        list->addItem("Id: "+QString::number(temp->data->id));
        list->addItem("Nombre: "+QString::fromStdString(temp->data->name+" "+(temp->data->surname)));
        list->addItem("Pais: "+QString::fromStdString(temp->data->country));
        list->addItem("Religion: "+QString::fromStdString(temp->data->religion));
        list->addItem("Trabajo: "+QString::fromStdString(temp->data->job));
        list->addItem("Familia: "+QString::fromStdString(temp->data->family->name)+" "+QString::number(temp->data->family->count));
        string s = "";
        string g = "";
        for(int i = 0;i<7;i++){
            if(i == 6){
                g = g+temp->data->goodDeeds[i][0]+temp->data->goodDeeds[i][1];
                s = s+temp->data->sins[i][0]+temp->data->sins[i][1];
            }else{
                g = g+temp->data->goodDeeds[i][0]+temp->data->goodDeeds[i][1]+"  ";
                s = s+temp->data->sins[i][0]+temp->data->sins[i][1]+"  ";
            }
        }
        list->addItem(QString::fromStdString(g));
        list->addItem(QString::fromStdString(s));
        list->addItem("___________________________");

        temp = temp->next;
    }
}
void WorldWindow::generateSins(){
    Node *temp = world->peolpe.first;   //EMPIEZA POR LA PRIMERA PERSONA
    srand(time(NULL));
    while(temp){    //MIENTRAS EXISTAN MAS PERSONAS.
        //GENERA LOS NUMEROS RANDOM PARA LOS PECADOS EN UNA LISTA
        int totalSins = 0;
        int percetages[7] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
        for(int t = 0; t<7 ; t++){  //CICLO PARA ESTABLECER PECADOS.
            //LE ASIGNA A CADA PECADO DE LA PERSONA SU PORCENTAJE RANDOM
            temp->data->sins[t][1] = to_string(stoi(temp->data->sins[t][1])+percetages[t]);
            totalSins = totalSins + percetages[t];
            temp->data->totalSins = totalSins;
            for(int c = 0; c < temp->data->childCount ; c++){ //RECORRE LA LISTA DE HIJOS
                //Y A SUS PECADOS LE SUMA EL 50% DEL PAPA.
                if(temp->data->child[c]!= nullptr){
                    temp->data->child[c]->sins[t][1] = to_string(stoi(temp->data->sins[t][1])+(percetages[t]*50/100));
                    totalSins = totalSins + percetages[t]*50/100;
                    for(int cc = 0; cc < temp->data->child[c]->childCount ; cc++){   //RECORRE LOS HIJOS DEL HIJO(NIETOS)
                        //Y A SUS PECADOS LES SUMA EL 25% DEL PAPA DEL PAPA(EL ABUELO)
                        if(temp->data->child[c]->child[cc] != nullptr){
                            temp->data->child[c]->child[cc]->sins[t][1] = to_string(stoi(temp->data->sins[t][1])+(percetages[t]*25/100));
                            totalSins = totalSins + percetages[t]*25/100;
                        }
                    }
                }
            }
        }
        temp->data->family->sins = temp->data->family->sins+totalSins;
        for(int country = 0; country < 100; country++){
            if(temp->data->country == this->world->countries[country][0]){
                int number;
                std::istringstream iss (this->world->countries[country][1]);
                iss >> number;
                this->world->countries[country][1] = to_string(number+totalSins);
            }
        }
        temp = temp->next;  //PASA A LA SIGUIENTE PERSONA
    }
    msgBox.setWindowTitle("Satanas haciendo de las suyas.");
    QPixmap pixmap = QPixmap(":/new/prefix1/demon.ico");
    msgBox.setWindowIcon(pixmap);
    msgBox.setText(QString::number(world->peolpe.quantity)+" personas han pecado de manera exitosa.");
    msgBox.exec();
    showHumans();
}
void WorldWindow::generateGoodDeeds(){
    Node *temp = world->peolpe.first;
    srand(time(NULL));
    while(temp){
        int totalGD = 0;
        int percetages[7] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
        for(int t = 0; t<7 ; t++){
            temp->data->goodDeeds[t][1] = to_string(stoi(temp->data->goodDeeds[t][1])+percetages[t]);
            totalGD = totalGD + percetages[t];
            temp->data->totalGD = totalGD;
            for(int c = 0; c < temp->data->childCount ; c++){ //RECORRE LA LISTA DE HIJOS
                //Y A SUS BUENAS ACCIONES LE SUMA EL 50% DEL PAPA.
                if(temp->data->child[c]!= nullptr){
                    temp->data->child[c]->goodDeeds[t][1] = to_string(stoi(temp->data->goodDeeds[t][1])+(percetages[t]*50/100));
                    totalGD = totalGD + percetages[t]*50/100;
                    for(int cc = 0; cc < temp->data->child[c]->childCount ; cc++){   //RECORRE LOS HIJOS DEL HIJO(NIETOS)
                        //Y A SUS BUENAS ACCIONES LES SUMA EL 25% DEL PAPA DEL PAPA(EL ABUELO)
                        if(temp->data->child[c]->child[cc] != nullptr){
                            temp->data->child[c]->child[cc]->goodDeeds[t][1] = to_string(stoi(temp->data->goodDeeds[t][1])+(percetages[t]*25/100));
                            totalGD = totalGD + percetages[t]*25/100;
                        }
                    }
                }
            }
            temp->data->family->GD = temp->data->family->GD+totalGD;
        }

        for(int country = 0; country < 100; country++){
            if(temp->data->country == this->world->countries[country][0]){
                int number;
                std::istringstream iss (this->world->countries[country][2]);
                iss >> number;
                this->world->countries[country][2] = to_string(number+totalGD);
            }
        }
        temp = temp->next;
    }
    msgBox.setWindowTitle("Gracias a Dios.");
    QPixmap pixmap = QPixmap(":/new/prefix1/please.ico");
    msgBox.setWindowIcon(pixmap);
    msgBox.setText(QString::number(world->peolpe.quantity)+" personas hicieron su buena accion del dia.");
    msgBox.exec();
    showHumans();

}
void WorldWindow::sortCountries(int p){
    for(int c = 0 ; c < 100 ; c++){
        for(int s = c+1; s<100;s++){
            int cant1,cant2;
            std::istringstream iss1 (world->countries[c][p]);
            std::istringstream iss2 (world->countries[s][p]);
            iss1 >> cant1;
            iss2 >> cant2;
            if(cant1<cant2){
                string temp0 = world->countries[c][2];
                string temp1 = world->countries[c][1];
                string temp2 = world->countries[c][0];
                world->countries[c][2] = world->countries[s][2];
                world->countries[c][1] = world->countries[s][1];
                world->countries[c][0] = world->countries[s][0];
                world->countries[s][2] = temp0;
                world->countries[s][1] = temp1;
                world->countries[s][0] = temp2;
            }
        }
    }
}
void WorldWindow::top5sins()
{
    sortCountries(1);
    msgBox.setText("Top 5 paises menos pecadores:\n\n");
    QPixmap pixmap = QPixmap(":/new/prefix1/worldwide.png");
    msgBox.setWindowIcon(pixmap);
    msgBox.setWindowTitle("Top 5");
    for(int c = 0 ; c < 100 ; c++ ){
        if(world->countries[c+5][1] == "0" || c == 94){
            int i = 4;
            while(i>=0){
                if(world->countries[i][1] == "0"){
                    i--;
                    continue;
                }
                msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world->countries[c+i][0]+" "+world->countries[c+i][1]+"\n"));
                i--;
            }
            msgBox.exec();
            break;
        }
    }
}

void WorldWindow::top10GD()
{
    sortCountries(2);
    msgBox.setText("Top 10 paises con buenas acciones:\n\n");
    QPixmap pixmap = QPixmap(":/new/prefix1/worldwide.png");
    msgBox.setWindowIcon(pixmap);
    msgBox.setWindowTitle("Top 10");
    for(int c = 0 ; c < 10 ; c++ ){
        if(world->countries[c][2] == "0"){
            continue;
        }
        msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world->countries[c][0]+" "+world->countries[c][2]+"\n"));
    }
    msgBox.exec();
}

void WorldWindow::top5GD()
{
    sortCountries(2);
    msgBox.setText("Top 5 paises con menos buenas acciones:\n\n");
    QPixmap pixmap = QPixmap(":/new/prefix1/worldwide.png");
    msgBox.setWindowIcon(pixmap);
    msgBox.setWindowTitle("Top 5");
    for(int c = 0 ; c < 100 ; c++ ){
        if(world->countries[c+5][2] == "0" || c == 94){
            int i = 4;
            while(i>=0){
                if(world->countries[i][2] == "0"){
                    i--;
                    continue;
                }
                msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world->countries[c+i][0]+" "+world->countries[c+i][2]+"\n"));
                i--;
            }
            msgBox.exec();
            break;
        }
    }
}

void WorldWindow::showDemon()
{
    DemonWindow *w = new DemonWindow(nullptr,this->hell->demons);
    w->show();
}

void WorldWindow::showFam()
{
    QString id = ui->id->toPlainText();
    Node *searched = this->world->peopleTree->search(id.toInt());
    if(!searched){
        msgBox.setText("No existe ningun humano con ese id ("+id+")");
        msgBox.setWindowTitle("Id incorrecto");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        msgBox.setIcon(QMessageBox::NoIcon);
    }else{
        FamSinsWindow *w = new FamSinsWindow(nullptr);
        w->show();
        w->setWindowTitle(QString::fromStdString(searched->data->family->name));
        w->preOrder(searched->data->family->root);
    }
    ui->id->clear();
}

void WorldWindow::sinsContinent(Node* root)
{
    if(root){
        for(int c = 0 ; c < 6 ; c++){
            if(this->continentsInfo[c][0] == root->data->continent){
                this->continentsInfo[c][1] = std::to_string(stoi(this->continentsInfo[c][1])+root->data->totalGD);
                this->continentsInfo[c][2] = std::to_string(stoi(this->continentsInfo[c][1])+root->data->totalSins);
                break;
            }
        }
        sinsContinent(root->left);
        sinsContinent(root->right);
    }
}
void WorldWindow::showContinentsInfo(){
    for(int c = 0 ; c<5 ; c++){
        this->continentsInfo[c][1] = this->continentsInfo[c][2] = "0";
    }
    sinsContinent(this->world->peopleTree->root);
    msgBox.setText("");
    for(int c = 0 ; c<5 ; c++){
        msgBox.setText(msgBox.text()+QString::fromStdString(this->continentsInfo[c][0]+" "+this->continentsInfo[c][1]+" "+this->continentsInfo[c][2])+"\n");
    }
    msgBox.exec();
}

void WorldWindow::condemn()
{
    this->hell->demons[0]->condemn(this->world->peolpe);
}

void WorldWindow::save()
{
    this->heaven->angels->generateAngels();
    this->heaven->angels->showAngels();
}
void WorldWindow::top10sins()
{
    sortCountries(1);
    msgBox.setText("Top 10 paises más pecadores:\n\n");
    QPixmap pixmap = QPixmap(":/new/prefix1/worldwide.png");
    msgBox.setWindowIcon(pixmap);
    msgBox.setWindowTitle("Top 10");
    for(int c = 0 ; c < 10 ; c++ ){
        if(world->countries[c][1] == "0"){
            continue;
        }
        msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world->countries[c][0]+" "+world->countries[c][1]+"\n"));
    }
    msgBox.exec();
}

void WorldWindow::generatePeople(){
    QString quant = ui->people->toPlainText();
    world->generatePeople(quant.toInt());
    msgBox.setText("Se han agregado "+quant+" personas\nActualmente hay "+QString::number(world->peolpe.quantity));
    msgBox.setWindowTitle("Haciendo bebes!");
    QPixmap pixmap = QPixmap(":/new/prefix1/baby.ico");
    msgBox.setWindowIcon(pixmap);
    msgBox.exec();
    showHumans();
    ui->people->clear();
}

