#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include "opencv2/opencv.hpp"
#include "medianfilterplugin.h"

#define FILTERS_SUBFOLDER "/MedianFilterPlugin/"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mMedianFilterPlugin( new MedianFilterPlugin())
{
    ui->setupUi(this);

    connect(ui->mBrowseImagePushButton, SIGNAL(clicked()), this, SLOT(onBrowseImagePushButtonClicked()));
    connect(ui->mFilterPushButton, SIGNAL(clicked()), this, SLOT(onFilterPushButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBrowseImagePushButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Input Image"), QDir::currentPath(), tr("Images") + " (*.jpg *.png *.bmp)");

    if(QFile::exists(fileName))
    {
        ui->mInputImageLineEdit->setText(fileName);
    }
}

void MainWindow::onFilterPushButtonClicked()
{
    if(!ui->mInputImageLineEdit->text().isEmpty())
    {
        if(QFile::exists(ui->mInputImageLineEdit->text()))
        {

            cv::Mat inputImage, outputImage;
            inputImage = cv::imread(ui->mInputImageLineEdit->text().toStdString());
            mMedianFilterPlugin->processImage(inputImage, outputImage);
            imshow(tr("Filtered Image").toStdString(), outputImage);
        }
        else
        {
            QMessageBox::warning(this,
                                 tr("Warning"),
                                 QString(tr("Make sure %1 exists."))
                                 .arg(ui->mInputImageLineEdit->text()));
        }
    }
}
