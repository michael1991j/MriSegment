#ifndef WIZARD_LOADIMAGES_H
#define WIZARD_LOADIMAGES_H

#include <QDialog>

namespace Ui {
class Wizard_Loadimages;
}

class Wizard_Loadimages : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard_Loadimages(QWidget *parent = 0);
    ~Wizard_Loadimages();
signals:
    void nextwindow(int newValue);

private slots:
    void on_Load_SPGR_button_clicked();

    void on_Load_wcube_button_clicked();

    void on_Load_fcube_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Wizard_Loadimages *ui;
};

#endif // WIZARD_LOADIMAGES_H
