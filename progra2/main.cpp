#include "mainwindow.h"
#include <QApplication>
#include "jsonparser.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    jsonParser *m = new jsonParser();
    w.show();

    return a.exec();
}
