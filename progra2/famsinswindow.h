#ifndef FAMSINSWINDOW_H
#define FAMSINSWINDOW_H

#include <QMainWindow>
#include "avltree.h"
#include "QListWidget"

namespace Ui {
class FamSinsWindow;
}

class FamSinsWindow : public QMainWindow
{
    Q_OBJECT

public:
    FamSinsWindow(QWidget *parent);
    ~FamSinsWindow();
    void preOrder(Node *root);
    QListWidget *list;

private:
    Ui::FamSinsWindow *ui;
};

#endif // FAMSINSWINDOW_H
