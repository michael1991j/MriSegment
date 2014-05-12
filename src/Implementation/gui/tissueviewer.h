#ifndef TISSUEVIEWER_H
#define TISSUEVIEWER_H

#include <QWidget>

namespace Ui {
class tissueviewer;
}

class tissueviewer : public QWidget
{
    Q_OBJECT

public:
    explicit tissueviewer(QWidget *parent = 0);
    ~tissueviewer();

private:
    Ui::tissueviewer *ui;
};

#endif // TISSUEVIEWER_H
