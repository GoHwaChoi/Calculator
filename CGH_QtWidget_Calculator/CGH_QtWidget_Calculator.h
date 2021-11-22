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
    //����� ���� �Լ�
    void setCalcData(QString str);                  //lineEdit_num ������ ��ư���� �Է��� �����͸� ���ڿ��� ���� �����
    void setCalcData_followingWinApp(QString str);  //lineEdit_num ����(�ϴ�)������ ���ڸ�, lineEdit_expr ����(���)���� ���� ǥ��. Win����ó��

    // ��ư UI ���� : ��ư�� ���ڸ� lineEdit �������� ����
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
