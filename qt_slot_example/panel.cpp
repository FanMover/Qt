#include "panel.h"
#include "ui_panel.h"

Panel::Panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel)
{
    ui->setupUi(this);
    connect(ui->btn1,&QPushButton::released,[=](){
      Q_EMIT reqSetLabel("Button1 Clicked");
    });
    connect(ui->btn2,&QPushButton::released,[=](){
      Q_EMIT reqSetLabel("Button2 Clicked");
    });
}

Panel::~Panel()
{
    delete ui;
}
