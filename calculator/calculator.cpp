#include <QtWidgets>
#include <cmath>
#include "button.h"
#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    sumSoFar = 0.0; //存储当按下一个运算符之前的所有的总和,总和将乘除优先运算得到的数值作为操作数
    factorSoFar = 0.0; //存储一个乘除优先运算的闭环值
    waitingForOperand = true; //这个值的true表示现在处于等待操作数的状态

    display = new QLineEdit("0"); //new的使用方法，新建了一个对象，TODO:查阅new定义的对象的数据类型

    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);  //设置队列右向，如果设置左向，backspace和clear需要修改，因为他们是对字符串的处理
    display->setMaxLength(15);

    QFont font = display->font(); //定义一个新的对象font指向display中的属性font()
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    for (int i = 0; i < NumDigitButtons; ++i) {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked())); //头文件中定义了一个button类的指针对象
        //QString::number
    }

    Button *pointButton = createButton(tr("."), SLOT(pointClicked())); //创建指针Button对象与信号槽中的函数链接，这里的连接功能还是依赖于connect，只是定义了这样一种函数可以创建按钮内容和信号，很赞
    Button *changeSignButton = createButton(tr("\302\261"), SLOT(changeSignClicked())); //符号是通过转义码转换的
    Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked())); //TODO:查阅tr()函数的作用
    Button *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Button *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));
    Button *divisionButton = createButton(tr("\303\267"), SLOT(multiplicativeOperatorClicked()));
    Button *timesButton = createButton(tr("\303\227"), SLOT(multiplicativeOperatorClicked()));
    Button *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Button *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));
    Button *equalButton = createButton(tr("="), SLOT(equalClicked()));

    QGridLayout *mainLayout = new QGridLayout;  //TODO:这里为什么与display的定义不同？

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 6); //参数是ui的块的排布
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
    mainLayout->addWidget(clearButton, 1, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(changeSignButton, 5, 3);

    mainLayout->addWidget(divisionButton, 2, 4);
    mainLayout->addWidget(timesButton, 3, 4);
    mainLayout->addWidget(minusButton, 4, 4);
    mainLayout->addWidget(plusButton, 5, 4);

    mainLayout->addWidget(equalButton, 5, 5);
    setLayout(mainLayout);  //TODO:查阅setLayout()函数功能

    setWindowTitle(tr("Calculator"));
}

void Calculator::digitClicked() //当数字按钮被按下
{
    Button *clickedButton = qobject_cast<Button *>(sender());  //固定格式，将函数内的一个指针对象指向放出信号的那个按钮，及将局部对象指针广播到全局指针对象
    int digitValue = clickedButton->text().toInt(); //这里数值的获取在于按钮的text()内容
    if (display->text() == "0" && digitValue == 0.0) //如果按出来的是0，不计入计算
        return;

    if (waitingForOperand) { //如果现在处在等待操作数的状态，比如刚输入一个加号
        display->clear(); //清空现在所呈现的内容
        waitingForOperand = false; //并且切换状态
    }
    display->setText(display->text() + QString::number(digitValue));  //这里将数值转换成QString类作为一个整体被放到了display指针对象的text()属性里
}


void Calculator::additiveOperatorClicked()  //当加减号被按下

{
    Button *clickedButton = qobject_cast<Button *>(sender()); //同上
    QString clickedOperator = clickedButton->text(); //获取加（减）号的QString
    double operand = display->text().toDouble(); //获取正在显示的数字，即被加（减）数

    if (!pendingMultiplicativeOperator.isEmpty()) { //如果存在乘除号

        if (!calculate(operand, pendingMultiplicativeOperator)) { //除数为0时
            abortOperation(); //退出操作
            return;
        }
        display->setText(QString::number(factorSoFar)); //将显示的数定为因子总积
        operand = factorSoFar; //操作数写为因子总积
        factorSoFar = 0.0; //按下了加减号，表示乘除的优先运算已经闭环，被乘除数应该被清零
        pendingMultiplicativeOperator.clear(); //乘除运算符也应该被清空
    }

    if (!pendingAdditiveOperator.isEmpty()) { //如果存在加减号
        if (!calculate(operand, pendingAdditiveOperator)) { //不知道为什么写这一步，加减号又不会报错，哦，但是与此同时需要参与计算
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar)); //将显示的数定为总和
    } else {
        sumSoFar = operand; //如果不存在加减号，那就将目前的显示的数（被加减数）写成总和
    }

    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::multiplicativeOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) { //如果存在乘除号
        if (!calculate(operand, pendingMultiplicativeOperator)) { //除数为0时
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar)); //将显示的数值作为因子总积
    } else {
        factorSoFar = operand; //如果不存在乘除号，那就将按下的那个数值作为因子
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true; //有了运算符就应该处于等待数字的状态
}

void Calculator::equalClicked() //当等号被按下
{
    double operand = display->text().toDouble();  //操作数为之前显示的那个数

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar)); //显示总和
    sumSoFar = 0.0; //归零重启，但显示的值还存在
    waitingForOperand = true;
}

void Calculator::pointClicked()
{
    if (waitingForOperand) //如果上一个输入为运算符
        display->setText("0"); //那你按下点，显示0
    if (!display->text().contains('.')) //如果本身不含'.',那么有效，否则按下无意义
        display->setText(display->text() + tr("."));
    waitingForOperand = false;
}

void Calculator::changeSignClicked()//改变正负号，按钮同减号
{
    QString text = display->text();
    double value = text.toDouble(); //得到目前的值

    if (value > 0.0) {
        text.prepend(tr("-"));//预先打印出-
    } else if (value < 0.0) {
        text.remove(0, 1); //从第0个数开始删除1个数
    }
    display->setText(text);
}

void Calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1); //砍掉最后一个数，砍的顺序是依据队列的方向确定的
    if (text.isEmpty()) { //本来就一位，砍掉直接赋成0
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculator::clear()
{
    if (waitingForOperand)
        return;

    display->setText("0"); //将目前的显示的数记为0，但是不改变内部值
    waitingForOperand = true;
}

void Calculator::clearAll() //全部初始化
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;
}

Button *Calculator::createButton(const QString &text, const char *member)  //Button *createButton函数指针创造了按钮并且将按下这个事件与SLOT信号槽对应函数connect起来
{
    Button *button = new Button(text); //真正的一个纯Button对象只需要它的title，详见button.h
    connect(button, SIGNAL(clicked()), this, member); //将这个按下的信号与执行函数连接，注意两个函数的参数形式要一致
    return button; //返回这个按钮
}

void Calculator::abortOperation()
{
    clearAll();
    display->setText(tr("####"));
}

bool Calculator::calculate(double rightOperand, const QString &pendingOperator) //计算函数
{
    if (pendingOperator == tr("+")) { //如果是加号，目前总和需要加上右值
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) { //如果是减号，目前总和需要减去右值
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) { //如果是乘号，目前因子总积乘上右值
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("\303\267")) { //如果是除号，目前因子总积除以右值
        if (rightOperand == 0.0)
            return false; //如果右值为0，返回false,因为除数不能为0
        factorSoFar /= rightOperand;
    }
    return true;
}

