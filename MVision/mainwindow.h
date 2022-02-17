#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QMessageBox>
#include <QPixmap>
#include <QDialog>
#include <QFileInfo>
#include <QFileDialog>
#include <QTimer>
#include <QDebug>
#include <QDir>

#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnScreen_clicked();
    void on_btnSave_clicked();
    void shoot();

    void on_actionLoad_Image_triggered();

private:
    Ui::MainWindow *ui;
    QPixmap m_image;
    QTimer m_timer;

};
#endif // MAINWINDOW_H
