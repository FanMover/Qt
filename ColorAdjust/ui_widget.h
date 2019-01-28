/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *sld_h_high;
    QLabel *h_high_value;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *sld_h_low;
    QLabel *h_low_value;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *sld_s_high;
    QLabel *s_high_value;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSlider *sld_s_low;
    QLabel *s_low_value;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSlider *sld_v_high;
    QLabel *v_high_value;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSlider *sld_v_low;
    QLabel *v_low_value;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(805, 760);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        sld_h_high = new QSlider(Widget);
        sld_h_high->setObjectName(QStringLiteral("sld_h_high"));
        sld_h_high->setMaximum(255);
        sld_h_high->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sld_h_high);

        h_high_value = new QLabel(Widget);
        h_high_value->setObjectName(QStringLiteral("h_high_value"));

        horizontalLayout->addWidget(h_high_value);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        sld_h_low = new QSlider(Widget);
        sld_h_low->setObjectName(QStringLiteral("sld_h_low"));
        sld_h_low->setMaximum(255);
        sld_h_low->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sld_h_low);

        h_low_value = new QLabel(Widget);
        h_low_value->setObjectName(QStringLiteral("h_low_value"));

        horizontalLayout_3->addWidget(h_low_value);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        sld_s_high = new QSlider(Widget);
        sld_s_high->setObjectName(QStringLiteral("sld_s_high"));
        sld_s_high->setMaximum(255);
        sld_s_high->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sld_s_high);

        s_high_value = new QLabel(Widget);
        s_high_value->setObjectName(QStringLiteral("s_high_value"));

        horizontalLayout_4->addWidget(s_high_value);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        sld_s_low = new QSlider(Widget);
        sld_s_low->setObjectName(QStringLiteral("sld_s_low"));
        sld_s_low->setMaximum(255);
        sld_s_low->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sld_s_low);

        s_low_value = new QLabel(Widget);
        s_low_value->setObjectName(QStringLiteral("s_low_value"));

        horizontalLayout_5->addWidget(s_low_value);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        sld_v_high = new QSlider(Widget);
        sld_v_high->setObjectName(QStringLiteral("sld_v_high"));
        sld_v_high->setMaximum(255);
        sld_v_high->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(sld_v_high);

        v_high_value = new QLabel(Widget);
        v_high_value->setObjectName(QStringLiteral("v_high_value"));

        horizontalLayout_7->addWidget(v_high_value);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        sld_v_low = new QSlider(Widget);
        sld_v_low->setObjectName(QStringLiteral("sld_v_low"));
        sld_v_low->setMaximum(255);
        sld_v_low->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(sld_v_low);

        v_low_value = new QLabel(Widget);
        v_low_value->setObjectName(QStringLiteral("v_low_value"));

        horizontalLayout_8->addWidget(v_low_value);


        verticalLayout->addLayout(horizontalLayout_8);

        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "H_High", nullptr));
        h_high_value->setText(QApplication::translate("Widget", "0", nullptr));
        label_2->setText(QApplication::translate("Widget", "H_Low", nullptr));
        h_low_value->setText(QApplication::translate("Widget", "0", nullptr));
        label_3->setText(QApplication::translate("Widget", "S_High", nullptr));
        s_high_value->setText(QApplication::translate("Widget", "0", nullptr));
        label_4->setText(QApplication::translate("Widget", "S_Low", nullptr));
        s_low_value->setText(QApplication::translate("Widget", "0", nullptr));
        label_5->setText(QApplication::translate("Widget", "V_High", nullptr));
        v_high_value->setText(QApplication::translate("Widget", "0", nullptr));
        label_6->setText(QApplication::translate("Widget", "V_Low", nullptr));
        v_low_value->setText(QApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
