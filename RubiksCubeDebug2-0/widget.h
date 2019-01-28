#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWidget>
#include <QString>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <QImageReader>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QRect>
#include <QSizePolicy>
#include <QImageWriter>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <QPushButton>

using namespace std;
using namespace cv;

struct FACE{
    QString faceCode; //每个面的代号，'L','U','R','D','F','B'
    QString faceName; //每个面的名字， 'left','up','right','down',front','back'
    int s_max; //每个色块的最大面积
    int s_min; //每个色块的最小面积
    Mat src; //经过一整图片的拆分后得到的每一个图的数据
    Point2f lt; //左上角的顶点
    Point2f lb; //左下角的顶点
    Point2f rt; //右上角的顶点
    Point2f rb; //右下角的顶点
};

struct COLOR{
    QString colorCode; //每个颜色的代号，'B','W','R','Y','G','O'
    QString colorNameString; //每个颜色的名字，'blue','white','red','yellow','green','orange'
    int H_Low; //H参数的最小值
    int H_High; //H参数的最大值
    int S_Low; //S参数的最小值
    int S_High; //S参数的最大值
    int V_Low; //V参数的最小值
    int V_High; //V参数的最大值
    Mat color_thresh; //HSV颜色阈值化后的图像
};
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QString fileName;

    Mat face_l;
    Mat face_r;
    Mat face_t;
    Mat face_f;
    Mat face_d;
    Mat face_b;

    FACE left = {"L", "Left", 4350, 1900, face_l, Point(229, 176), Point(241, 324),
                 Point(377, 247), Point(365, 398)};
    FACE right = {"R", "Right", 4350, 1400, face_r, Point(377, 247), Point(369, 405),
                  Point(493, 175), Point(476, 315)};
    FACE up = {"U", "Up", 3550, 1400, face_t, Point(355, 765), Point(456, 246),
               Point(490, 147), Point(376, 238)};
    FACE front = {"F", "Front", 3550, 1400, face_f, Point(876, 134), Point(230, 767),
                  Point(490, 147), Point(376, 238)};
    FACE down = {"D", "Down", 3550, 1400, face_d, Point(688, 223), Point(433, 976),
                 Point(490, 147), Point(376, 238)};
    FACE back = {"B", "Back", 3550, 1400, face_b, Point(887, 232), Point(230, 167),
                 Point(490, 147), Point(376, 238)};

    Mat W_Thresholded;
    Mat R_Thresholded;
    Mat G_Thresholded;
    Mat B_Thresholded;
    Mat O_Thresholded;
    Mat Y_Thresholded;

    COLOR blue = {"B", "Blue", 101, 150, 128, 255, 128, 255, B_Thresholded};
    COLOR white = {"W", "White", 10, 43, 0, 50, 50, 255, W_Thresholded};
    COLOR red = {"R", "Red", 0, 9, 128, 255, 128, 255, R_Thresholded};
    COLOR green = {"G", "Green", 46, 100, 128, 255, 128, 255, G_Thresholded};
    COLOR orange = {"O", "Orange", 10, 15, 128, 255, 128, 255, O_Thresholded};
    COLOR yellow = {"Y", "Yellow", 16, 45, 128, 255, 128, 255, Y_Thresholded};

    FACE getFace(QString faceName){
        if(faceName == "Up") return this->up;
        else if(faceName == "Front") return this->front;
        else if(faceName == "Left") return this->left;
        else if(faceName == "Right") return this->right;
        else if(faceName == "Back") return this->back;
        else if(faceName == "Down") return this->down;
    }

    int getFaceRotateStatus(QString faceName){
        if(faceName == "Up") return 1;
        else return 0;
    }

    COLOR getColor(QString colorName){
        if(colorName == "Blue") return this->blue;
        else if(colorName == "White") return this->white;
        else if(colorName == "Red") return this->red;
        else if(colorName == "Yellow") return this->yellow;
        else if(colorName == "Orange") return this->orange;
        else if(colorName == "Green") return this->green;
        else{ qDebug()<<"Wrong Color Name."<<endl;}
    }

private:
    Ui::Widget *ui;

    QImage Image1;
    QString faceName;
    QString colorName;

    void loading();
    void affining(QString faceName);
    void threshing(QString colorName);
    void setHSV();
    void showHSV();
    void DisplayScene1Image();
    void DisplayScene2Image(QString faceName);
    void DisplayScene3Image(QString colorName);

    QString this_face_color(FACE face, int isRotate = 0){
        if(face.src.empty() != 0){
            qDebug()<<"face source Mat is empty"<<endl;
        }
        qDebug()<<"Detecting this face color..."<<endl;
        QString color_this_face;
        vector<Rect> ROI_rect = getROI(face.src, face.s_max, face.s_min);
        if(ROI_rect.size() != 9){
            qDebug()<<"False to get the right number of the blocks."<<endl;
            qDebug()<<"Please fix your auguments."<<endl;
            return "return false";
        }
        Mat imgHSV;
        vector<Mat> hsvSplit;
        cvtColor(face.src, imgHSV, COLOR_BGR2HSV);
        inRange(imgHSV, Scalar(white.H_Low, white.S_Low, white.V_Low),
                Scalar(white.H_High, white.S_High, white.V_High), W_Thresholded);
        inRange(imgHSV, Scalar(red.H_Low, red.S_Low, red.V_Low),
                Scalar(red.H_High, red.S_High, red.V_High), R_Thresholded);
        inRange(imgHSV, Scalar(green.H_Low, green.S_Low, green.V_Low),
                Scalar(green.H_High, green.S_High, green.V_High), G_Thresholded);
        inRange(imgHSV, Scalar(blue.H_Low, blue.S_Low, blue.V_Low),
                Scalar(blue.H_High, blue.S_High, blue.V_High), B_Thresholded);
        inRange(imgHSV, Scalar(orange.H_Low, orange.S_Low, orange.V_Low),
                Scalar(orange.H_High, orange.S_High, orange.V_High), O_Thresholded);
        inRange(imgHSV, Scalar(yellow.H_Low, yellow.S_Low, yellow.V_Low),
                Scalar(yellow.H_High, yellow.S_High, yellow.V_High), Y_Thresholded);
        blue.color_thresh = B_Thresholded;
        white.color_thresh = W_Thresholded;
        green.color_thresh = G_Thresholded;
        orange.color_thresh = O_Thresholded;
        red.color_thresh = R_Thresholded;
        yellow.color_thresh = Y_Thresholded;
        colorV.push_back(blue);
        colorV.push_back(white);
        colorV.push_back(red);
        colorV.push_back(green);
        colorV.push_back(orange);
        colorV.push_back(yellow);
        for(auto item = colorV.begin(); item != colorV.end(); ++item){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    COLOR it = *item;
                    Mat roi = it.color_thresh(ROI_rect[3*i+j]);
                    int isColor = Sum(roi);
//                cout<<"isColor:"<< isColor<<endl;
                    if (isColor > 40) {
//                        rectangle(face.src, ROI_rect[3 * i + j], Scalar(0, 255, 0));
//                        putText(face.src, it.colorNameString, ROI_rect[3*i+j].tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0,255,0), 1);
                        qDebug()<<"it color code:"<<it.colorCode<<endl;
                        color_this_face.append(it.colorCode);
                    }
                }
            }
        }
        qDebug()<<"color_this_face:"<<color_this_face<<endl;
        if(isRotate == 0) {return color_this_face;}
        else {return reversalStr(color_this_face);}
    }
    void separate(const QString fileName){
        qDebug()<<"Separating..."<<endl;
        Mat src = cv::imread(fileName.toStdString());
        if(src.empty() != 0){
            qDebug()<<"separate source Mat is empty"<<endl;
        }
        Mat src_scaled ;
        cv::resize(src, src_scaled, Size(800,452));
        Point2f OriPoint_l[3] = {left.lt, left.lb, left.rb};
        Point2f OriPoint_r[3] = {right.lt, right.lb, right.rb};
        Point2f OriPoint_t[3] = {up.lt, up.lb, up.rb};
        Point2f AffinePoint[3] = {Point(30, 30), Point(30, 230), Point(230,230)};
        Mat AffineMatrix_l = getAffineTransform(OriPoint_l, AffinePoint);
        Mat AffineMatrix_r = getAffineTransform(OriPoint_r, AffinePoint);
        Mat AffineMatrix_t = getAffineTransform(OriPoint_t, AffinePoint);
        warpAffine(src_scaled, this->left.src, AffineMatrix_l, Size(260, 260));
        warpAffine(src_scaled, this->right.src, AffineMatrix_r, Size(260, 260));
        warpAffine(src_scaled, this->up.src, AffineMatrix_t, Size(260, 260));
        if(right.src.empty() != 0){
            qDebug()<<"right source Mat is empty"<<endl;
        }
    }
    int Sum(Mat& src){
        int counter = 0;
        //迭代器访问像素点
        Mat_<uchar>::iterator it = src.begin<uchar>();
        Mat_<uchar>::iterator itend = src.end<uchar>();
        for (; it != itend; ++it)
        {
            if ((*it)>0)
                counter += 1;
        }
        return counter;
    }
    vector<Rect> getROI(Mat &src, int s_max, int s_min){
        qDebug() << "Getting ROI..." << endl;
        Mat musk, gray, blurred, canny, dilated;
        src.copyTo(musk);
        cvtColor(src, gray, CV_RGB2GRAY);
        GaussianBlur(gray, blurred, Size(15,15), 0);
        Canny(blurred, canny, 20, 40);
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
        dilate(canny, dilated, element, Point(-1,-1), 2);
        vector<vector<Point>>contours;
        vector<Vec4i>hierarchy;
        findContours(dilated, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
        vector<Rect> rect;
        for(int i=0; i<contours.size(); i++){
            Rect rect_tmp = boundingRect(contours[i]);
            double s = rect_tmp.area();
//        cout<<"Square area :"<<s<<"  hierarchy:"<<hierarchy[i][2]<<endl;
            rectangle(musk, rect_tmp.tl(), rect_tmp.br(), Scalar(0, 255, 0));
            if(hierarchy[i][2] == -1 && s>s_min && s<s_max){
                rect.push_back(rect_tmp);
            }
        }
        sort(rect.begin(), rect.end(), comp);
        return rect;
    }
    vector<COLOR> colorV;
    static bool comp(const Rect &a, const Rect &b) {
        if(fabs(a.y-b.y)>40){
            if(a.y > b.y) return false;
            else return true;
        }else{
            if(a.x > b.x) return false;
            else return true;
        }
    }
    QString reversalStr(QString &str) {
        QString ret;
        for(QChar sz:str)
        {
            ret.push_front(sz);
        }
        return ret;
    }
    void getWhichColorThreshed(Mat& imgHSV, COLOR whichColor){
        inRange(imgHSV, Scalar(whichColor.H_Low, whichColor.S_Low, whichColor.V_Low),
                Scalar(whichColor.H_High, whichColor.S_High, whichColor.V_High), whichColor.color_thresh);
    }

};

#endif // WIDGET_H
