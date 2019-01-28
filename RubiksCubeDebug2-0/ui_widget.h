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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_load;
    QGraphicsView *ImageView;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *Affined;
    QGraphicsView *AffinedImageView;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *ColorThreshed;
    QGraphicsView *ColorThreshedImageView;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spin_h_high;
    QLabel *label_2;
    QSpinBox *spin_h_low;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QSpinBox *spin_s_high;
    QLabel *label_6;
    QSpinBox *spin_s_low;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QSpinBox *spin_v_high;
    QLabel *label_9;
    QSpinBox *spin_v_low;
    QPushButton *btn_changeHSV;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QTextEdit *pointInfo;
    QPushButton *btn_changeP;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(700, 581);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setVerticalSpacing(6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_load = new QPushButton(Widget);
        btn_load->setObjectName(QStringLiteral("btn_load"));

        verticalLayout->addWidget(btn_load);

        ImageView = new QGraphicsView(Widget);
        ImageView->setObjectName(QStringLiteral("ImageView"));

        verticalLayout->addWidget(ImageView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 10, -1, -1);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        Affined = new QComboBox(Widget);
        Affined->addItem(QString());
        Affined->addItem(QString());
        Affined->addItem(QString());
        Affined->addItem(QString());
        Affined->addItem(QString());
        Affined->addItem(QString());
        Affined->setObjectName(QStringLiteral("Affined"));
        Affined->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout_5->addWidget(Affined);


        verticalLayout->addLayout(horizontalLayout_5);

        AffinedImageView = new QGraphicsView(Widget);
        AffinedImageView->setObjectName(QStringLiteral("AffinedImageView"));
        AffinedImageView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AffinedImageView->sizePolicy().hasHeightForWidth());
        AffinedImageView->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(AffinedImageView);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        ColorThreshed = new QComboBox(Widget);
        ColorThreshed->addItem(QString());
        ColorThreshed->addItem(QString());
        ColorThreshed->addItem(QString());
        ColorThreshed->addItem(QString());
        ColorThreshed->addItem(QString());
        ColorThreshed->addItem(QString());
        ColorThreshed->setObjectName(QStringLiteral("ColorThreshed"));

        horizontalLayout_2->addWidget(ColorThreshed);


        verticalLayout_3->addLayout(horizontalLayout_2);

        ColorThreshedImageView = new QGraphicsView(Widget);
        ColorThreshedImageView->setObjectName(QStringLiteral("ColorThreshedImageView"));

        verticalLayout_3->addWidget(ColorThreshedImageView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        spin_h_high = new QSpinBox(Widget);
        spin_h_high->setObjectName(QStringLiteral("spin_h_high"));

        horizontalLayout_3->addWidget(spin_h_high);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spin_h_low = new QSpinBox(Widget);
        spin_h_low->setObjectName(QStringLiteral("spin_h_low"));

        horizontalLayout_3->addWidget(spin_h_low);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_10->addWidget(label_7);

        spin_s_high = new QSpinBox(Widget);
        spin_s_high->setObjectName(QStringLiteral("spin_s_high"));

        horizontalLayout_10->addWidget(spin_s_high);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        spin_s_low = new QSpinBox(Widget);
        spin_s_low->setObjectName(QStringLiteral("spin_s_low"));

        horizontalLayout_10->addWidget(spin_s_low);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_11->addWidget(label_8);

        spin_v_high = new QSpinBox(Widget);
        spin_v_high->setObjectName(QStringLiteral("spin_v_high"));

        horizontalLayout_11->addWidget(spin_v_high);

        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_11->addWidget(label_9);

        spin_v_low = new QSpinBox(Widget);
        spin_v_low->setObjectName(QStringLiteral("spin_v_low"));

        horizontalLayout_11->addWidget(spin_v_low);


        verticalLayout_3->addLayout(horizontalLayout_11);

        btn_changeHSV = new QPushButton(Widget);
        btn_changeHSV->setObjectName(QStringLiteral("btn_changeHSV"));

        verticalLayout_3->addWidget(btn_changeHSV);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        pointInfo = new QTextEdit(Widget);
        pointInfo->setObjectName(QStringLiteral("pointInfo"));

        horizontalLayout_4->addWidget(pointInfo);


        verticalLayout_3->addLayout(horizontalLayout_4);

        btn_changeP = new QPushButton(Widget);
        btn_changeP->setObjectName(QStringLiteral("btn_changeP"));

        verticalLayout_3->addWidget(btn_changeP);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btn_load->setText(QApplication::translate("Widget", "load", nullptr));
        label_4->setText(QApplication::translate("Widget", "Affine", nullptr));
        Affined->setItemText(0, QApplication::translate("Widget", "Right", nullptr));
        Affined->setItemText(1, QApplication::translate("Widget", "Left", nullptr));
        Affined->setItemText(2, QApplication::translate("Widget", "Up", nullptr));
        Affined->setItemText(3, QApplication::translate("Widget", "Down", nullptr));
        Affined->setItemText(4, QApplication::translate("Widget", "Front", nullptr));
        Affined->setItemText(5, QApplication::translate("Widget", "Back", nullptr));

        label_3->setText(QApplication::translate("Widget", "Threshold", nullptr));
        ColorThreshed->setItemText(0, QApplication::translate("Widget", "Blue", nullptr));
        ColorThreshed->setItemText(1, QApplication::translate("Widget", "Green", nullptr));
        ColorThreshed->setItemText(2, QApplication::translate("Widget", "Yellow", nullptr));
        ColorThreshed->setItemText(3, QApplication::translate("Widget", "White", nullptr));
        ColorThreshed->setItemText(4, QApplication::translate("Widget", "Orange", nullptr));
        ColorThreshed->setItemText(5, QApplication::translate("Widget", "Red", nullptr));

        label->setText(QApplication::translate("Widget", "H_HIGH:", nullptr));
        label_2->setText(QApplication::translate("Widget", "H_LOW:", nullptr));
        label_7->setText(QApplication::translate("Widget", "S_HIGH:", nullptr));
        label_6->setText(QApplication::translate("Widget", "S_LOW:", nullptr));
        label_8->setText(QApplication::translate("Widget", "V_HIGH:", nullptr));
        label_9->setText(QApplication::translate("Widget", "V_LOW:", nullptr));
        btn_changeHSV->setText(QApplication::translate("Widget", "send", nullptr));
        label_10->setText(QApplication::translate("Widget", "Point", nullptr));
        btn_changeP->setText(QApplication::translate("Widget", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
