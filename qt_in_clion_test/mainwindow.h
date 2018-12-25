//
// Created by top on 18-12-10.
//

#ifndef QT_TEST_MAINWINDOW_H
#define QT_TEST_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif //QT_TEST_MAINWINDOW_H
