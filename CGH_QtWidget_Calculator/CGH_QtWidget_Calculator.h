#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CGH_QtWidget_Calculator.h"

class CGH_QtWidget_Calculator : public QMainWindow
{
    Q_OBJECT

public:
    CGH_QtWidget_Calculator(QWidget *parent = Q_NULLPTR);

private:
    Ui::CGH_QtWidget_CalculatorClass ui;
};
