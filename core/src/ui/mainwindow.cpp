 #include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MenuWidget *menuWidget = this->createMenuWidget();
    ui->sidebarVLayout->addWidget(menuWidget,0,Qt::AlignTop);
    ui->sidebarVLayout->setStretch(0,1);
    ui->sidebarVLayout->setStretch(1,10);
    this->setHeaderDescriptionByMode(PolygonsDetector::DEFAULT);

    connect(ui->contoursBtn, &QPushButton::clicked, this, &MainWindow::onContoursBtnClicked);
    connect(ui->perimetersBtn, &QPushButton::clicked, this, &MainWindow::onPerimetersBtnClicked);
    connect(ui->areasBtn, &QPushButton::clicked, this, &MainWindow::onAreasBtnClicked);
    connect(ui->detailsBtn, &QPushButton::clicked, this, &MainWindow::onDetailsBtnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// SLOTS //
void MainWindow::onStartBtnClicked()
{
    ui->headerTitle->setText("Dashboard");
    this->setHeaderDescriptionByMode(PolygonsDetector::DEFAULT);
    deleteImageResultsWidget();
    loadNextWidgetOnStack();
}

void MainWindow::onContoursBtnClicked()
{
    ui->headerTitle->setText("Encuentra figuras en imagen");
    this->setHeaderDescriptionByMode(PolygonsDetector::CONTOURS);
    updateDashStackedWidget(PolygonsDetector::CONTOURS);
    loadNextWidgetOnStack();
}

void MainWindow::onAreasBtnClicked()
{
    ui->headerTitle->setText("Encuentra areas en imagen");
    this->setHeaderDescriptionByMode(PolygonsDetector::AREA);
    updateDashStackedWidget(PolygonsDetector::AREA);
    loadNextWidgetOnStack();
}

void MainWindow::onPerimetersBtnClicked()
{
    ui->headerTitle->setText("Encuentra perimetros en imagen");
    this->setHeaderDescriptionByMode(PolygonsDetector::PERIMETER);
    updateDashStackedWidget(PolygonsDetector::PERIMETER);
    loadNextWidgetOnStack();
}

void MainWindow::onDetailsBtnClicked()
{
    ui->headerTitle->setText("Detalles de figuras en imagen");
    this->setHeaderDescriptionByMode(PolygonsDetector::DETAILS);
    updateDashStackedWidget(PolygonsDetector::DETAILS);
    loadNextWidgetOnStack();
}


// PRIVATE METHODS //

void MainWindow::loadNextWidgetOnStack() {
    int currentIndex = ui->dashStackedWidget->currentIndex();
    int nextIndex = (currentIndex + 1) % ui->dashStackedWidget->count();
    ui->dashStackedWidget->setCurrentIndex(nextIndex);
}

void MainWindow::deleteImageResultsWidget(){
    // Elimina todos los widgets actuales
    while (ui->dashStackedWidget->count() > 1) {
        QWidget* widget = ui->dashStackedWidget->widget(1);
        ui->dashStackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MainWindow::updateDashStackedWidget(PolygonsDetector::Mode mode){
    deleteImageResultsWidget();
    ui->dashStackedWidget->addWidget(new DashFunctionWidget(mode, this));
}

void MainWindow::setHeaderDescriptionByMode(PolygonsDetector::Mode mode){
    QString description;
    QString backgroundColor;

    switch(mode){
    case PolygonsDetector::CONTOURS:
        description = "Selecciona tu imagen para poder obtener el contorno de los polígonos dentro de esta.";
        backgroundColor = Colors::secondaryPink;
        break;
    case PolygonsDetector::AREA:
        description = "Selecciona tu archivo para obtener el area de los polígonos obtenidos.";
        backgroundColor = Colors::secondaryPurple;
        break;
    case PolygonsDetector::PERIMETER:
        description = "Selecciona tu archcivo para obtener el perimetro de los polígonos obtenidos";
        backgroundColor = Colors::secondaryOrange;
        break;
    case PolygonsDetector::DETAILS:
        description = "Selecciona tu archcivo para obtener los detalles de los polígonos obtenidos";
        backgroundColor = Colors::secondaryBlue;
        break;
    case PolygonsDetector::DEFAULT:
        description = "¡Bienvenido!. Con este programa puedes analizar imagenes y los polígonos dentro de ella.";
        backgroundColor = Colors::secondaryPink;
        break;
    }

    ui->headerDescription->setText(description);
    ui->headerDescription->setStyleSheet(ui->headerDescription->styleSheet() + "QLabel {background-color: " + backgroundColor + ";}");
}

MenuWidget* MainWindow::createMenuWidget(){
    std::vector<MenuButton*> buttons = {
        new MenuButton(0, "Inicio", QIcon(":/icons/start.svg"), std::bind(&MainWindow::onStartBtnClicked, this), this),
        new MenuButton(1, "Polígonos", QIcon(":/icons/start.svg"), std::bind(&MainWindow::onContoursBtnClicked, this), this),
        new MenuButton(2, "Areas", QIcon(":/icons/area.svg"), std::bind(&MainWindow::onAreasBtnClicked, this), this),
        new MenuButton(3, "Perimetros", QIcon(":/icons/perimeter.svg"), std::bind(&MainWindow::onPerimetersBtnClicked, this), this),
        new MenuButton(4, "Detalles", QIcon(":/icons/info.svg"), std::bind(&MainWindow::onDetailsBtnClicked, this), this),
    };

    return new MenuWidget(buttons, this);
}




