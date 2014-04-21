#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mriscene.h"
#include "MRICommon.h"
#include "mrimanualscene.h"
#include "recordhandel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ProcessDicom(char * path );
     MriScene * scene;
     MRICommon * MRIData;
     MriManuelScene * Manualscene;
     RecordHandel * Datahandel;
public slots:


private slots:
    void on_pushButton_3_clicked();
    void On_tree_itemclicked();

    void on_LoadDirforManual_clicked();

    void on_zoomin_clicked();

    void on_zoomout_clicked();

    void on_Clear_clicked();

    void on_outputpcd_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
