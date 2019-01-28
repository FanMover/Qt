#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->btn_load, &QPushButton::released, this, &Widget::loading);
    connect(ui->Affined, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &Widget::DisplayScene2Image);
    connect(ui->ColorThreshed, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &Widget::threshing);
}

Widget::~Widget()
{
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
    Image1 = reader.read();
    if (Image1.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return;
    }
    qDebug() << "FileName:" << fileName << endl;
    DisplayScene1Image();
    faceName = ui->Affined->currentText();
    colorName = ui->ColorThreshed->currentText();
    affining(faceName);
    threshing(colorName);
}

void Widget::DisplayScene1Image(){
    QPixmap image = QPixmap::fromImage(Image1);
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    ui->ImageView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->ImageView->setScene(scene);
}

void Widget::affining(QString faceNameTmp){
    separate(fileName);
    DisplayScene2Image(faceNameTmp);
}

void Widget::DisplayScene2Image(QString faceNameTmp) {
    faceName = ui->Affined->currentText();
    qDebug()<<"faceName:"<<faceNameTmp<<endl;
    Mat this_face = this->getFace(faceNameTmp).src;
    if(this_face.empty()){
        qDebug()<<"this face is not correctly affined"<<endl;
    }
    QImage Image2(this_face.data, this_face.cols, this_face.rows, QImage::Format_RGB888);
    QPixmap image2 = QPixmap::fromImage(Image2);
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addPixmap(image2);
    ui->AffinedImageView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->AffinedImageView->setScene(scene);
}

void Widget::threshing(QString colorNameTmp) {
    qDebug()<<"colorName:"<<colorNameTmp<<endl;
    qDebug()<<"Face:"<<this->getFace(faceName).faceName<<endl;
    QString Answer = this_face_color(this->getFace(faceName),
                                     this->getFaceRotateStatus(faceName));
    DisplayScene3Image(colorName);
}

void Widget::DisplayScene3Image(QString colorName) {
    qDebug()<<"ColorName:"<<colorName<<endl;
    Mat this_thresh = this->getColor(colorName).color_thresh;
    if(this_thresh.empty()){
        qDebug()<<"this Color is not correctly threshed"<<endl;
    }
    QImage Image3(this_thresh.data, this_thresh.cols, this_thresh.rows, QImage::Format_Grayscale8);
    QPixmap image3 = QPixmap::fromImage(Image3);
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addPixmap(image3);
    ui->ColorThreshedImageView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->ColorThreshedImageView->setScene(scene);
}