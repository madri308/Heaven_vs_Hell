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
    void sortCountries(int p);
    Ui::WorldWindow *ui;

private slots:
    void generatePeople();
    void generateSins();
    void generateGoodDeeds();
    void top10sins();
    void top5sins();
    void top10GD();
    void top5GD();
private:
};

#endif // WORLDWINDOW_H
