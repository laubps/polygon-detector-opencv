#ifndef DASHFUNCTIONWIDGET_H
#define DASHFUNCTIONWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDir>

#include "../core/polygon_detector/polygonsdetector.h"
#include "imageresultswidget.h"
#include "../../include/colors.h"

namespace Ui {
class DashFunctionWidget;
}

class DashFunctionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashFunctionWidget(PolygonsDetector::Mode mode, QWidget *parent = nullptr);
    ~DashFunctionWidget();

private slots:
    void onSelectImageClicked();

private:
    Ui::DashFunctionWidget *ui;
    PolygonsDetector::Mode mode;

    void loadNextWidgetOnStack();
    QString getImageFromExplorer();
    void loadResultsByMode(const string &filepath);
    void addImageResultsWidget(PolygonsDetector &pd);
    void setStylesByMode();
};

#endif // DashFunctionWidget_H
