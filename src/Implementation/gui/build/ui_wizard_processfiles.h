/********************************************************************************
** Form generated from reading UI file 'wizard_processfiles.ui'
**
** Created: Thu May 15 13:18:56 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_PROCESSFILES_H
#define UI_WIZARD_PROCESSFILES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wizard_processfiles
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QProgressBar *progressBar_femers;
    QLabel *label_3;
    QProgressBar *progressBar_femert;
    QLabel *label_4;
    QProgressBar *progressBar_cartc;
    QLabel *label_5;
    QProgressBar *progressBar_tibiat;
    QLabel *label_7;
    QProgressBar *progressBar_petellat;
    QLabel *label_11;
    QFrame *line;
    QLabel *label_2;
    QFrame *line_2;
    QProgressBar *progressBar_femur;
    QLabel *label_6;
    QProgressBar *progressBar_cartilage;
    QLabel *label_8;
    QProgressBar *progressBar_patella;
    QLabel *label_9;
    QProgressBar *progressBar_tibia;
    QLabel *label_10;

    void setupUi(QDialog *Wizard_processfiles)
    {
        if (Wizard_processfiles->objectName().isEmpty())
            Wizard_processfiles->setObjectName(QString::fromUtf8("Wizard_processfiles"));
        Wizard_processfiles->resize(764, 427);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        Wizard_processfiles->setPalette(palette);
        formLayoutWidget = new QWidget(Wizard_processfiles);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 20, 651, 429));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        progressBar_femers = new QProgressBar(formLayoutWidget);
        progressBar_femers->setObjectName(QString::fromUtf8("progressBar_femers"));
        progressBar_femers->setValue(0);

        formLayout->setWidget(1, QFormLayout::LabelRole, progressBar_femers);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_3);

        progressBar_femert = new QProgressBar(formLayoutWidget);
        progressBar_femert->setObjectName(QString::fromUtf8("progressBar_femert"));
        progressBar_femert->setValue(0);

        formLayout->setWidget(2, QFormLayout::LabelRole, progressBar_femert);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_4);

        progressBar_cartc = new QProgressBar(formLayoutWidget);
        progressBar_cartc->setObjectName(QString::fromUtf8("progressBar_cartc"));
        progressBar_cartc->setValue(0);

        formLayout->setWidget(3, QFormLayout::LabelRole, progressBar_cartc);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_5);

        progressBar_tibiat = new QProgressBar(formLayoutWidget);
        progressBar_tibiat->setObjectName(QString::fromUtf8("progressBar_tibiat"));
        progressBar_tibiat->setValue(0);

        formLayout->setWidget(4, QFormLayout::LabelRole, progressBar_tibiat);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_7);

        progressBar_petellat = new QProgressBar(formLayoutWidget);
        progressBar_petellat->setObjectName(QString::fromUtf8("progressBar_petellat"));
        progressBar_petellat->setValue(0);

        formLayout->setWidget(5, QFormLayout::LabelRole, progressBar_petellat);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_11);

        line = new QFrame(formLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(6, QFormLayout::LabelRole, line);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_2);

        line_2 = new QFrame(formLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(9, QFormLayout::LabelRole, line_2);

        progressBar_femur = new QProgressBar(formLayoutWidget);
        progressBar_femur->setObjectName(QString::fromUtf8("progressBar_femur"));
        progressBar_femur->setValue(0);

        formLayout->setWidget(10, QFormLayout::LabelRole, progressBar_femur);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(10, QFormLayout::FieldRole, label_6);

        progressBar_cartilage = new QProgressBar(formLayoutWidget);
        progressBar_cartilage->setObjectName(QString::fromUtf8("progressBar_cartilage"));
        progressBar_cartilage->setValue(0);

        formLayout->setWidget(11, QFormLayout::LabelRole, progressBar_cartilage);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(11, QFormLayout::FieldRole, label_8);

        progressBar_patella = new QProgressBar(formLayoutWidget);
        progressBar_patella->setObjectName(QString::fromUtf8("progressBar_patella"));
        progressBar_patella->setValue(0);

        formLayout->setWidget(12, QFormLayout::LabelRole, progressBar_patella);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(12, QFormLayout::FieldRole, label_9);

        progressBar_tibia = new QProgressBar(formLayoutWidget);
        progressBar_tibia->setObjectName(QString::fromUtf8("progressBar_tibia"));
        progressBar_tibia->setValue(0);

        formLayout->setWidget(13, QFormLayout::LabelRole, progressBar_tibia);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(13, QFormLayout::FieldRole, label_10);


        retranslateUi(Wizard_processfiles);

        QMetaObject::connectSlotsByName(Wizard_processfiles);
    } // setupUi

    void retranslateUi(QDialog *Wizard_processfiles)
    {
        Wizard_processfiles->setWindowTitle(QApplication::translate("Wizard_processfiles", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Wizard_processfiles", "Perform segment and labeling", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Wizard_processfiles", "Detecting the Femer Via Sagittal", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Wizard_processfiles", "Detecting the Femer Via Transversal", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Wizard_processfiles", "Detecting the Cartilage Via Corronial", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Wizard_processfiles", "Detecting the Tibia Via Transversal", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Wizard_processfiles", "Detectinv the Patella", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Wizard_processfiles", "Peforming Datafusion and downsampling", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Wizard_processfiles", "Femur", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Wizard_processfiles", "Cartilage", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Wizard_processfiles", "Patella", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Wizard_processfiles", "Tibia", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Wizard_processfiles: public Ui_Wizard_processfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARD_PROCESSFILES_H
