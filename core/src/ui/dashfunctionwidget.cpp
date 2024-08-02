#include "dashfunctionwidget.h"
#include "ui_dashfunctionwidget.h"

DashFunctionWidget::DashFunctionWidget(PolygonsDetector::Mode mode, QWidget *parent)
    : mode(mode), QWidget(parent), ui(new Ui::DashFunctionWidget){
    this->ui->setupUi(this);
    this->setStylesByMode();

    this->connect(ui->selectImageButton, &QPushButton::clicked, this, &DashFunctionWidget::onSelectImageClicked);
}

DashFunctionWidget::~DashFunctionWidget()
{
    delete ui;
}


void DashFunctionWidget::onSelectImageClicked()
{
    loadResultsByMode(getImageFromExplorer().toStdString());
    loadNextWidgetOnStack();
}

void DashFunctionWidget::loadNextWidgetOnStack() {
    int currentIndex = ui->stackedWidget->currentIndex();
    int nextIndex = (currentIndex + 1) % ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(nextIndex);

}

QString DashFunctionWidget::getImageFromExplorer(){
    QString filter = "Image Files (*.png *.jpg *.jpeg *.bmp *.gif)";
    QString filePath = QFileDialog::getOpenFileName(this, "Select an image", QDir::homePath(), filter);

    if (!filePath.isEmpty())
        return filePath;
    else
        return QString();
}

void DashFunctionWidget::loadResultsByMode(const string &filepath){

    try {
        PolygonsDetector pd(make_unique<Image>(filepath));
        //TODO: Aquí se debe pasar también el mode.
        pd.detectPolygons();
        pd.drawPolygonsOnImage(this->mode);
        addImageResultsWidget(pd);
    } catch (const std::runtime_error& e) {

    }

}

void DashFunctionWidget::addImageResultsWidget(PolygonsDetector &pd){

    const QVector<ImageResultsWidget::ImageCardData> imageCards = {
        {"Imagen original", pd.getImage().getPixels()},
        {"Imagen con polígonos", pd.getResultImage()},
    };

    const ImageResultsWidget::ImageDetails imageDetails = {
        QString::fromStdString(pd.getImage().getFileName()),
        QString::fromStdString(pd.getImage().getFilePath()),
        "Aquí va funciones para obtener medidas del tamaño de la imagen."
    };

    ui->stackedWidget->addWidget(new ImageResultsWidget(imageCards, imageDetails, this));
}

void DashFunctionWidget::setStylesByMode(){
    QString containerStyle = "QWidget { background-color: ";
    QString buttonStyle = "QPushButton {color: rgb(255,255,255); \
        font: 700 11pt Segoe UI Variable Small; \
        padding: 10px;\
        border-radius: 15px;\
        background-color: ";

    switch(this->mode){
    case PolygonsDetector::AREA:
        containerStyle += Colors::secondaryPurple;
        buttonStyle += Colors::primaryPurple;
        break;
    case PolygonsDetector::CONTOURS:
        containerStyle += Colors::secondaryPink;
        buttonStyle += Colors::primaryPink;
        break;
    case PolygonsDetector::PERIMETER:
        containerStyle += Colors::secondaryOrange;
        buttonStyle += Colors::primaryOrange;
        break;
    case PolygonsDetector::DETAILS:
        containerStyle += Colors::secondaryBlue;
        buttonStyle += Colors::primaryBlue;
        break;
    }

    containerStyle += " ;}";
    buttonStyle += " ;}";

    ui->selectImageWidget->setStyleSheet(containerStyle);
    ui->selectImageButton->setStyleSheet(buttonStyle);
}
