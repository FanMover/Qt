#include "widget.h"
#include "ui_widget.h"

using namespace cv;
using namespace std;

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);

    connect(ui->btn_load, &QPushButton::released, this, &Widget::loading);
    connect(this, static_cast<void(Widget::*)()>(&Widget::imageLoaded),
            this, &Widget::affining);
    connect(this, static_cast<void(Widget::*)(QImage, QGraphicsScene*)>(&Widget::imageLoaded),
            this, static_cast<void(Widget::*)(QImage, QGraphicsScene*)>(&Widget::showImage));
    connect(this, static_cast<void(Widget::*)()>(&Widget::imageAffined),
            this, &Widget::threshing);
    connect(this, static_cast<void(Widget::*)(Mat&, QGraphicsScene*, QImage::Format)>(&Widget::imageAffined),
            this, static_cast<void(Widget::*)(Mat&, QGraphicsScene*, QImage::Format)>(&Widget::showImage));
    connect(this, static_cast<void(Widget::*)()>(&Widget::imageThreshed),
            this, &Widget::showHSV);
    connect(this, static_cast<void(Widget::*)(Mat&, QGraphicsScene*, QImage::Format)>(&Widget::imageThreshed),
            this, static_cast<void(Widget::*)(Mat&, QGraphicsScene*, QImage::Format)>(&Widget::showImage));
    connect(ui->btn_changeHSV, &QPushButton::click, this, &Widget::setHSV);
}

Widget::~Widget() {
    delete ui;
}

void Widget::loading() {
    qDebug() << "Hello world!";
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), "",
                                            tr("JPG Opened Image (*.jpg);;PNG (*.png);;All Files (*)"));
    if (fileName.isEmpty()) {
        std::cout << "Unable to load image" << std::endl;
        return;
    }
    qDebug() << "Loaded File Absolute Path: " << fileName;
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return;
    }
    qDebug() << "Image Loaded Signal Emitted..." << endl;
    qDebug() << "FileName:" << fileName << endl;
    Q_EMIT imageLoaded();
    Q_EMIT imageLoaded(newImage, scene);
    return;
}

void Widget::affining() {
    separate(fileName);
    QString faceName = ui->Affined->currentText();
    qDebug()<<"faceName:"<<faceName<<endl;
    this_face = this->getFace(faceName).src;
    if(this_face.empty()){
        qDebug()<<"this face is not correctly loaded"<<endl;
    }
    qDebug() << "Image Affined Signal Emitted..." << endl;
    Q_EMIT imageAffined();
    Q_EMIT imageAffined(this_face, scene_2, QImage::Format_RGB888);
}

void Widget::threshing() {
    qDebug()<<ui->Affined->currentText()<<">>>"<<getFaceRotateStatus(ui->Affined->currentText())<<endl;
    FACE this_face = this->getFace(ui->Affined->currentText());
    Qthis->this_face_color(this->getFace(ui->Affined->currentText()),
                          this->getFaceRotateStatus(ui->Affined->currentText()));
    this_color = this->getColor(ui->ColorThreshed->currentText()).color_thresh;
    if(this_color.empty()){
        qDebug()<<"this face is not correctly loaded"<<endl;
    }
    qDebug() << "Image Threshed Signal Emitted..." << endl;
    Q_EMIT imageThreshed();
    Q_EMIT imageThreshed(this_color, scene_3, QImage::Format_Grayscale8);
}

void Widget::showHSV() {
    ui->spin_h_high->setValue(this->getColor(ui->ColorThreshed->currentText()).H_High);
    ui->spin_h_low->setValue(this->getColor(ui->ColorThreshed->currentText()).H_Low);
    ui->spin_s_high->setValue(this->getColor(ui->ColorThreshed->currentText()).S_High);
    ui->spin_s_low->setValue(this->getColor(ui->ColorThreshed->currentText()).S_Low);
    ui->spin_v_high->setValue(this->getColor(ui->ColorThreshed->currentText()).V_High);
    ui->spin_v_low->setValue(this->getColor(ui->ColorThreshed->currentText()).V_Low);
}

void Widget::setHSV(){
    COLOR tmpColor = getColor(ui->ColorThreshed->currentText());
    tmpColor.H_High = ui->spin_h_high->text().toInt();
    tmpColor.H_Low = ui->spin_h_low->text().toInt();
    tmpColor.S_High = ui->spin_s_high->text().toInt();
    tmpColor.S_Low = ui->spin_s_low->text().toInt();
    tmpColor.V_High = ui->spin_v_high->text().toInt();
    tmpColor.V_Low = ui->spin_v_low->text().toInt();
    getWhichColorThreshed(this_face, tmpColor);
    showImage(tmpColor.color_thresh, scene_3, QImage::Format_Grayscale8);
}

void Widget::showImage(Mat& src, QGraphicsScene* scene, QImage::Format Format){
    QImage img(src.data, src.cols, src.rows, Format);
    QPixmap image = QPixmap::fromImage(img);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    ui->ColorThreshedImageView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->ColorThreshedImageView->setScene(scene);
}

void Widget::showImage(QImage Image, QGraphicsScene* scene){
    QPixmap image = QPixmap::fromImage(Image);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    ui->ColorThreshedImageView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->ColorThreshedImageView->setScene(scene);
}


