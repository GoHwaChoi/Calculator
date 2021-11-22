#include "CGH_QtWidget_Calculator.h"
#include "calculator.hpp"
#include <string>
#include <QMessageBox>
#include <iostream>


CGH_QtWidget_Calculator::CGH_QtWidget_Calculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //숫자버튼 입력
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

    //연산자 버튼 입력
    connect(ui.pushButton_plus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_plus);
    connect(ui.pushButton_minus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_minus);
    connect(ui.pushButton_multiple, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_multiple);
    connect(ui.pushButton_divide, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_divide);

    //부가기능 버튼 입력
    connect(ui.pushButton_result, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_result);
    connect(ui.pushButton_clearExpr, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_clearExpr);
    connect(ui.pushButton_resetCalc, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_resetCalc);
    connect(ui.pushButton_backspace, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_backspace);
    connect(ui.pushButton_selectNegOrPos, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_selectNegOrPos);


}

void CGH_QtWidget_Calculator::on_Button_selectNegOrPos()        //양수, 음수 전환
{
    auto strPrev = ui.lineEdit_num->text();     //숫자 입력창에서 텍스트 가져옴

    if (! strPrev.isEmpty())                    //입력창의 텍스트가 있는 경우
    {
        auto stdPrev = strPrev.toStdString();   //QString을 String 타입으로 변환
        auto checkMinus = stdPrev.substr(0, 1); //문자열 중 첫번째 문자 1개만 추출
        if (checkMinus != "-")                  //숫자 입력 시 - 부호를 입력한 경우
        {
            auto strModi = "-" + stdPrev;       //
            ui.lineEdit_num->setText(QString::fromStdString(strModi));
        }
        else
        {
            auto strModi = stdPrev.substr(1, stdPrev.length() - 1);
            ui.lineEdit_num->setText(QString::fromStdString(strModi));
        }
    }
    else                                      //입력창의 텍스트가 없는 경우 예외 처리
    {
        QMessageBox::warning(this, "Error Expression!", "There is no exist data of expression. Input the Expression!");
    }

}
void CGH_QtWidget_Calculator::on_Button_backspace()     //마지막 텍스트 지우기(backspace)
{
    auto strPrev = ui.lineEdit_num->text();
    auto stdPrev = strPrev.toStdString();
    auto strModi = stdPrev.substr(0, stdPrev.length() - 1);
    ui.lineEdit_num->setText(QString::fromStdString(strModi));
}

void CGH_QtWidget_Calculator::on_Button_clearExpr()     //입력된 피연산자 문자열 삭제
{
    ui.lineEdit_num->setText("");
}

void CGH_QtWidget_Calculator::on_Button_resetCalc()     //입력된 계산식 및 피연산자 문자열 삭제
{
    ui.lineEdit_num->setText("");
    ui.lineEdit_expr->setText("");
}

void CGH_QtWidget_Calculator::setCalcData_followingWinApp(QString str)          //구현중 : 연산자 입력 시 상단 계산식에만 추가. 하단은 피연산자만 입력
{
    //return;
    auto strPrev = ui.lineEdit_expr->text();
    int strNum = std::stoi(str.toStdString());
    QString strLine_num;
    QString strLine_expr;

    if (0 <= strNum && strNum <= 9)
    {
        strLine_num = strPrev + str;
        ui.lineEdit_num->setText(strLine_num);
    }

    strLine_expr = strPrev + str;

    ui.lineEdit_expr->setText(strLine_expr);
}

void CGH_QtWidget_Calculator::setCalcData(QString str)          //버튼으로 입력된 내용 출력(계산식)
{
    auto strPrev = ui.lineEdit_num->text();
  
    strPrev += str;

    ui.lineEdit_num->setText(strPrev);
    ui.lineEdit_expr->setText(strPrev);
}


void CGH_QtWidget_Calculator::on_Button_result()                //계산식 결과값 연산 버튼 슬롯
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

//숫자버튼 슬롯
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

//연산자 버튼 슬롯
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