#include "imageresultswidget.h"
#include "ui_imageresultswidget.h"

//TODO: agregar solo atributos que se necesitan de la imagen, puede ser una struct.
ImageResultsWidget::ImageResultsWidget(const QVector<ImageCardData> &imageCards,
                                       const struct ImageDetails &imageDetails, QWidget *parent)
    : imageDetails(imageDetails), imageCards(imageCards), QWidget(parent), ui(new Ui::ImageResultsWidget){
    ui->setupUi(this);
    ui->imageDetailsLayout->addWidget(new ImageDetailsWidget(imageDetails.name, imageDetails.filepath, imageDetails.size, this));
    this->addImageCards();
}

ImageResultsWidget::~ImageResultsWidget()
{
    delete ui;
}

void ImageResultsWidget::addImageCards() {
    for (const ImageCardData& card : imageCards){
        ui->imageCardsLayout->addWidget(new ImageCardWidget(card.title, card.imgPixels, this));
        ui->imageCardsLayout->addStretch(1);
    }
}

