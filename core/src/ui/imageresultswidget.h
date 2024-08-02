#ifndef IMAGERESULTSWIDGET_H
#define IMAGERESULTSWIDGET_H

#include <QWidget>
#include <utility>

#include "dashfunctionwidget.h"
#include "imagecardwidget.h"
#include "imagedetailswidget.h"


namespace Ui {
class ImageResultsWidget;
}

class ImageResultsWidget : public QWidget
{
    Q_OBJECT

public:
    struct ImageCardData{
        QString title;
        cv::Mat imgPixels;
    };

    struct ImageDetails{
        QString name;
        QString filepath;
        QString size;
    };

    explicit ImageResultsWidget(const QVector<ImageCardData> &imageCards,
                                const struct ImageDetails &imageDetails, QWidget *parent = nullptr);
    ~ImageResultsWidget();


private:
    Ui::ImageResultsWidget *ui;
    const QVector<struct ImageCardData> imageCards;
    const struct ImageDetails imageDetails;

    void addImageCards();
};

#endif // IMAGERESULTSWIDGET_H
