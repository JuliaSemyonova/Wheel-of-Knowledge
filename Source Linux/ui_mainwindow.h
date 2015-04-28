/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 13 01:10:54 2015
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
#include <QtGui/QDial>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *TurnTheWheel;
    QWidget *centralWidget;
    QPushButton *pushButton_Turn;
    QGraphicsView *graphicsView_Wheel;
    QDial *dial;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(402, 475);
        TurnTheWheel = new QAction(MainWindow);
        TurnTheWheel->setObjectName(QString::fromUtf8("TurnTheWheel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        pushButton_Turn = new QPushButton(centralWidget);
        pushButton_Turn->setObjectName(QString::fromUtf8("pushButton_Turn"));
        pushButton_Turn->setGeometry(QRect(130, 410, 151, 31));
        graphicsView_Wheel = new QGraphicsView(centralWidget);
        graphicsView_Wheel->setObjectName(QString::fromUtf8("graphicsView_Wheel"));
        graphicsView_Wheel->setGeometry(QRect(0, 0, 401, 401));
        sizePolicy.setHeightForWidth(graphicsView_Wheel->sizePolicy().hasHeightForWidth());
        graphicsView_Wheel->setSizePolicy(sizePolicy);
        dial = new QDial(centralWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setEnabled(false);
        dial->setGeometry(QRect(153, 160, 91, 81));
        dial->setMaximum(100);
        dial->setValue(90);
        dial->setSliderPosition(90);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        TurnTheWheel->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214 \320\221\320\260\321\200\320\260\320\261\320\260\320\275", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        TurnTheWheel->setToolTip(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214 \320\221\320\260\321\200\320\260\320\261\320\260\320\275", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_Turn->setText(QApplication::translate("MainWindow", "Turn the wheel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
