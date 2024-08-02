#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "../core/image/image.h"
#include "MenuButton.h"
#include "menuwidget.h"
#include "dashfunctionwidget.h"
#include "../core/polygon_detector/polygonsdetector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartBtnClicked();
    void onContoursBtnClicked();
    void onAreasBtnClicked();
    void onPerimetersBtnClicked();
    void onDetailsBtnClicked();

private:
    Ui::MainWindow *ui;
    MenuWidget* createMenuWidget();
    void deleteImageResultsWidget();
    void loadNextWidgetOnStack();
    void updateDashStackedWidget(PolygonsDetector::Mode mode);
    void setHeaderDescriptionByMode(PolygonsDetector::Mode mode);
};
#endif // MAINWINDOW_H
