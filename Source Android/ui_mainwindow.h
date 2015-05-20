/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(402, 475);
        TurnTheWheel = new QAction(MainWindow);
        TurnTheWheel->setObjectName(QStringLiteral("TurnTheWheel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        pushButton_Turn = new QPushButton(centralWidget);
        pushButton_Turn->setObjectName(QStringLiteral("pushButton_Turn"));
        pushButton_Turn->setGeometry(QRect(130, 410, 151, 31));
        graphicsView_Wheel = new QGraphicsView(centralWidget);
        graphicsView_Wheel->setObjectName(QStringLiteral("graphicsView_Wheel"));
        graphicsView_Wheel->setGeometry(QRect(0, 0, 401, 401));
        sizePolicy.setHeightForWidth(graphicsView_Wheel->sizePolicy().hasHeightForWidth());
        graphicsView_Wheel->setSizePolicy(sizePolicy);
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setEnabled(false);
        dial->setGeometry(QRect(153, 160, 91, 81));
        dial->setMaximum(100);
        dial->setValue(90);
        dial->setSliderPosition(90);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        TurnTheWheel->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214 \320\221\320\260\321\200\320\260\320\261\320\260\320\275", 0));
#ifndef QT_NO_TOOLTIP
        TurnTheWheel->setToolTip(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214 \320\221\320\260\321\200\320\260\320\261\320\260\320\275", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Turn->setText(QApplication::translate("MainWindow", "Turn the wheel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
