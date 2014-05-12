#ifndef LAYERSLIDE_H
#define LAYERSLIDE_H

#include <QWidget>

namespace Ui {
class Layerslide;
}

class Layerslide : public QWidget
{
    Q_OBJECT

public:
    explicit Layerslide(QWidget *parent = 0);
    ~Layerslide();

private:
    Ui::Layerslide *ui;
};

#endif // LAYERSLIDE_H
