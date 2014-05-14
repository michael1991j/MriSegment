/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 14 00:45:55 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGraphicsView *myGraphicsView;
    QLabel *label_2;
    QTextBrowser *textBrowser_2;
    QListView *listView;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QTreeWidget *treeWidget;
    QPushButton *LoadDirforManual;
    QGraphicsView *ManualGraphicView;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *zoomin;
    QPushButton *zoomout;
    QPushButton *Clear;
    QPushButton *outputpcd;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1204, 953);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1211, 901));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        myGraphicsView = new QGraphicsView(tab);
        myGraphicsView->setObjectName(QString::fromUtf8("myGraphicsView"));
        myGraphicsView->setGeometry(QRect(10, 40, 911, 641));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 690, 66, 17));
        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(80, 710, 821, 151));
        listView = new QListView(tab);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(930, 100, 256, 192));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(930, 60, 98, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 80, 201, 511));
        LoadDirforManual = new QPushButton(tab_2);
        LoadDirforManual->setObjectName(QString::fromUtf8("LoadDirforManual"));
        LoadDirforManual->setGeometry(QRect(20, 30, 98, 27));
        ManualGraphicView = new QGraphicsView(tab_2);
        ManualGraphicView->setObjectName(QString::fromUtf8("ManualGraphicView"));
        ManualGraphicView->setGeometry(QRect(230, 80, 921, 511));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(230, 631, 921, 191));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 650, 98, 27));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 610, 66, 17));
        progressBar = new QProgressBar(tab_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(130, 30, 118, 23));
        progressBar->setValue(24);
        zoomin = new QPushButton(tab_2);
        zoomin->setObjectName(QString::fromUtf8("zoomin"));
        zoomin->setGeometry(QRect(550, 40, 51, 27));
        zoomout = new QPushButton(tab_2);
        zoomout->setObjectName(QString::fromUtf8("zoomout"));
        zoomout->setGeometry(QRect(620, 40, 51, 27));
        Clear = new QPushButton(tab_2);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(430, 40, 98, 27));
        outputpcd = new QPushButton(tab_2);
        outputpcd->setObjectName(QString::fromUtf8("outputpcd"));
        outputpcd->setGeometry(QRect(310, 600, 98, 27));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1204, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Output:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "AddRegion", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "RegionSelection", 0, QApplication::UnicodeUTF8));
        LoadDirforManual->setText(QApplication::translate("MainWindow", "LoadDir", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "SaveFile", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Output:", 0, QApplication::UnicodeUTF8));
        zoomin->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        zoomout->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        Clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        outputpcd->setText(QApplication::translate("MainWindow", "Output", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ManualSegmentation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
