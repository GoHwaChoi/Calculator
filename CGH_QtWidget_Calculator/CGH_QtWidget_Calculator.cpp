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

    //���ڹ�ư �Է�
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

    //������ ��ư �Է�
    connect(ui.pushButton_plus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_plus);
    connect(ui.pushButton_minus, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_minus);
    connect(ui.pushButton_multiple, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_multiple);
    connect(ui.pushButton_divide, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_divide);
    
    //�ΰ���� ��ư �Է�
    connect(ui.pushButton_result, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_result);
    connect(ui.pushButton_clearExpr, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_clearExpr);
    connect(ui.pushButton_clearCalc, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_clearCalc);
    connect(ui.pushButton_backspace, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_backspace);
    connect(ui.pushButton_selectNegOrPos, &QAbstractButton::clicked, this, &CGH_QtWidget_Calculator::on_Button_selectNegOrPos);


}

void CGH_QtWidget_Calculator::on_Button_selectNegOrPos()        //���, ���� ��ȯ
{
    auto strPrev = ui.lineEdit_num->text();     //���� �Է�â���� �ؽ�Ʈ ������
    auto stdPrev = strPrev.toStdString();       //QString�� String Ÿ������ ��ȯ
    auto checkMinus = stdPrev.substr(0, 1);     //���ڿ� �� ù��° ���� 1���� ����

    /*--------------------------------------------------------------------
        - ��ȣ�� ���� ���
    --------------------------------------------------------------------*/
    if (checkMinus != "-")                      //"-" ��ȣ�� ���� ���
    {
        auto strModi = "-" + stdPrev;                                   //- ��ȣ�� ���忭 ���� ���� ������
        ui.lineEdit_num->setText(QString::fromStdString(strModi));      //String ���ڿ��� QString ���ڿ��� ��ȯ
    }
    /*--------------------------------------------------------------------
        - ��ȣ�� �ִ� ���
    --------------------------------------------------------------------*/
    else
    {
        auto strModi = stdPrev.substr(1, stdPrev.length() - 1);         //���� �κи� ��ȯ�Ͽ� ���
        ui.lineEdit_num->setText(QString::fromStdString(strModi));      //String ���ڿ��� QString ���ڿ��� ��ȯ
    }
}

void CGH_QtWidget_Calculator::on_Button_backspace()     //������ �ؽ�Ʈ �����(backspace)
{
    auto strPrev = ui.lineEdit_num->text();
    auto stdPrev = strPrev.toStdString();
    auto strModi = stdPrev.substr(0, stdPrev.length() - 1);
    ui.lineEdit_num->setText(QString::fromStdString(strModi));
}

void CGH_QtWidget_Calculator::on_Button_clearExpr()     //�Էµ� ���� ���ڿ� ����(�̱���)
{
    //ui.lineEdit_num->setText("");
}

void CGH_QtWidget_Calculator::on_Button_clearCalc()     //�Էµ� ���� �� �ǿ����� ���ڿ� ����(���������� �Էµ� ����)
{
    ui.lineEdit_num->setText("");
    ui.lineEdit_expr->setText("");
}

void CGH_QtWidget_Calculator::setCalcData(QString strNum)          //���� ��ư �Է� �� ���� �� ���� ���ڿ� ���
{   
    auto strPrev = ui.lineEdit_num->text();             //���� ���ڿ��� ��� ������ ������
    
    /*--------------------------------------------------------------------
        ������ ��ư �Է� ( + , - , * , / )
    --------------------------------------------------------------------*/
	if (strNum == "+" || strNum == "-" || strNum == "*" || strNum == "/")       //������ ��ư�� ������ ���
	{
        auto strExpr = ui.lineEdit_expr->text();        //��� lineEdit�������� ���� ������

        /*--------------------------------------------------------------------
            �ǿ����ڰ� �Էµ� ��� (���� �Է�â�� ������� ���� ���)
        --------------------------------------------------------------------*/
        if (! strPrev.isEmpty())
        {
            auto strExprLast = strExpr.right(1);            //���� ������ ������ ���� ����
            /*--------------------------------------------------------------------
                ���� ������ ��� ������� ��µ� ���(������ �Է� �� ���Ŀ� "=" ���ڰ� ������)                
            --------------------------------------------------------------------*/
            if (strExprLast == "=")
            {
                strExpr = strPrev + strNum;                 //��� ������� �Է��� �����ڸ� �߰��Ͽ� ���ο� ������ �̾

                ui.lineEdit_expr->setText(strExpr);         //�ű� ���� ���
                ui.lineEdit_num->setText("");               //���� �Է�â�� ���� ���ڰ� �Էµǵ��� ���ڿ� �ʱ�ȭ
            }
            /*--------------------------------------------------------------------
                ���Ŀ� 0 �������� �Էµ� ���
                ���� ó��(���� �ʱ�ȭ)
            --------------------------------------------------------------------*/
            else if ((strExprLast == "/" && (strPrev == "0" || strPrev == "00")))
            {
				QMessageBox::warning(this, "Error Expression!", "Divide '0' inserted! Write Expression Correctly");
				ui.lineEdit_num->setText("");
				ui.lineEdit_expr->setText("");
				return;
            }
            /*--------------------------------------------------------------------
			    ���� ������ ��� �ۼ����� ���(������ �Է� �� ���Ŀ� "=" ���ڰ� ������)
			--------------------------------------------------------------------*/
            else
            {
				strExpr += strPrev + strNum;                    //���� ���Ŀ� ���ڿ� ������ �߰�

				ui.lineEdit_expr->setText(strExpr);             //���� �����Ͽ� lineEdit������ ���
				ui.lineEdit_num->setText("");                   //���� �Է�â�� ���� ���ڰ� �Էµǵ��� ���ڿ� �ʱ�ȭ
            }
        }
        /*--------------------------------------------------------------------
			������ ���� �� �����ں��� �Է��� ���
            ����ó��
		--------------------------------------------------------------------*/
        else if (strExpr.isEmpty())
        {
            QMessageBox::warning(this, "Error Expression!", "Please Input number first!");
            return;
        }
        /*--------------------------------------------------------------------
		    �����ڸ� �����Ͽ� 2���̻� �Է��ϴ� ��� (���� �Է�â�� ����ִ� ���)
                ���� �����ڸ� �����ϰ� �Էµ� �����ڸ� �߰���
		--------------------------------------------------------------------*/
        else
        {
            strExpr.chop(1);                                //������ ���������� �Էµ� ����ŭ ����
            strExpr += strNum;                              //���� ���Ŀ��� ������ ������ ���� �� �Էµ� ������ �߰�

            ui.lineEdit_expr->setText(strExpr);             //���� �����Ͽ� lineEdit������ ���
        }
	}
    /*--------------------------------------------------------------------
		������ �̿��� ��ư �Է� ( ����, �������(+/-) )
	--------------------------------------------------------------------*/
    else
    {                                                   
        auto strExpr      = ui.lineEdit_expr->text();       //���� ���â ���ڿ� ������
        auto checkEndExpr = strExpr.right(1);               //������ ������� ����� ��� �ν� (���� ������ ���� 1�� ����)
        //auto checkDivZero = strExpr.right(2);               //���Ŀ� 0�� ������ ������ �� ��� �ν� (���� ������ ���ڿ� 2�� ����)

        /*--------------------------------------------------------------------
			���� ��� ������� ��µ� ���
		--------------------------------------------------------------------*/
        if (checkEndExpr == "=")                        //��� �Ϸ�. ����� ���� ��µ� ����
        {
			ui.lineEdit_expr->setText("");              //���� ���â �ʱ�ȭ
            strPrev.clear();                            //���� ���� ����� �� ����
                    
			ui.lineEdit_num->setText(strNum);          //���� �Էµ� ���� ���
        }
        /*--------------------------------------------------------------------
            �ǿ����� ���� ���
        --------------------------------------------------------------------*/
        else
        {
			strPrev += strNum;                          //���� �Է°� �����Ͽ� ����

			ui.lineEdit_num->setText(strPrev);          //������ ���� ���
        }
    }
}

void CGH_QtWidget_Calculator::on_Button_result()                //���� ����� ���� ��ư ����
{
    auto strExpr = ui.lineEdit_expr->text();
    auto strNum  = ui.lineEdit_num->text();

    if (! strExpr.isEmpty())                                    //������ �Է� ���� ��, 
    {
		auto stdExpr     = strExpr.toStdString();
		auto stdNum      = strNum.toStdString();
		auto strExprLast = strExpr.right(1);

        stdExpr += stdNum;
        /*--------------------------------------------------------------------
            ������ �ϼ����� ���� ������ ��(���� ���� �������̰� ���� �Է�â�� ����� ����, ���� ������ �����ڸ� �Է��� ���)
            ���� ó��
        --------------------------------------------------------------------*/
        if (stdNum.empty())
        {
            QMessageBox::warning(this, "Error Expression!", "Complete the Expression");
            return;
        }
        /*--------------------------------------------------------------------
            ���Ŀ� 0 �������� �Էµ� ���
            ���� ó��(���� �ʱ�ȭ)
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
		������ ���� �Էµ��� ���� ���
		���� ó��
	--------------------------------------------------------------------*/
    else
    {                                                           //��� �Ϸ� ��
        QMessageBox::warning(this, "Error Expression!", "There is no exist data of expression. Input the Expression!");
    }
    
}

//���ڹ�ư ����
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

//������ ��ư ����
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