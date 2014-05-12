#include "welcomescreen.h"
#include "ui_welcomescreen.h"

WelcomeScreen::WelcomeScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeScreen)
{
    ui->setupUi(this);
    QPixmap bkgnd("/home/michaelroberts/Build/MriSegment/src/Implementation/build-gui-Desktop-Debug/background.png");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);
}

WelcomeScreen::~WelcomeScreen()
{
    delete ui;
}

void WelcomeScreen::on_new_pushButton_clicked()
{
    emit nextwindow(LOADHEADER);
    this->close();
}
