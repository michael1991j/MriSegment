#ifndef WIZARD_SELECTIMAGE_H
#define WIZARD_SELECTIMAGE_H

#include <QDialog>
#include <QTabWidget>

namespace Ui {
class wizard_selectimage;
}

class wizard_selectimage : public QDialog
{
    Q_OBJECT

public:
    explicit wizard_selectimage(QWidget *parent = 0);
    ~wizard_selectimage();
signals:
    void nextwindow(int newValue);
private slots:
    void on_pushButton_clicked();

private:
    Ui::wizard_selectimage *ui;
        QTabWidget *tabWidget;
};

#endif // WIZARD_SELECTIMAGE_H
