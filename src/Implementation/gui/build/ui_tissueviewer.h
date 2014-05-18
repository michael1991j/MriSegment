/********************************************************************************
** Form generated from reading UI file 'tissueviewer.ui'
**
** Created: Wed May 14 12:14:22 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TISSUEVIEWER_H
#define UI_TISSUEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_tissueviewer
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVTKWidget *qvtkWidget;

    void setupUi(QWidget *tissueviewer)
    {
        if (tissueviewer->objectName().isEmpty())
            tissueviewer->setObjectName(QString::fromUtf8("tissueviewer"));
        tissueviewer->resize(763, 605);
        horizontalLayoutWidget = new QWidget(tissueviewer);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 751, 571));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(horizontalLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(200, 0));
        qvtkWidget = new QVTKWidget(widget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(10, 0, 691, 561));
        qvtkWidget->setMinimumSize(QSize(0, 100));

        horizontalLayout->addWidget(widget);


        retranslateUi(tissueviewer);

        QMetaObject::connectSlotsByName(tissueviewer);
    } // setupUi

    void retranslateUi(QWidget *tissueviewer)
    {
        tissueviewer->setWindowTitle(QApplication::translate("tissueviewer", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class tissueviewer: public Ui_tissueviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TISSUEVIEWER_H
