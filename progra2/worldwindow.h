#ifndef WORLDWINDOW_H
#define WORLDWINDOW_H

#include <QMainWindow>
#include "world.h"
#include "QMessageBox"
#include "QLabel"

namespace Ui {
class WorldWindow;
}

class WorldWindow : public QMainWindow
{
    Q_OBJECT

public:
    World world;
    QMessageBox msgBox;
    explicit WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();
    void showHumans();
    Ui::WorldWindow *ui;

private slots:
    void generatePeople();
    void generateSins();
    void generateGoodDeeds();
    void top10();

private:
};

#endif // WORLDWINDOW_H
