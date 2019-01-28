#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <QImageReader>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QRect>
#include <QSizePolicy>
#include <QImageWriter>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void load(QString fileName);
    void save(QString fileName);

    QString fileName;
private:
    Ui::Widget *ui;

    void loading();
    void saving();
    void thresholding();

    QImage newImage;
    QGraphicsScene *scene;
    QGraphicsScene *scene_2;

    QString savePath;
    QString threshold_value;
};

#endif // WIDGET_H
