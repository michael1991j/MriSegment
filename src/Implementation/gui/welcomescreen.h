#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QDialog>
#include "wizardcontroller.h"
namespace Ui {
class WelcomeScreen;
}

class WelcomeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeScreen(QWidget *parent = 0);
    ~WelcomeScreen();

private slots:
    void on_new_pushButton_clicked();

signals:
    void nextwindow(int newValue);

private:
    Ui::WelcomeScreen *ui;
};

#endif // WELCOMESCREEN_H
