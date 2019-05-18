#ifndef WORLDWINDOW_H
#define WORLDWINDOW_H

#include <QMainWindow>
#include "world.h"
#include "QMessageBox"

namespace Ui {
class WorldWindow;
}

class WorldWindow : public QMainWindow
{
    Q_OBJECT

public:
    World *world;
    QMessageBox msgBox;
    explicit WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();

private slots:
    void generatePeople();
    void generateSins();
    void generateGoodDeeds();

private:
    Ui::WorldWindow *ui;
};

#endif // WORLDWINDOW_H
