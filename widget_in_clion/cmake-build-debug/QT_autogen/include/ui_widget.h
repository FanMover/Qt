/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *save;
    QPushButton *load;
    QPushButton *threshold;
    QLineEdit *thresh_value;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(584, 845);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        save = new QPushButton(Widget);
        save->setObjectName(QStringLiteral("save"));

        verticalLayout_2->addWidget(save);

        load = new QPushButton(Widget);
        load->setObjectName(QStringLiteral("load"));

        verticalLayout_2->addWidget(load);

        threshold = new QPushButton(Widget);
        threshold->setObjectName(QStringLiteral("threshold"));

        verticalLayout_2->addWidget(threshold);

        thresh_value = new QLineEdit(Widget);
        thresh_value->setObjectName(QStringLiteral("thresh_value"));

        verticalLayout_2->addWidget(thresh_value);


        verticalLayout_3->addLayout(verticalLayout_2);

        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_3->addWidget(graphicsView);

        graphicsView_2 = new QGraphicsView(Widget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        verticalLayout_3->addWidget(graphicsView_2);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        save->setText(QApplication::translate("Widget", "save", 0));
        load->setText(QApplication::translate("Widget", "load", 0));
        threshold->setText(QApplication::translate("Widget", "threshold", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
