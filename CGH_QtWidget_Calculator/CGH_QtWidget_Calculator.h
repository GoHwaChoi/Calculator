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
    void setCalcData(QString str);                  //lineEdit_num 위젯에 버튼으로 입력한 데이터를 문자열로 누적 출력함
    void setCalcData_followingWinApp(QString str);  //lineEdit_num 위젯(하단)에서는 숫자만, lineEdit_expr 위젯(상단)에는 계산식 표현. Win계산기처럼

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

    void on_Button_plus();
    void on_Button_minus();
    void on_Button_multiple();
    void on_Button_divide();

    void on_Button_result();
    void on_Button_clearExpr();
    void on_Button_resetCalc();
    void on_Button_backspace();
    void on_Button_selectNegOrPos();
};
