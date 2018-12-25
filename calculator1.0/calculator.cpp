#include <QtWidgets>
#include <cmath>
#include "button.h"
#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true; //这个值的true表示现在处于等待操作数的状态
    display = new QLineEdit("0"); //new的使用方法，新建了一个对象，TODO:查阅new定义的对象的数据类型

    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);  //设置队列右向，如果设置左向，backspace和clear需要修改，因为他们是对字符串的处理
    display->setMaxLength(15);

    QFont font = display->font(); //定义一个新的对象font指向display中的font()
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
    if (display->text() == "0" && digitValue == 0.0) //如果按出来的是０，不计入计算
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

    if (!pendingMultiplicativeOperator.isEmpty()) { //如果

        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::multiplicativeOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

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

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculator::pointClicked()
{
    if (waitingForOperand)
        display->setText("0");
    if (!display->text().contains('.'))
        display->setText(display->text() + tr("."));
    waitingForOperand = false;
}

void Calculator::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    display->setText(text);
}

void Calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculator::clear()
{
    if (waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearAll()
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

bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("\303\267")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}

