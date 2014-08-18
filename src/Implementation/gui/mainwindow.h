#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wizardcontroller.h>
#include "tissueviewer.h"
#include "layerslide.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    wizardController * controller ;
     Layerslide * controllerlayerslider ;
    tissueviewer * viewer;
private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;
public slots:
    void wizardone(int Nextstate);
};

#endif // MAINWINDOW_H
