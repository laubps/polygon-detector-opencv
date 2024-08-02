#include "./src/ui/mainwindow.h"

#include <QFile>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QApplication>
#include <QWidget>
#include <QPalette>

void loadColors(QPalette &palette) {
    QFile file(":/colors.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonObject json = doc.object();

    QJsonObject primaryPalette = json["colors"].toObject()["primary"].toObject();
    QColor backgroundColor(primaryPalette["background"].toString());
    QColor textColor(primaryPalette["text"].toString());
    QColor buttonColor(primaryPalette["button"].toString());

    palette.setColor(QPalette::Window, backgroundColor);
    palette.setColor(QPalette::WindowText, textColor);
    palette.setColor(QPalette::Button, buttonColor);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
