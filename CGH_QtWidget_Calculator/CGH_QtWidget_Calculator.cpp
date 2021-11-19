#include "CGH_QtWidget_Calculator.h"
#include "calculator.hpp"
#include <string>
#include <QMessageBox>
#include <iostream>


CGH_QtWidget_Calculator::CGH_QtWidget_Calculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton_0, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_0);
    connect(ui.pushButton_1, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_1);
    connect(ui.pushButton_2, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_2);
    connect(ui.pushButton_3, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_3);
    connect(ui.pushButton_4, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_4);
    connect(ui.pushButton_5, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_5);
    connect(ui.pushButton_6, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_6);
    connect(ui.pushButton_7, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_7);
    connect(ui.pushButton_8, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_8);
    connect(ui.pushButton_9, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_9);

    connect(ui.pushButton_plus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_plus);
    connect(ui.pushButton_minus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_minus);
    connect(ui.pushButton_multiple, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_multiple);
    connect(ui.pushButton_divide, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_divide);

    connect(ui.pushButton_result, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_result);
    connect(ui.pushButton_clearExpr, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_clearExpr);
    connect(ui.pushButton_resetCalc, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_resetCalc);
    connect(ui.pushButton_backspace, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_backspace);
    connect(ui.pushButton_selectNegOrPos, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_selectNegOrPos);


}

void CGH_QtWidget_Calculator::on_Button_selectNegOrPos()
{
    auto strPrev = ui.lineEdit_num->text();

    if (strPrev != NULL)
    {
        auto stdPrev = strPrev.toStdString();
        auto checkMinus = stdPrev.substr(0, 1);
        if (checkMinus != "-")
        {
            auto strModi = "-" + stdPrev;
            ui.lineEdit_num->setText(QString::fromStdString(strModi));
        }
        else
        {
            auto strModi = stdPrev.substr(1, stdPrev.length() - 1);
            ui.lineEdit_num->setText(QString::fromStdString(strModi));
        }
    }
    else
    {
        QMessageBox::warning(this, "Error Expression!", "There is no exist data of expression. Input the Expression!");
    }

}
void CGH_QtWidget_Calculator::on_Button_backspace()
{
    auto strPrev = ui.lineEdit_num->text();
    auto stdPrev = strPrev.toStdString();
    auto strModi = stdPrev.substr(0, stdPrev.length() - 1);
    ui.lineEdit_num->setText(QString::fromStdString(strModi));
}

void CGH_QtWidget_Calculator::on_Button_clearExpr()
{
    ui.lineEdit_num->setText("");
}

void CGH_QtWidget_Calculator::on_Button_resetCalc()
{
    ui.lineEdit_num->setText("");
    ui.lineEdit_expr->setText("");
}

//void CGH_QtWidget_Calculator::setCalcData(QString str)          //구현중
//{
//    auto strPrev = ui.lineEdit_expr->text();
//    int strNum = std::stoi(str.toStdString());
//    QString strLine_num;
//    QString strLine_expr;
//
//    if (0 <= strNum && strNum <= 9)
//    {
//        strLine_num = strPrev + str;
//        ui.lineEdit_num->setText(strLine_num);
//    }
//
//    strLine_expr = strPrev + str;
//
//    ui.lineEdit_expr->setText(strLine_expr);
//}

void CGH_QtWidget_Calculator::setCalcData(QString str)          //구현중
{
    auto strPrev = ui.lineEdit_num->text();
  
    strPrev += str;

    ui.lineEdit_num->setText(strPrev);
    ui.lineEdit_expr->setText(strPrev);
}


void CGH_QtWidget_Calculator::on_Button_result()
{
    auto strExpr = ui.lineEdit_num->text();
    if (strExpr != NULL)
    {
        auto stdExpr = strExpr.toStdString();
        auto nResult = calculator::eval(stdExpr);
        ui.lineEdit_num->setText(QString::number(nResult));
    }
    else
    {
        QMessageBox::warning(this, "Error Expression!", "There is no exist data of expression. Input the Expression!");
    }
    
}
void CGH_QtWidget_Calculator::on_Button_0()
{
    setCalcData("0");
}
void CGH_QtWidget_Calculator::on_Button_1()
{
    setCalcData("1");
}
void CGH_QtWidget_Calculator::on_Button_2()
{
    setCalcData("2");
}
void CGH_QtWidget_Calculator::on_Button_3()
{
    setCalcData("3");
}
void CGH_QtWidget_Calculator::on_Button_4()
{
    setCalcData("4");
}
void CGH_QtWidget_Calculator::on_Button_5()
{
    setCalcData("5");
}
void CGH_QtWidget_Calculator::on_Button_6()
{
    setCalcData("6");
}
void CGH_QtWidget_Calculator::on_Button_7()
{
    setCalcData("7");
}
void CGH_QtWidget_Calculator::on_Button_8()
{
    setCalcData("8");
}
void CGH_QtWidget_Calculator::on_Button_9()
{
    setCalcData("9");
}

void CGH_QtWidget_Calculator::on_Button_plus()
{
    setCalcData("+");
}
void CGH_QtWidget_Calculator::on_Button_minus()
{
    setCalcData("-");
}
void CGH_QtWidget_Calculator::on_Button_multiple()
{
    setCalcData("*");
}
void CGH_QtWidget_Calculator::on_Button_divide()
{
    setCalcData("/");
}