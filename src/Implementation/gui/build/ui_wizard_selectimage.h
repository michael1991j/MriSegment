/********************************************************************************
** Form generated from reading UI file 'wizard_selectimage.ui'
**
** Created: Sun May 11 21:55:55 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_SELECTIMAGE_H
#define UI_WIZARD_SELECTIMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wizard_selectimage
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;

    void setupUi(QDialog *wizard_selectimage)
    {
        if (wizard_selectimage->objectName().isEmpty())
            wizard_selectimage->setObjectName(QString::fromUtf8("wizard_selectimage"));
        wizard_selectimage->resize(832, 656);
        pushButton = new QPushButton(wizard_selectimage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 620, 99, 27));
        formLayoutWidget = new QWidget(wizard_selectimage);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 761, 401));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(wizard_selectimage);

        QMetaObject::connectSlotsByName(wizard_selectimage);
    } // setupUi

    void retranslateUi(QDialog *wizard_selectimage)
    {
        wizard_selectimage->setWindowTitle(QApplication::translate("wizard_selectimage", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("wizard_selectimage", "Next", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wizard_selectimage: public Ui_wizard_selectimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARD_SELECTIMAGE_H
