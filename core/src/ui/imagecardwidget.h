#ifndef PHOTOCARDWIDGET_H
#define PHOTOCARDWIDGET_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include <QWidget>
#include "../core/image/image.h"

namespace Ui {
class ImageCardWidget;
}

class ImageCardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageCardWidget(const QString &title, const cv::Mat &imgPixels, QWidget *parent = nullptr);
    ~ImageCardWidget();

private:
    Ui::ImageCardWidget *ui;
    const QString title;
    const cv::Mat imgPixels;

    QPixmap convertMatToQPixmap(const cv::Mat &pixelsMat);
};

#endif // PHOTOCARDWIDGET_H
