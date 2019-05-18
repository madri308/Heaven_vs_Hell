#ifndef WORLDWINDOW_H
#define WORLDWINDOW_H

#include <QMainWindow>

namespace Ui {
class WorldWindow;
}

class WorldWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();

private:
    Ui::WorldWindow *ui;
};

#endif // WORLDWINDOW_H
