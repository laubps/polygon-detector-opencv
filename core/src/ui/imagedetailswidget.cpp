#include "imagedetailswidget.h"
#include "ui_imagedetailswidget.h"

ImageDetailsWidget::ImageDetailsWidget(const QString &name, const QString &filepath, const QString &size,  QWidget *parent)
    : name(name), filepath(filepath), size(size), QWidget(parent), ui(new Ui::ImageDetailsWidget)
{
    ui->setupUi(this);
    ui->nameValue->setText(name);
    ui->filepathValue->setText(filepath);
    ui->sizeValue->setText(size);
}

ImageDetailsWidget::~ImageDetailsWidget() {
    delete ui;
}

//TODO: Hacer funciones en clase imagen calculat peso, dpi y bits.
// QString ImageDetailsWidget::formatSizeData(){
//     return this->sizeInfo.pixels + "     "
//            + this->sizeInfo.weight + "     "
//            + this->sizeInfo.dpi + "     "
//            + this->sizeInfo.bits + "     ";
// }
