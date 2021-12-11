/********************************************************************************
** Form generated from reading UI file 'CGH_QtWidget_Calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGH_QTWIDGET_CALCULATOR_H
#define UI_CGH_QTWIDGET_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGH_QtWidget_CalculatorClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_expr;
    QLineEdit *lineEdit_num;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_selectNegOrPos;
    QPushButton *pushButton_0;
    QPushButton *pushButton_00;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_result;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_backspaceExpr;
    QPushButton *pushButton_multiple;
    QPushButton *pushButton_clearCalc;
    QPushButton *pushButton_exit;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *CGH_QtWidget_CalculatorClass)
    {
        if (CGH_QtWidget_CalculatorClass->objectName().isEmpty())
            CGH_QtWidget_CalculatorClass->setObjectName(QStringLiteral("CGH_QtWidget_CalculatorClass"));
        CGH_QtWidget_CalculatorClass->resize(794, 761);
        CGH_QtWidget_CalculatorClass->setMinimumSize(QSize(500, 450));
        CGH_QtWidget_CalculatorClass->setStyleSheet(QLatin1String("background-color: rgb(25, 35, 45);\n"
"color: rgb(240, 240, 240);"));
        centralWidget = new QWidget(CGH_QtWidget_CalculatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(372, 382));
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(25, 35, 45, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        centralWidget->setPalette(palette);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        lineEdit_expr = new QLineEdit(centralWidget);
        lineEdit_expr->setObjectName(QStringLiteral("lineEdit_expr"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_expr->sizePolicy().hasHeightForWidth());
        lineEdit_expr->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(25);
        lineEdit_expr->setFont(font);
        lineEdit_expr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lineEdit_expr);

        lineEdit_num = new QLineEdit(centralWidget);
        lineEdit_num->setObjectName(QStringLiteral("lineEdit_num"));
        sizePolicy1.setHeightForWidth(lineEdit_num->sizePolicy().hasHeightForWidth());
        lineEdit_num->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Bahnschrift Light"));
        font1.setPointSize(36);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lineEdit_num->setFont(font1);
        lineEdit_num->setLayoutDirection(Qt::LeftToRight);
        lineEdit_num->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lineEdit_num);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 5, 0);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(40, 40));
        QFont font2;
        font2.setPointSize(20);
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMinimumSize(QSize(40, 40));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMinimumSize(QSize(40, 40));
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(40, 40));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(40, 40));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(40, 40));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        sizePolicy1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy1);
        pushButton_1->setMinimumSize(QSize(40, 40));
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(40, 40));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(40, 40));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_selectNegOrPos = new QPushButton(centralWidget);
        pushButton_selectNegOrPos->setObjectName(QStringLiteral("pushButton_selectNegOrPos"));
        sizePolicy1.setHeightForWidth(pushButton_selectNegOrPos->sizePolicy().hasHeightForWidth());
        pushButton_selectNegOrPos->setSizePolicy(sizePolicy1);
        pushButton_selectNegOrPos->setMinimumSize(QSize(40, 40));
        pushButton_selectNegOrPos->setFont(font2);
        pushButton_selectNegOrPos->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_selectNegOrPos, 3, 0, 1, 1);

        pushButton_0 = new QPushButton(centralWidget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        sizePolicy1.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy1);
        pushButton_0->setMinimumSize(QSize(40, 40));
        pushButton_0->setFont(font2);
        pushButton_0->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_00 = new QPushButton(centralWidget);
        pushButton_00->setObjectName(QStringLiteral("pushButton_00"));
        pushButton_00->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_00->sizePolicy().hasHeightForWidth());
        pushButton_00->setSizePolicy(sizePolicy1);
        pushButton_00->setMinimumSize(QSize(40, 40));
        pushButton_00->setFont(font2);
        pushButton_00->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(pushButton_00, 3, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(10);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 0, 0, 0);
        pushButton_result = new QPushButton(centralWidget);
        pushButton_result->setObjectName(QStringLiteral("pushButton_result"));
        sizePolicy1.setHeightForWidth(pushButton_result->sizePolicy().hasHeightForWidth());
        pushButton_result->setSizePolicy(sizePolicy1);
        pushButton_result->setMinimumSize(QSize(40, 40));
        pushButton_result->setFont(font2);
        pushButton_result->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout_2->addWidget(pushButton_result, 6, 1, 1, 1);

        pushButton_plus = new QPushButton(centralWidget);
        pushButton_plus->setObjectName(QStringLiteral("pushButton_plus"));
        sizePolicy1.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
        pushButton_plus->setSizePolicy(sizePolicy1);
        pushButton_plus->setMinimumSize(QSize(40, 40));
        pushButton_plus->setFont(font2);
        pushButton_plus->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout_2->addWidget(pushButton_plus, 6, 0, 1, 1);

        pushButton_minus = new QPushButton(centralWidget);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));
        sizePolicy1.setHeightForWidth(pushButton_minus->sizePolicy().hasHeightForWidth());
        pushButton_minus->setSizePolicy(sizePolicy1);
        pushButton_minus->setMinimumSize(QSize(40, 40));
        pushButton_minus->setFont(font2);
        pushButton_minus->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout_2->addWidget(pushButton_minus, 5, 0, 1, 1);

        pushButton_divide = new QPushButton(centralWidget);
        pushButton_divide->setObjectName(QStringLiteral("pushButton_divide"));
        sizePolicy1.setHeightForWidth(pushButton_divide->sizePolicy().hasHeightForWidth());
        pushButton_divide->setSizePolicy(sizePolicy1);
        pushButton_divide->setMinimumSize(QSize(40, 40));
        pushButton_divide->setFont(font2);
        pushButton_divide->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout_2->addWidget(pushButton_divide, 2, 0, 1, 1);

        pushButton_backspaceExpr = new QPushButton(centralWidget);
        pushButton_backspaceExpr->setObjectName(QStringLiteral("pushButton_backspaceExpr"));
        sizePolicy1.setHeightForWidth(pushButton_backspaceExpr->sizePolicy().hasHeightForWidth());
        pushButton_backspaceExpr->setSizePolicy(sizePolicy1);
        pushButton_backspaceExpr->setMinimumSize(QSize(40, 40));
        pushButton_backspaceExpr->setFont(font2);
        pushButton_backspaceExpr->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"image: url(:/CGH_QtWidget_Calculator/icon/delete_64.png);"));

        gridLayout_2->addWidget(pushButton_backspaceExpr, 2, 1, 1, 1);

        pushButton_multiple = new QPushButton(centralWidget);
        pushButton_multiple->setObjectName(QStringLiteral("pushButton_multiple"));
        sizePolicy1.setHeightForWidth(pushButton_multiple->sizePolicy().hasHeightForWidth());
        pushButton_multiple->setSizePolicy(sizePolicy1);
        pushButton_multiple->setMinimumSize(QSize(40, 40));
        pushButton_multiple->setFont(font2);
        pushButton_multiple->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout_2->addWidget(pushButton_multiple, 3, 0, 1, 1);

        pushButton_clearCalc = new QPushButton(centralWidget);
        pushButton_clearCalc->setObjectName(QStringLiteral("pushButton_clearCalc"));
        sizePolicy1.setHeightForWidth(pushButton_clearCalc->sizePolicy().hasHeightForWidth());
        pushButton_clearCalc->setSizePolicy(sizePolicy1);
        pushButton_clearCalc->setMinimumSize(QSize(40, 40));
        pushButton_clearCalc->setFont(font2);
        pushButton_clearCalc->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(240, 240, 240);"));

        gridLayout_2->addWidget(pushButton_clearCalc, 3, 1, 1, 1);

        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_exit->sizePolicy().hasHeightForWidth());
        pushButton_exit->setSizePolicy(sizePolicy1);
        pushButton_exit->setMinimumSize(QSize(40, 40));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_exit->setFont(font3);
        pushButton_exit->setStyleSheet(QLatin1String("background-color: rgb(80, 95, 105);\n"
"color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(pushButton_exit, 5, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 10);

        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        CGH_QtWidget_CalculatorClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(CGH_QtWidget_CalculatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CGH_QtWidget_CalculatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(CGH_QtWidget_CalculatorClass);

        QMetaObject::connectSlotsByName(CGH_QtWidget_CalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *CGH_QtWidget_CalculatorClass)
    {
        CGH_QtWidget_CalculatorClass->setWindowTitle(QApplication::translate("CGH_QtWidget_CalculatorClass", "\354\202\254\354\271\231\354\227\260\354\202\260 \352\263\204\354\202\260\352\270\260 - \354\240\225\354\210\230", nullptr));
        pushButton_7->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "7", nullptr));
        pushButton_8->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "8", nullptr));
        pushButton_9->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "9", nullptr));
        pushButton_4->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "4", nullptr));
        pushButton_5->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "5", nullptr));
        pushButton_6->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "6", nullptr));
        pushButton_1->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "1", nullptr));
        pushButton_2->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "2", nullptr));
        pushButton_3->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "3", nullptr));
        pushButton_selectNegOrPos->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "+/-", nullptr));
        pushButton_0->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "0", nullptr));
        pushButton_00->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "00", nullptr));
        pushButton_result->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "=", nullptr));
        pushButton_plus->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "+", nullptr));
        pushButton_minus->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "-", nullptr));
        pushButton_divide->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "/", nullptr));
        pushButton_backspaceExpr->setText(QString());
        pushButton_multiple->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "X", nullptr));
        pushButton_clearCalc->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "C", nullptr));
        pushButton_exit->setText(QApplication::translate("CGH_QtWidget_CalculatorClass", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGH_QtWidget_CalculatorClass: public Ui_CGH_QtWidget_CalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGH_QTWIDGET_CALCULATOR_H
