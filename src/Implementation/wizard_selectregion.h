#ifndef WIZARD_SELECTREGION_H
#define WIZARD_SELECTREGION_H

#include <QDialog>

namespace Ui {
class wizard_selectregion;
}

class wizard_selectregion : public QDialog
{
    Q_OBJECT

public:
    explicit wizard_selectregion(QWidget *parent = 0);
    ~wizard_selectregion();

private:
    Ui::wizard_selectregion *ui;
};

#endif // WIZARD_SELECTREGION_H
