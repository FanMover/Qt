/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btn1;
    QPushButton *btn2;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QStringLiteral("Panel"));
        Panel->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Panel);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn1 = new QPushButton(Panel);
        btn1->setObjectName(QStringLiteral("btn1"));

        horizontalLayout->addWidget(btn1);

        btn2 = new QPushButton(Panel);
        btn2->setObjectName(QStringLiteral("btn2"));

        horizontalLayout->addWidget(btn2);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QApplication::translate("Panel", "Form", 0));
        btn1->setText(QApplication::translate("Panel", "Button1", 0));
        btn2->setText(QApplication::translate("Panel", "Button2", 0));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
