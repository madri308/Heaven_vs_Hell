#include "demonwindow.h"
#include "ui_demonwindow.h"
#include "demon.h"

DemonWindow::DemonWindow(QWidget *parent, Demon *list[]) :
    QMainWindow(parent),
    ui(new Ui::DemonWindow)
{
    ui->setupUi(this);

    for(int d = 0 ; d<7 ; d++){
        this->demonsList[d] = list[d];
    }

    connect(ui->next, SIGNAL (released()),this, SLOT (next()));
    connect(ui->prev, SIGNAL (released()),this, SLOT (prev()));
<<<<<<< HEAD

    QShortcut *shortcut1 = new QShortcut(QKeySequence("Right"), this);
    connect(shortcut1, SIGNAL(activated()), this, SLOT(next()));

    QShortcut *shortcut2 = new QShortcut(QKeySequence("right"), this);
    connect(shortcut2, SIGNAL(activated()), this, SLOT(prev()));

=======
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
    showInfo();
}

DemonWindow::~DemonWindow()
{
    delete ui;
}

void DemonWindow::next()
{
    demonC++;
    if(demonC == 7){
        demonC = 0;
    }
    showInfo();

}
void DemonWindow::prev(){
    demonC--;
    if(demonC == -1){
        demonC = 6;
    }
    showInfo();
}
void DemonWindow::showInfo(){
    QPixmap pixmap = QPixmap(this->demonsList[demonC]->image);
    ui->info->setText(this->demonsList[demonC]->name+"\n\n"+this->demonsList[demonC]->sin+"\n\n"+this->demonsList[demonC]->desc);

    ui->demon->setScaledContents(true);
    ui->demon->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->demon->setPixmap(pixmap);
}
