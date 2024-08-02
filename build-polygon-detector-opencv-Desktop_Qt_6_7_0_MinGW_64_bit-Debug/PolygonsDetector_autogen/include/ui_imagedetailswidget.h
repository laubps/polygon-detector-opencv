/********************************************************************************
** Form generated from reading UI file 'imagedetailswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDETAILSWIDGET_H
#define UI_IMAGEDETAILSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageDetailsWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *detailsDetail;
    QLabel *filepathValue;
    QLabel *filepathLabel;
    QLabel *nameLabel;
    QLabel *sizeLabel;
    QLabel *sizeValue;
    QLabel *nameValue;

    void setupUi(QWidget *ImageDetailsWidget)
    {
        if (ImageDetailsWidget->objectName().isEmpty())
            ImageDetailsWidget->setObjectName("ImageDetailsWidget");
        ImageDetailsWidget->resize(641, 116);
        ImageDetailsWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(ImageDetailsWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ImageDetailsWidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 15px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(22);
        gridLayout_2->setContentsMargins(20, 20, 20, 20);
        detailsDetail = new QGridLayout();
        detailsDetail->setSpacing(0);
        detailsDetail->setObjectName("detailsDetail");
        filepathValue = new QLabel(frame);
        filepathValue->setObjectName("filepathValue");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Small")});
        font.setPointSize(10);
        filepathValue->setFont(font);
        filepathValue->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        filepathValue->setWordWrap(true);

        detailsDetail->addWidget(filepathValue, 2, 1, 1, 1);

        filepathLabel = new QLabel(frame);
        filepathLabel->setObjectName("filepathLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Small")});
        font1.setPointSize(10);
        font1.setBold(true);
        filepathLabel->setFont(font1);
        filepathLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 0);\n"
"}"));

        detailsDetail->addWidget(filepathLabel, 2, 0, 1, 1);

        nameLabel = new QLabel(frame);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setFont(font1);
        nameLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 0);\n"
"}"));

        detailsDetail->addWidget(nameLabel, 0, 0, 1, 1);

        sizeLabel = new QLabel(frame);
        sizeLabel->setObjectName("sizeLabel");
        sizeLabel->setFont(font1);
        sizeLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 0);\n"
"}"));

        detailsDetail->addWidget(sizeLabel, 1, 0, 1, 1);

        sizeValue = new QLabel(frame);
        sizeValue->setObjectName("sizeValue");
        sizeValue->setFont(font);
        sizeValue->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
""));
        sizeValue->setWordWrap(true);

        detailsDetail->addWidget(sizeValue, 1, 1, 1, 1);

        nameValue = new QLabel(frame);
        nameValue->setObjectName("nameValue");
        nameValue->setFont(font);
        nameValue->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        nameValue->setWordWrap(true);

        detailsDetail->addWidget(nameValue, 0, 1, 1, 1);

        detailsDetail->setColumnStretch(0, 1);
        detailsDetail->setColumnStretch(1, 8);

        gridLayout_2->addLayout(detailsDetail, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ImageDetailsWidget);

        QMetaObject::connectSlotsByName(ImageDetailsWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageDetailsWidget)
    {
        ImageDetailsWidget->setWindowTitle(QCoreApplication::translate("ImageDetailsWidget", "Form", nullptr));
        filepathValue->setText(QCoreApplication::translate("ImageDetailsWidget", "D:CUCEI3RO_INFOPOOFiguresDetectionrestest.jpg", nullptr));
        filepathLabel->setText(QCoreApplication::translate("ImageDetailsWidget", "Ruta del archivo:", nullptr));
        nameLabel->setText(QCoreApplication::translate("ImageDetailsWidget", "Nombre del archivo: ", nullptr));
        sizeLabel->setText(QCoreApplication::translate("ImageDetailsWidget", "Info de tama\303\261o: ", nullptr));
        sizeValue->setText(QCoreApplication::translate("ImageDetailsWidget", "300 x 300     60 KB     96 dpi     8 bit", nullptr));
        nameValue->setText(QCoreApplication::translate("ImageDetailsWidget", "poligonos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageDetailsWidget: public Ui_ImageDetailsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDETAILSWIDGET_H
