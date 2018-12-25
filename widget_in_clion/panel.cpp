#include "widget.h"
#include "ui_widget.h"

using namespace cv;
using namespace std;

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);
    connect(ui->load, &QPushButton::released, this, &Widget::loading);
    connect(ui->save, &QPushButton::released, this, &Widget::saving);
    connect(ui->threshold, &QPushButton::released, this, &Widget::thresholding);
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
    QPixmap image = QPixmap::fromImage(newImage);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    ui->graphicsView->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->graphicsView->setScene(scene);
    return;
}

void Widget::saving() {
    qDebug() << "Hello world!";
    savePath = QFileDialog::getSaveFileName(this,
                                            tr("Save File"), "",
                                            tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;All Files (*)"));
    qDebug() << "save path:" << savePath;
    qDebug() << "result:" << newImage.save(savePath);
    return;
}

void Widget::thresholding() {
    qDebug() << "Hello world!";
    if (fileName.isNull()) {
        qDebug() << "Haven't choose the picture yet!";
        return;
    }
    qDebug() << fileName;
    cout << fileName.toStdString() << endl;
    Mat src = imread(fileName.toStdString(), CV_LOAD_IMAGE_COLOR);
    cout << "source image rows:" << src.rows << ",source image columns:" << src.cols << endl;
    Mat dst = Mat(src.size(), src.type());
    cvtColor(src, src, CV_RGB2GRAY);
    threshold_value = ui->thresh_value->text();
    threshold(src, dst, threshold_value.toInt(), 255, THRESH_BINARY);
    QImage img((uchar *) dst.data, dst.cols, dst.rows, QImage::Format_Grayscale8);
    QPixmap image = QPixmap::fromImage(img);
    scene_2 = new QGraphicsScene(this);
    scene_2->addPixmap(image);
    ui->graphicsView_2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->graphicsView_2->setScene(scene_2);
    return;
}

void Widget::load(QString fileName) {
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
    QPixmap image = QPixmap::fromImage(newImage);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    ui->graphicsView->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->graphicsView->setScene(scene);
    return;
}

void Widget::save(QString fileName) {
    qDebug() << "save path:" << fileName;
    qDebug() << "result:" << newImage.save(fileName);
    return;
}

