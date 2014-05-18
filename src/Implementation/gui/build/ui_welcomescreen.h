/********************************************************************************
** Form generated from reading UI file 'welcomescreen.ui'
**
** Created: Thu May 15 13:18:56 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMESCREEN_H
#define UI_WELCOMESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomeScreen
{
public:
    QPushButton *new_pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *WelcomeScreen)
    {
        if (WelcomeScreen->objectName().isEmpty())
            WelcomeScreen->setObjectName(QString::fromUtf8("WelcomeScreen"));
        WelcomeScreen->setWindowModality(Qt::ApplicationModal);
        WelcomeScreen->resize(676, 492);
        WelcomeScreen->setAutoFillBackground(false);
        WelcomeScreen->setStyleSheet(QString::fromUtf8("\342\200\234background-image: /home/michaelroberts/Build/MriSegment/src/Implementation/build-gui-Desktop-Debug/background.png\342\200\235"));
        new_pushButton = new QPushButton(WelcomeScreen);
        new_pushButton->setObjectName(QString::fromUtf8("new_pushButton"));
        new_pushButton->setGeometry(QRect(190, 430, 99, 27));
        pushButton_2 = new QPushButton(WelcomeScreen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 430, 99, 27));
        label = new QLabel(WelcomeScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 591, 231));
        QPalette palette;
        QBrush brush(QColor(255, 195, 73, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Pacifico"));
        font.setPointSize(48);
        label->setFont(font);

        retranslateUi(WelcomeScreen);

        QMetaObject::connectSlotsByName(WelcomeScreen);
    } // setupUi

    void retranslateUi(QDialog *WelcomeScreen)
    {
        WelcomeScreen->setWindowTitle(QApplication::translate("WelcomeScreen", "Welcome Screen", 0, QApplication::UnicodeUTF8));
        new_pushButton->setText(QApplication::translate("WelcomeScreen", "Create New", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("WelcomeScreen", "Open", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WelcomeScreen", "<html><head/><body><p align=\"center\"><span style=\" color:#e6c12c;\">MRI Segmentation </span></p><p align=\"center\"><span style=\" color:#e6c12c;\">Tool</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WelcomeScreen: public Ui_WelcomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMESCREEN_H
