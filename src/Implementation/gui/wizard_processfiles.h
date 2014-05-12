#ifndef WIZARD_PROCESSFILES_H
#define WIZARD_PROCESSFILES_H

#include <QDialog>

namespace Ui {
class Wizard_processfiles;
}

class Wizard_processfiles : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard_processfiles(QWidget *parent = 0);
    ~Wizard_processfiles();

private:
    Ui::Wizard_processfiles *ui;
};

#endif // WIZARD_PROCESSFILES_H
