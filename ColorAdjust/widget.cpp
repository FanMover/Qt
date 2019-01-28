#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->sld_h_high, &QSlider::sliderReleased, this, &Widget::setHSV);
    connect(ui->sld_h_low, &QSlider::sliderReleased, this, &Widget::setHSV);
    connect(ui->sld_s_high, &QSlider::sliderReleased, this, &Widget::setHSV);
    connect(ui->sld_s_low, &QSlider::sliderReleased, this, &Widget::setHSV);
    connect(ui->sld_v_high, &QSlider::sliderReleased, this, &Widget::setHSV);
    connect(ui->sld_v_low, &QSlider::sliderReleased, this, &Widget::setHSV);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setHSV() {
    Mat src = imread("/home/top/Cobot_Cube_Origin/captureImage0124/B.jpg");
    Mat srcHSV_FULL, Thresholded;
    cvtColor(src, srcHSV_FULL, COLOR_BGR2HSV_FULL);
    int H_High = ui->sld_h_high->value();
    int H_Low = ui->sld_h_low->value();
    int S_High = ui->sld_s_high->value();
    int S_Low = ui->sld_s_low->value();
    int V_High = ui->sld_v_high->value();
    int V_Low = ui->sld_v_low->value();
    ui->h_high_value->setText(QString::number(ui->sld_h_high->value()));
    ui->h_low_value->setText(QString::number(ui->sld_h_low->value()));
    ui->s_high_value->setText(QString::number(ui->sld_s_high->value()));
    ui->s_low_value->setText(QString::number(ui->sld_s_low->value()));
    ui->v_high_value->setText(QString::number(ui->sld_v_high->value()));
    ui->v_low_value->setText(QString::number(ui->sld_v_low->value()));
    inRange(srcHSV_FULL, Scalar(H_Low, S_Low, V_Low),
            Scalar(H_High, S_High, V_High), Thresholded);
    QImage img((uchar *) Thresholded.data, Thresholded.cols, Thresholded.rows, QImage::Format_Grayscale8);
    QPixmap image = QPixmap::fromImage(img);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    ui->graphicsView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->graphicsView->setScene(scene);
}