#ifndef SELECTREGIONWIDGET_H
#define SELECTREGIONWIDGET_H

#include <QWidget>

namespace Ui {
class Selectregionwidget;
}

class Selectregionwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Selectregionwidget(QWidget *parent = 0);
    ~Selectregionwidget();

private:
    Ui::Selectregionwidget *ui;
};

#endif // SELECTREGIONWIDGET_H
