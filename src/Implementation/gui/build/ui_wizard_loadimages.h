/********************************************************************************
** Form generated from reading UI file 'wizard_loadimages.ui'
**
** Created: Thu May 15 13:18:56 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_LOADIMAGES_H
#define UI_WIZARD_LOADIMAGES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wizard_Loadimages
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_spgrw;
    QPushButton *Load_SPGR_button_SPGRW;
    QLabel *label_3;
    QLineEdit *lineEdit_spgrf;
    QPushButton *pushButton_spgrf;
    QLabel *label_2;
    QLineEdit *lineEdit_cubew;
    QPushButton *Load_wcube_button;
    QLabel *label_7;
    QLineEdit *lineEdit_cubef;
    QPushButton *Load_fcube_button;
    QLabel *label_5;
    QProgressBar *progressBar_spgrf;
    QLabel *label_4;
    QProgressBar *progressBar_cubew;
    QPushButton *pushButton;
    QLabel *label_6;
    QProgressBar *progressBar_cubef;
    QLabel *label_8;
    QProgressBar *progressBar_SPGRW;

    void setupUi(QDialog *Wizard_Loadimages)
    {
        if (Wizard_Loadimages->objectName().isEmpty())
            Wizard_Loadimages->setObjectName(QString::fromUtf8("Wizard_Loadimages"));
        Wizard_Loadimages->resize(519, 623);
        formLayoutWidget = new QWidget(Wizard_Loadimages);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 521, 621));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(10, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_spgrw = new QLineEdit(formLayoutWidget);
        lineEdit_spgrw->setObjectName(QString::fromUtf8("lineEdit_spgrw"));
        lineEdit_spgrw->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_spgrw);

        Load_SPGR_button_SPGRW = new QPushButton(formLayoutWidget);
        Load_SPGR_button_SPGRW->setObjectName(QString::fromUtf8("Load_SPGR_button_SPGRW"));
        Load_SPGR_button_SPGRW->setMinimumSize(QSize(100, 0));
        Load_SPGR_button_SPGRW->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, Load_SPGR_button_SPGRW);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_spgrf = new QLineEdit(formLayoutWidget);
        lineEdit_spgrf->setObjectName(QString::fromUtf8("lineEdit_spgrf"));
        lineEdit_spgrf->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(4, QFormLayout::LabelRole, lineEdit_spgrf);

        pushButton_spgrf = new QPushButton(formLayoutWidget);
        pushButton_spgrf->setObjectName(QString::fromUtf8("pushButton_spgrf"));
        pushButton_spgrf->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton_spgrf);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_2);

        lineEdit_cubew = new QLineEdit(formLayoutWidget);
        lineEdit_cubew->setObjectName(QString::fromUtf8("lineEdit_cubew"));
        lineEdit_cubew->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(8, QFormLayout::LabelRole, lineEdit_cubew);

        Load_wcube_button = new QPushButton(formLayoutWidget);
        Load_wcube_button->setObjectName(QString::fromUtf8("Load_wcube_button"));
        Load_wcube_button->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(8, QFormLayout::FieldRole, Load_wcube_button);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_7);

        lineEdit_cubef = new QLineEdit(formLayoutWidget);
        lineEdit_cubef->setObjectName(QString::fromUtf8("lineEdit_cubef"));
        lineEdit_cubef->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(11, QFormLayout::LabelRole, lineEdit_cubef);

        Load_fcube_button = new QPushButton(formLayoutWidget);
        Load_fcube_button->setObjectName(QString::fromUtf8("Load_fcube_button"));
        Load_fcube_button->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(11, QFormLayout::FieldRole, Load_fcube_button);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(15, QFormLayout::LabelRole, label_5);

        progressBar_spgrf = new QProgressBar(formLayoutWidget);
        progressBar_spgrf->setObjectName(QString::fromUtf8("progressBar_spgrf"));
        progressBar_spgrf->setMinimumSize(QSize(200, 0));
        progressBar_spgrf->setMaximumSize(QSize(200, 16777215));
        progressBar_spgrf->setValue(0);

        formLayout->setWidget(16, QFormLayout::LabelRole, progressBar_spgrf);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(17, QFormLayout::LabelRole, label_4);

        progressBar_cubew = new QProgressBar(formLayoutWidget);
        progressBar_cubew->setObjectName(QString::fromUtf8("progressBar_cubew"));
        progressBar_cubew->setMinimumSize(QSize(200, 0));
        progressBar_cubew->setMaximumSize(QSize(27215, 16777215));
        progressBar_cubew->setValue(0);

        formLayout->setWidget(18, QFormLayout::LabelRole, progressBar_cubew);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(18, QFormLayout::FieldRole, pushButton);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(19, QFormLayout::LabelRole, label_6);

        progressBar_cubef = new QProgressBar(formLayoutWidget);
        progressBar_cubef->setObjectName(QString::fromUtf8("progressBar_cubef"));
        progressBar_cubef->setMinimumSize(QSize(200, 0));
        progressBar_cubef->setValue(0);

        formLayout->setWidget(20, QFormLayout::LabelRole, progressBar_cubef);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(21, QFormLayout::LabelRole, label_8);

        progressBar_SPGRW = new QProgressBar(formLayoutWidget);
        progressBar_SPGRW->setObjectName(QString::fromUtf8("progressBar_SPGRW"));
        progressBar_SPGRW->setMinimumSize(QSize(200, 0));
        progressBar_SPGRW->setValue(0);

        formLayout->setWidget(22, QFormLayout::LabelRole, progressBar_SPGRW);


        retranslateUi(Wizard_Loadimages);

        QMetaObject::connectSlotsByName(Wizard_Loadimages);
    } // setupUi

    void retranslateUi(QDialog *Wizard_Loadimages)
    {
        Wizard_Loadimages->setWindowTitle(QApplication::translate("Wizard_Loadimages", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Wizard_Loadimages", "Select SPGR Water Images", 0, QApplication::UnicodeUTF8));
        Load_SPGR_button_SPGRW->setText(QApplication::translate("Wizard_Loadimages", "Select Directory", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Wizard_Loadimages", "Select Fat  SPGR", 0, QApplication::UnicodeUTF8));
        pushButton_spgrf->setText(QApplication::translate("Wizard_Loadimages", "Select Directory", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Wizard_Loadimages", "Select Cube  water", 0, QApplication::UnicodeUTF8));
        Load_wcube_button->setText(QApplication::translate("Wizard_Loadimages", "Select Directory", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Wizard_Loadimages", "Select Cub Fat", 0, QApplication::UnicodeUTF8));
        Load_fcube_button->setText(QApplication::translate("Wizard_Loadimages", "Select Directory", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Wizard_Loadimages", "Load Status for SPGR fat", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Wizard_Loadimages", "Load Status for Cube Water", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Wizard_Loadimages", "Load Images", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Wizard_Loadimages", "Load Status for Cube Fat", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Wizard_Loadimages", "Load Status  fo SPGR Water", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Wizard_Loadimages: public Ui_Wizard_Loadimages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARD_LOADIMAGES_H
