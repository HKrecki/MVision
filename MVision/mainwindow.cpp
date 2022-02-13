#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (QScreen *screen, QGuiApplication::screens()) {
        ui->cmbScreens->addItem(screen->name());
    }

    ui->btnSave->setEnabled(false);
    ui->LblScreen->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnScreen_clicked()
{
    QScreen *screen = QGuiApplication::screens().at(ui->cmbScreens->currentIndex());
    if(!screen){
        QMessageBox::critical(this,"Error", "Could not get the screen!");
        return;
    }

    hide();
    QTimer::singleShot(500, this, &MainWindow::shoot);
}

void MainWindow::on_btnSave_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "Save", QString(), "PNG image (*.png)");
    if(path.isEmpty())  return;

    QFileInfo fi(path);
    if(fi.exists()){
        QMessageBox::StandardButton btn = QMessageBox::question(this, "Exists", "File already exists, overwrite?");
        if(btn != QMessageBox::StandardButton::Yes) return;
    }

    if(!m_image.save(path, "PNG")){
        QMessageBox::critical(this,"Error", "Could not save image");
    }
}

void MainWindow::shoot()
{
    QScreen *screen = QGuiApplication::screens().at(ui->cmbScreens->currentIndex());

    m_image = screen->grabWindow(0);

    QPixmap m_scaled = m_image.scaled(ui->LblScreen->width(), ui->LblScreen->height(), Qt::AspectRatioMode::KeepAspectRatio);

    ui->LblScreen->setPixmap(m_scaled);
    ui->btnSave->setEnabled(true);
    show();
}












