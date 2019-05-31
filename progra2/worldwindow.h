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
    World *world = new World();
    Hell *hell = new Hell();

    std::string continentsInfo[6][3] = {{"America","0","0"},
                            {"Africa","0","0"},
                            {"Asia","0","0"},
                            {"Europa","0","0"},
                            {"Oceania","0","0"}};

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
    void showDemon();
    void showFam();
    void sinsContinent(Node* root);
    void showContinentsInfo();
private:
};

#endif // WORLDWINDOW_H
