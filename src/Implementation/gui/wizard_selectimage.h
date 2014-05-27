#ifndef WIZARD_SELECTIMAGE_H
#define WIZARD_SELECTIMAGE_H

#include <QDialog>
#include <QTabWidget>
#include <MRIOpenCVSettings.h>
#include <MRICommon.h>
namespace Ui {
class wizard_selectimage;
}

class wizard_selectimage : public QDialog
{
    Q_OBJECT

public:
     wizard_selectimage( MRIOpenCVSettings * settings ,vector<MRICommon *> * Imagesets,  QWidget *parent = 0);
    ~wizard_selectimage();
     vector<MRICommon *> * Imagesets;
     MRIOpenCVSettings * settings;
signals:
    void nextwindow(int newValue);

private slots:
    void on_pushButton_clicked();

private:
    Ui::wizard_selectimage *ui;
        QTabWidget *tabWidget;

};

#endif // WIZARD_SELECTIMAGE_H
