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

void CGH_QtWidget_Calculator::on_Button_clearExpr()     //입력된 계산식 문자열 삭제(미구현)
{
    //ui.lineEdit_num->setText("");
}

void CGH_QtWidget_Calculator::on_Button_clearCalc()     //입력된 계산식 및 피연산자 문자열 삭제(마지막으로 입력된 숫자)
{
    ui.lineEdit_num->setText("");
    ui.lineEdit_expr->setText("");
}

void CGH_QtWidget_Calculator::setCalcData(QString strNum)          //숫자 버튼 입력 시 계산식 및 숫자 문자열 출력
{   
    auto strPrev = ui.lineEdit_num->text();             //숫자 문자열의 출력 누적값 가져옴
    
    /*--------------------------------------------------------------------
        연산자 버튼 입력 ( + , - , * , / )
    --------------------------------------------------------------------*/
	if (strNum == "+" || strNum == "-" || strNum == "*" || strNum == "/")       //연산자 버튼을 눌렀을 경우
	{
        auto strExpr = ui.lineEdit_expr->text();        //상단 lineEdit위젯에서 계산식 가져옴

        /*--------------------------------------------------------------------
          연산자가 입력되면 (하단 출력창이 비어있지 않는 경우)
            기존 계산식 + 입력된 숫자 + 연산자 를 모두 출력
        --------------------------------------------------------------------*/
        if (! strPrev.isEmpty())
        {
            auto strExprLast = strExpr.right(1);            //기존 계산식의 마지막 문자 저장

            if (strExprLast == "=")
            {
                strExpr = strPrev + strNum;                 //계산 결과값에 입력한 연산자를 추가하여 새로운 계산식을 이어감

                ui.lineEdit_expr->setText(strExpr);         //신규 계산식 출력
                ui.lineEdit_num->setText("");               //숫자 입력창에 다음 숫자가 입력되도록 문자열 초기화
            }

            else
            {
				strExpr += strPrev + strNum;                    //기존 계산식에 숫자와 연산자 추가

				ui.lineEdit_expr->setText(strExpr);             //계산식 누적하여 lineEdit위젯에 출력
				ui.lineEdit_num->setText("");                   //숫자 입력창에 다음 숫자가 입력되도록 문자열 초기화
            }
        }
        /*--------------------------------------------------------------------
		  연산자를 연속하여 2번이상 입력하는 경우 (하단 출력창이 비어있는 경우)
            기존 연산자를 삭제하고 입력된 연산자를 추가함
		--------------------------------------------------------------------*/
        else
        {
            strExpr.chop(1);                                //오른쪽 끝에서부터 입력된 수만큼 제거
            strExpr += strNum;                              //기존 계산식에서 마지막 연산자 삭제 후 입력된 연산자 추가

            ui.lineEdit_expr->setText(strExpr);             //계산식 누적하여 lineEdit위젯에 출력
        }
	}
    /*--------------------------------------------------------------------
		연산자 이외의 버튼 입력
	--------------------------------------------------------------------*/
    else
    {                                                   
        auto strExpr = ui.lineEdit_expr->text();        //계산식 출력창 문자열 가져옴
        auto checkEndExpr = strExpr.right(1);           //계산식 마지막 문자 추출

        /*--------------------------------------------------------------------
			계산 결과 출력( "=" 버튼 입력)
		--------------------------------------------------------------------*/
        if (checkEndExpr == "=")                        //계산 완료. 결과값 연산 출력된 이후
        {
			ui.lineEdit_expr->setText("");              //계산식 출력창 초기화
            strPrev.clear();                            //기존 계산식 저장된 값 삭제
                    
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

void CGH_QtWidget_Calculator::on_Button_result()                //계산식 결과값 연산 버튼 슬롯
{
    auto strExpr = ui.lineEdit_expr->text();
    auto strNum = ui.lineEdit_num->text();

    if (! strExpr.isEmpty())                                    //계산식이 입력 중일 때, 
    {
		auto stdExpr = strExpr.toStdString();
        auto stdNum = strNum.toStdString();

        stdExpr += stdNum;
        if (stdNum.empty())
        {
            QMessageBox::warning(this, "Error Expression!", "Error");
            return;
        }

        auto nResult = calculator::eval(stdExpr);
        auto strExpr = QString::fromStdString(stdExpr);

        strExpr += " =";

        ui.lineEdit_num->setText(QString::number(nResult));
        ui.lineEdit_expr->setText(strExpr);
    }
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