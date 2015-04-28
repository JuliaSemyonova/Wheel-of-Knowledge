/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QLabel *label_Obl;
    QLabel *label_Question;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label_QuestionNum;
    QLabel *label_CheckAnswer;
    QRadioButton *radioButton_5;
    QPushButton *pushButton_Check;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(620, 512);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 470, 121, 31));
        label_Obl = new QLabel(Dialog);
        label_Obl->setObjectName(QStringLiteral("label_Obl"));
        label_Obl->setGeometry(QRect(10, 10, 261, 16));
        label_Question = new QLabel(Dialog);
        label_Question->setObjectName(QStringLiteral("label_Question"));
        label_Question->setGeometry(QRect(10, 30, 601, 121));
        label_Question->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_Question->setWordWrap(true);
        radioButton_1 = new QRadioButton(Dialog);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setGeometry(QRect(10, 150, 501, 18));
        radioButton_2 = new QRadioButton(Dialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 175, 501, 18));
        radioButton_3 = new QRadioButton(Dialog);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 200, 501, 18));
        radioButton_4 = new QRadioButton(Dialog);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 225, 501, 18));
        label_QuestionNum = new QLabel(Dialog);
        label_QuestionNum->setObjectName(QStringLiteral("label_QuestionNum"));
        label_QuestionNum->setGeometry(QRect(280, 10, 251, 16));
        label_CheckAnswer = new QLabel(Dialog);
        label_CheckAnswer->setObjectName(QStringLiteral("label_CheckAnswer"));
        label_CheckAnswer->setEnabled(true);
        label_CheckAnswer->setGeometry(QRect(10, 270, 601, 191));
        label_CheckAnswer->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_CheckAnswer->setWordWrap(true);
        radioButton_5 = new QRadioButton(Dialog);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 250, 501, 18));
        pushButton_Check = new QPushButton(Dialog);
        pushButton_Check->setObjectName(QStringLiteral("pushButton_Check"));
        pushButton_Check->setGeometry(QRect(220, 470, 91, 31));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("Dialog", "Next", 0));
        label_Obl->setText(QApplication::translate("Dialog", "obl", 0));
        label_Question->setText(QApplication::translate("Dialog", "TextLabel", 0));
        radioButton_1->setText(QApplication::translate("Dialog", "RadioButton", 0));
        radioButton_2->setText(QApplication::translate("Dialog", "RadioButton", 0));
        radioButton_3->setText(QApplication::translate("Dialog", "RadioButton", 0));
        radioButton_4->setText(QApplication::translate("Dialog", "RadioButton", 0));
        label_QuestionNum->setText(QApplication::translate("Dialog", "TextLabel", 0));
        label_CheckAnswer->setText(QApplication::translate("Dialog", "TextLabel", 0));
        radioButton_5->setText(QApplication::translate("Dialog", "RadioButton", 0));
        pushButton_Check->setText(QApplication::translate("Dialog", "Check", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
