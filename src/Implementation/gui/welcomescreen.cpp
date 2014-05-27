#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <QFileDialog>
WelcomeScreen::WelcomeScreen(Dataset * Configuration,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeScreen)
{
    this->Configuration = Configuration;
    ui->setupUi(this);
    QPixmap bkgnd("/home/michaelroberts/Build/MriSegment/src/Implementation/gui/background.png");
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
    this->Configuration->destinationpath = ui->OutputPath->text();
    emit nextwindow(LOADHEADER);
    this->close();
}

void WelcomeScreen::on_pushButton_2_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "./",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    this->Configuration->destinationpath = dir;
    this->Configuration->load(dir + "/test.xml");
     emit nextwindow(LOADOLD);
  this->close();
}
