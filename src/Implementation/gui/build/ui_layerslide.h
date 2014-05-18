/********************************************************************************
** Form generated from reading UI file 'layerslide.ui'
**
** Created: Sun May 11 21:55:55 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERSLIDE_H
#define UI_LAYERSLIDE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Layerslide
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QTreeWidget *treeWidget;
    QSpacerItem *verticalSpacer;
    QSlider *horizontalSlider;
    QWidget *widget;

    void setupUi(QWidget *Layerslide)
    {
        if (Layerslide->objectName().isEmpty())
            Layerslide->setObjectName(QString::fromUtf8("Layerslide"));
        Layerslide->resize(724, 643);
        horizontalLayoutWidget_2 = new QWidget(Layerslide);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 440, 721, 201));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView_3 = new QGraphicsView(horizontalLayoutWidget_2);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        horizontalLayout_2->addWidget(graphicsView_3);

        graphicsView_2 = new QGraphicsView(horizontalLayoutWidget_2);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        horizontalLayout_2->addWidget(graphicsView_2);

        graphicsView = new QGraphicsView(horizontalLayoutWidget_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_2->addWidget(graphicsView);

        formLayoutWidget = new QWidget(Layerslide);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 20, 711, 421));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(formLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        formLayout->setWidget(1, QFormLayout::LabelRole, treeWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer);

        horizontalSlider = new QSlider(formLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSlider);

        widget = new QWidget(formLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widget);


        retranslateUi(Layerslide);

        QMetaObject::connectSlotsByName(Layerslide);
    } // setupUi

    void retranslateUi(QWidget *Layerslide)
    {
        Layerslide->setWindowTitle(QApplication::translate("Layerslide", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Layerslide: public Ui_Layerslide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERSLIDE_H
