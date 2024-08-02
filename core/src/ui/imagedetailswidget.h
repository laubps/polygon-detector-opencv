#ifndef IMAGEDETAILSWIDGET_H
#define IMAGEDETAILSWIDGET_H

#include <QWidget>
#include <utility>  // For std::move

#include "../core/image/image.h"

namespace Ui {
class ImageDetailsWidget;
}

class  ImageDetailsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageDetailsWidget(const QString &name, const QString &filepath, const QString &size, QWidget *parent = nullptr);
    ~ImageDetailsWidget();

private:
    Ui::ImageDetailsWidget *ui;
    const QString &name;
    const QString &filepath;
    const QString &size;
};

#endif
