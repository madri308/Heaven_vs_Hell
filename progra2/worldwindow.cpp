#include "worldwindow.h"
#include "ui_worldwindow.h"
#include "iostream"
#include "sstream"
#include "QMessageBox"
#include "QListWidget"

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
}

WorldWindow::~WorldWindow()
{
    delete ui;
}
void WorldWindow::showHumans(){
    ui->humansCount->setText("Personas actualmente: "+QString::number(world.peolpe.quantity));
    Node *temp = world.peolpe.first;
    QListWidget *list = ui->list;
    list->clear();
    while(temp){
        QVBoxLayout *container = new QVBoxLayout;

        QLabel *l1 = new QLabel;
        l1->setText(QString::fromStdString(temp->data->name));
        container->addWidget(l1);

        list->addItem(QString::number(temp->data->id));
        list->addItem(QString::fromStdString(temp->data->name+" "+(temp->data->surname)));
        list->addItem(QString::fromStdString(temp->data->country));
        list->addItem(QString::fromStdString(temp->data->religion));
        list->addItem(QString::fromStdString(temp->data->job));
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
        list->addItem("----------------------");

        temp = temp->next;
    }
}
void WorldWindow::generateSins(){
    Node *temp = world.peolpe.first;   //EMPIEZA POR LA PRIMERA PERSONA
    srand(time(NULL));
    while(temp){    //MIENTRAS EXISTAN MAS PERSONAS.
        //GENERA LOS NUMEROS RANDOM PARA LOS PECADOS EN UNA LISTA
        int totalSins = 0;
        int percetages[7] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
        for(int t = 0; t<7 ; t++){  //CICLO PARA ESTABLECER PECADOS.
            //LE ASIGNA A CADA PECADO DE LA PERSONA SU PORCENTAJE RANDOM
            temp->data->sins[t][1] = to_string(stoi(temp->data->sins[t][1])+percetages[t]);
            totalSins = totalSins + percetages[t];
            for(Human child:temp->data->childrens){ //RECORRE LA LISTA DE HIJOS
                //Y A SUS PECADOS LE SUMA EL 50% DEL PAPA.
                child.sins[t][1] = to_string(stoi(temp->data->sins[t][1])+(percetages[t]*50/100));
                //totalSins = totalSins + percetages[t]*50/100;
                for(Human child:child.childrens){   //RECORRE LOS HIJOS DEL HIJO(NIETOS)
                    //Y A SUS PECADOS LES SUMA EL 25% DEL PAPA DEL PAPA(EL ABUELO)
                    totalSins = totalSins + percetages[t]*25/100;
                    //child.sins[t][1] = to_string(stoi(temp->data->sins[t][1])+(percetages[t]*25/100));
                }
            }
        }
        for(int country = 0; country < 100; country++){
            if(temp->data->country == this->world.countries[country][0]){
                int number;
                std::istringstream iss (this->world.countries[country][1]);
                iss >> number;
                this->world.countries[country][1] = to_string(number+totalSins);
                cout<<this->world.countries[country][1]<<endl;
            }
        }
        temp = temp->next;  //PASA A LA SIGUIENTE PERSONA
    }
    msgBox.setWindowTitle("Satanas haciendo de las suyas.");
    QPixmap pixmap = QPixmap(":/new/prefix1/demon.ico");
    msgBox.setWindowIcon(pixmap);
    msgBox.setText(QString::number(world.peolpe.quantity)+" personas han pecado de manera exitosa.");
    msgBox.exec();
    showHumans();
}
void WorldWindow::generateGoodDeeds(){
    Node *temp = world.peolpe.first;
    srand(time(NULL));
    while(temp){
        int totalGD = 0;
        int percetages[7] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
        for(int t = 0; t<7 ; t++){
            temp->data->goodDeeds[t][1] = to_string(stoi(temp->data->goodDeeds[t][1])+percetages[t]);
            totalGD = totalGD + percetages[t];
        }
        for(int country = 0; country < 100; country++){
            if(temp->data->country == this->world.countries[country][0]){
                int number;
                std::istringstream iss (this->world.countries[country][2]);
                iss >> number;
                this->world.countries[country][2] = to_string(number+totalGD);
                cout<<this->world.countries[country][2]<<endl;
            }
        }
        temp = temp->next;
    }
    msgBox.setWindowTitle("Gracias a Dios.");
    QPixmap pixmap = QPixmap(":/new/prefix1/please.ico");
    msgBox.setWindowIcon(pixmap);
    msgBox.setText(QString::number(world.peolpe.quantity)+" personas hicieron su buena accion del dia.");
    msgBox.exec();
    showHumans();

}
void WorldWindow::sortCountries(int p){
    for(int c = 0 ; c < 100 ; c++){
        for(int s = c+1; s<100;s++){
            int cant1,cant2;
            std::istringstream iss1 (world.countries[c][p]);
            std::istringstream iss2 (world.countries[s][p]);
            iss1 >> cant1;
            iss2 >> cant2;
            if(cant1<cant2){
                string temp0 = world.countries[c][2];
                string temp1 = world.countries[c][1];
                string temp2 = world.countries[c][0];
                world.countries[c][2] = world.countries[s][2];
                world.countries[c][1] = world.countries[s][1];
                world.countries[c][0] = world.countries[s][0];
                world.countries[s][2] = temp0;
                world.countries[s][1] = temp1;
                world.countries[s][0] = temp2;
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
        if(world.countries[c+5][1] == "0"){
            int i = 4;
            while(i>=0){
                if(world.countries[c][1] == "0"){
                    continue;
                }
                msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world.countries[c+i][0]+" "+world.countries[c+i][1]+"\n"));
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
        if(world.countries[c][2] == "0"){
            continue;
        }
        msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world.countries[c][0]+" "+world.countries[c][2]+"\n"));
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
        if(world.countries[c+5][2] == "0"){
            int i = 4;
            while(i>=0){
                if(world.countries[c][2] == "0"){
                    continue;
                }
                msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world.countries[c+i][0]+" "+world.countries[c+i][2]+"\n"));
                i--;
            }
            msgBox.exec();
            break;
        }
    }
}
void WorldWindow::top10sins()
{
    sortCountries(1);
    msgBox.setText("Top 10 paises más pecadores:\n\n");
    QPixmap pixmap = QPixmap(":/new/prefix1/worldwide.png");
    msgBox.setWindowIcon(pixmap);
    msgBox.setWindowTitle("Top 10");
    for(int c = 0 ; c < 10 ; c++ ){
        if(world.countries[c][1] == "0"){
            continue;
        }
        msgBox.setText(QString::fromStdString(msgBox.text().toStdString()+" "+world.countries[c][0]+" "+world.countries[c][1]+"\n"));
    }
    msgBox.exec();
}

void WorldWindow::generatePeople(){
    QString quant = ui->people->toPlainText();
    world.generatePeople(quant.toInt());
    msgBox.setText("Se han agregado "+quant+" personas\nActualmente hay "+QString::number(world.peolpe.quantity));
    msgBox.setWindowTitle("Haciendo bebes!");
    QPixmap pixmap = QPixmap(":/new/prefix1/baby.ico");
    msgBox.setWindowIcon(pixmap);
    msgBox.exec();
    showHumans();
    ui->people->clear();
}

