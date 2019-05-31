#ifndef DEMONWINDOW_H
#define DEMONWINDOW_H

#include <QMainWindow>
#include "demon.h"

namespace Ui {
class DemonWindow;
}

class DemonWindow : public QMainWindow
{
    Q_OBJECT

public:
    DemonWindow(QWidget *parent, Demon *List[]);
    ~DemonWindow();
    void setInfo(Ui::DemonWindow ui);
    Demon *demonsList[7];
    int demonC = 0;
    void showInfo();
private slots:
    void next();
    void prev();
    void showHeap();
private:
    Ui::DemonWindow *ui;
};

#endif // DEMONWINDOW_H
