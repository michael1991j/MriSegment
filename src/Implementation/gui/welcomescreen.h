#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QDialog>
#include "wizardcontroller.h"
#include "dataset.h"
namespace Ui {
class WelcomeScreen;
}

class WelcomeScreen : public QDialog
{
    Q_OBJECT

public:
     WelcomeScreen(Dataset * Configuration,QWidget *parent = 0);
    ~WelcomeScreen();
    Dataset * Configuration;
private slots:
    void on_new_pushButton_clicked();


    void on_pushButton_2_clicked();

signals:
    void nextwindow(int newValue);

private:
    Ui::WelcomeScreen *ui;
};

#endif // WELCOMESCREEN_H
