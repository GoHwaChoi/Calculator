#include "CGH_QtWidget_Calculator.h"
#include "calculator.hpp"
#include <string>
#include <QMessageBox>
#include <iostream>
#include "QDir"
#include "QDebug"

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
    connect(ui.pushButton_00, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_00);

    //연산자 버튼 입력
    connect(ui.pushButton_plus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_plus);
    connect(ui.pushButton_minus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_minus);
    connect(ui.pushButton_multiple, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_multiple);
    connect(ui.pushButton_divide, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_divide);
    
    //부가기능 버튼 입력
    connect(ui.pushButton_result, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_result);
    connect(ui.pushButton_clearExpr, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_clearExpr);
    connect(ui.pushButton_clearCalc, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_clearCalc);
    connect(ui.pushButton_backspace, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_backspace);
    connect(ui.pushButton_selectNegOrPos, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_selectNegOrPos);


}

void CGH_QtWidget_Calculator::on_Button_selectNegOrPos()        //양수, 음수 전환
{
    auto strPrev = ui.lineEdit_num->text();     //숫자 입력창에서 텍스트 가져옴
    auto stdPrev = strPrev.toStdString();       //QString을 String 타입으로 변환
    auto checkMinus = stdPrev.substr(0, 1);     //문자열 중 첫번째 문자 1개만 추출

    /*--------------------------------------------------------------------
        - 부호가 없는 경우
    --------------------------------------------------------------------*/
    if (checkMinus != "-")                      //"-" 부호가 없는 경우
    {
        auto strModi = "-" + stdPrev;                                   //- 부호를 문장열 왼쪽 끝에 덧붙임
        ui.lineEdit_num->setText(QString::fromStdString(strModi));      //String 문자열을 QString 문자열로 변환
    }
    /*--------------------------------------------------------------------
        - 부호가 있는 경우
    --------------------------------------------------------------------*/
    else
    {
        auto strModi = stdPrev.substr(1, stdPrev.length() - 1);         //숫자 부분만 반환하여 출력
        ui.lineEdit_num->setText(QString::fromStdString(strModi));      //String 문자열을 QString 문자열로 변환
    }
}

void CGH_QtWidget_Calculator::on_Button_backspace()     //마지막 텍스트 지우기(backspace)
{
    auto strPrev = ui.lineEdit_num->text();
    auto stdPrev = strPrev.toStdString();
    auto strModi = stdPrev.substr(0, stdPrev.length() - 1);
    ui.lineEdit_num->setText(QString::fromStdString(strModi));
}

void CGH_QtWidget_Calculator::on_Button_clearExpr()     //입력된 수식 문자열 삭제(미구현)
{
    //ui.lineEdit_num->setText("");
}

void CGH_QtWidget_Calculator::on_Button_clearCalc()     //입력된 수식 및 피연산자 문자열 삭제(마지막으로 입력된 숫자)
{
    ui.lineEdit_num->setText("");
    ui.lineEdit_expr->setText("");
}

void CGH_QtWidget_Calculator::setCalcData(QString strNum)          //숫자 버튼 입력 시 수식 및 숫자 문자열 출력
{   
    auto strPrev = ui.lineEdit_num->text();             //숫자 문자열의 출력 누적값 가져옴
    
    /*--------------------------------------------------------------------
        연산자 버튼 입력 ( + , - , * , / )
    --------------------------------------------------------------------*/
	if (strNum == "+" || strNum == "-" || strNum == "*" || strNum == "/")       //연산자 버튼을 눌렀을 경우
	{
        auto strExpr = ui.lineEdit_expr->text();        //상단 lineEdit위젯에서 수식 가져옴

        /*--------------------------------------------------------------------
            피연산자가 입력된 경우 (숫자 입력창이 비어있지 않은 경우)
        --------------------------------------------------------------------*/
        if (! strPrev.isEmpty())
        {
            auto strExprLast = strExpr.right(1);            //기존 수식의 마지막 문자 저장
            /*--------------------------------------------------------------------
                기존 수식이 계산 결과값이 출력된 경우(연산자 입력 시 수식에 "=" 문자가 있으면)                
            --------------------------------------------------------------------*/
            if (strExprLast == "=")
            {
                strExpr = strPrev + strNum;                 //계산 결과값에 입력한 연산자를 추가하여 새로운 수식을 이어감

                ui.lineEdit_expr->setText(strExpr);         //신규 수식 출력
                ui.lineEdit_num->setText("");               //숫자 입력창에 다음 숫자가 입력되도록 문자열 초기화
            }
            /*--------------------------------------------------------------------
                수식에 0 나눗셈이 입력된 경우
                예외 처리(수식 초기화)
            --------------------------------------------------------------------*/
            else if ((strExprLast == "/" && (strPrev == "0" || strPrev == "00")))
            {
				QMessageBox::warning(this, "Error Expression!", "Divide '0' inserted! Write Expression Correctly");
				ui.lineEdit_num->setText("");
				ui.lineEdit_expr->setText("");
				return;
            }
            /*--------------------------------------------------------------------
			    기존 수식을 계속 작성중인 경우(연산자 입력 시 수식에 "=" 문자가 없으면)
			--------------------------------------------------------------------*/
            else
            {
				strExpr += strPrev + strNum;                    //기존 수식에 숫자와 연산자 추가

				ui.lineEdit_expr->setText(strExpr);             //수식 누적하여 lineEdit위젯에 출력
				ui.lineEdit_num->setText("");                   //숫자 입력창에 다음 숫자가 입력되도록 문자열 초기화
            }
        }
        /*--------------------------------------------------------------------
			수식이 없을 때 연산자부터 입력한 경우
            예외처리
		--------------------------------------------------------------------*/
        else if (strExpr.isEmpty())
        {
            QMessageBox::warning(this, "Error Expression!", "Please Input number first!");
            return;
        }
        /*--------------------------------------------------------------------
		    연산자를 연속하여 2번이상 입력하는 경우 (숫자 입력창이 비어있는 경우)
                기존 연산자를 삭제하고 입력된 연산자를 추가함
		--------------------------------------------------------------------*/
        else
        {
            strExpr.chop(1);                                //오른쪽 끝에서부터 입력된 수만큼 제거
            strExpr += strNum;                              //기존 수식에서 마지막 연산자 삭제 후 입력된 연산자 추가

            ui.lineEdit_expr->setText(strExpr);             //수식 누적하여 lineEdit위젯에 출력
        }
	}
    /*--------------------------------------------------------------------
		연산자 이외의 버튼 입력 ( 숫자, 음수양수(+/-) )
	--------------------------------------------------------------------*/
    else
    {                                                   
        auto strExpr      = ui.lineEdit_expr->text();       //수식 출력창 문자열 가져옴
        auto checkEndExpr = strExpr.right(1);               //수식이 결과값을 출력한 경우 인식 (수식 마지막 문자 1개 추출)
        //auto checkDivZero = strExpr.right(2);               //수식에 0을 나누는 내용이 들어간 경우 인식 (수식 마지막 문자열 2개 추출)

        /*--------------------------------------------------------------------
			수식 계산 결과값이 출력된 경우
		--------------------------------------------------------------------*/
        if (checkEndExpr == "=")                        //계산 완료. 결과값 연산 출력된 이후
        {
			ui.lineEdit_expr->setText("");              //수식 출력창 초기화
            strPrev.clear();                            //기존 수식 저장된 값 삭제
                    
			ui.lineEdit_num->setText(strNum);          //새로 입력된 숫자 출력
        }
        /*--------------------------------------------------------------------
            피연산자 누적 출력
        --------------------------------------------------------------------*/
        else
        {
			strPrev += strNum;                          //숫자 입력값 누적하여 저장

			ui.lineEdit_num->setText(strPrev);          //누적된 숫자 출력
        }
    }
}

void CGH_QtWidget_Calculator::on_Button_result()                //수식 결과값 연산 버튼 슬롯
{
    auto strExpr = ui.lineEdit_expr->text();
    auto strNum  = ui.lineEdit_num->text();

    if (! strExpr.isEmpty())                                    //수식이 입력 중일 때, 
    {
		auto stdExpr     = strExpr.toStdString();
		auto stdNum      = strNum.toStdString();
		auto strExprLast = strExpr.right(1);

        stdExpr += stdNum;
        /*--------------------------------------------------------------------
            수식이 완성되지 않은 상태일 때(수식 끝이 연산자이고 숫자 입력창이 비워진 상태, 이전 동작이 연산자를 입력한 경우)
            예외 처리
        --------------------------------------------------------------------*/
        if (stdNum.empty())
        {
            QMessageBox::warning(this, "Error Expression!", "Complete the Expression");
            return;
        }
        /*--------------------------------------------------------------------
            수식에 0 나눗셈이 입력된 경우
            예외 처리(수식 초기화)
        --------------------------------------------------------------------*/
        else if (strExprLast == "/" && (strNum == "0" || strNum == "00"))
        {
			QMessageBox::warning(this, "Error Expression!", "Divide '0' inserted! Write Expression Correctly");
			ui.lineEdit_num->setText("");
			ui.lineEdit_expr->setText("");
            return;
        }

        auto nResult = calculator::eval(stdExpr);
        auto strExpr = QString::fromStdString(stdExpr);

        strExpr += " =";

        ui.lineEdit_num->setText(QString::number(nResult));
        ui.lineEdit_expr->setText(strExpr);
    }
    /*--------------------------------------------------------------------
		수식이 전혀 입력되지 않은 경우
		예외 처리
	--------------------------------------------------------------------*/
    else
    {                                                           //계산 완료 후
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

void CGH_QtWidget_Calculator::on_Button_00()
{
	setCalcData("00");
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