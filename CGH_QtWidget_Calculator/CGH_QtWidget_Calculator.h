#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CGH_QtWidget_Calculator.h"

class CGH_QtWidget_Calculator : public QMainWindow
{
    Q_OBJECT

public:
    CGH_QtWidget_Calculator(QWidget* parent = Q_NULLPTR);

private:
    Ui::CGH_QtWidget_CalculatorClass ui;

public:
    //사용자 지정 함수
    void setCalcData(QString strNum);                   //lineEdit_num 위젯에 숫자열 출력

    //윈도우 함수
    void closeEvent(QCloseEvent* event);                //alt+f4 종료 기능 비활성화

    // 버튼 UI 슬롯 : 버튼의 문자를 lineEdit 위젯으로 전달
    void on_Button_0();
    void on_Button_1();
    void on_Button_2();
    void on_Button_3();
    void on_Button_4();
    void on_Button_5();
    void on_Button_6();
    void on_Button_7();
    void on_Button_8();
    void on_Button_9();
    void on_Button_00();

    void on_Button_plus();
    void on_Button_minus();
    void on_Button_multiple();
    void on_Button_divide();

    void on_Button_result();
    void on_Button_clearCalc();
    void on_Button_exit();
    void on_Button_backspaceExpr();
    void on_Button_selectNegOrPos();
};
