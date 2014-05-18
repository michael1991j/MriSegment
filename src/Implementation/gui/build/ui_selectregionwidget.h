/********************************************************************************
** Form generated from reading UI file 'selectregionwidget.ui'
**
** Created: Wed May 14 06:39:42 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTREGIONWIDGET_H
#define UI_SELECTREGIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selectregionwidget
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QGraphicsView *graphicsView;
    QTreeWidget *treeWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *Selectregionwidget)
    {
        if (Selectregionwidget->objectName().isEmpty())
            Selectregionwidget->setObjectName(QString::fromUtf8("Selectregionwidget"));
        Selectregionwidget->resize(749, 568);
        formLayoutWidget = new QWidget(Selectregionwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 10, 681, 511));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(formLayoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        formLayout->setWidget(0, QFormLayout::FieldRole, graphicsView);

        treeWidget = new QTreeWidget(formLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        formLayout->setWidget(0, QFormLayout::LabelRole, treeWidget);

        pushButton = new QPushButton(Selectregionwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 530, 99, 27));

        retranslateUi(Selectregionwidget);

        QMetaObject::connectSlotsByName(Selectregionwidget);
    } // setupUi

    void retranslateUi(QWidget *Selectregionwidget)
    {
        Selectregionwidget->setWindowTitle(QApplication::translate("Selectregionwidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Selectregionwidget", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Selectregionwidget: public Ui_Selectregionwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTREGIONWIDGET_H
