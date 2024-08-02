#include "imagecardwidget.h"
#include "ui_imagecardwidget.h"

ImageCardWidget::ImageCardWidget(const QString &title, const cv::Mat &imgPixels, QWidget *parent)
    : QWidget(parent), title(title), imgPixels(imgPixels), ui(new Ui::ImageCardWidget){
    ui->setupUi(this);
    ui->title->setText(this->title);
    ui->photo->setPixmap(convertMatToQPixmap(this->imgPixels));
}

ImageCardWidget::~ImageCardWidget()
{
    delete ui;
}

QPixmap ImageCardWidget::convertMatToQPixmap(const cv::Mat &mat){
    if (mat.empty()) return QPixmap();

    // Para convertir de BGR a RGB si es necesario
    cv::Mat rgbMat;
    if (mat.channels() == 3)
        cv::cvtColor(mat, rgbMat, cv::COLOR_BGR2RGB);
    else
        rgbMat = mat;


    // Crear QImage directamente desde cv::Mat
    QImage qImage((const unsigned char*)(rgbMat.data), rgbMat.cols, rgbMat.rows, rgbMat.step, QImage::Format_RGB888);

    // Convertir QImage a QPixmap
    return QPixmap::fromImage(qImage);
}

