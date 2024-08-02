/********************************************************************************
** Form generated from reading UI file 'imageresultswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGERESULTSWIDGET_H
#define UI_IMAGERESULTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageResultsWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *imageCardsLayout;
    QVBoxLayout *imageDetailsLayout;

    void setupUi(QWidget *ImageResultsWidget)
    {
        if (ImageResultsWidget->objectName().isEmpty())
            ImageResultsWidget->setObjectName("ImageResultsWidget");
        ImageResultsWidget->resize(609, 403);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageResultsWidget->sizePolicy().hasHeightForWidth());
        ImageResultsWidget->setSizePolicy(sizePolicy);
        ImageResultsWidget->setMaximumSize(QSize(1000, 800));
        ImageResultsWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(ImageResultsWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        imageCardsLayout = new QHBoxLayout();
        imageCardsLayout->setSpacing(30);
        imageCardsLayout->setObjectName("imageCardsLayout");

        verticalLayout->addLayout(imageCardsLayout);

        imageDetailsLayout = new QVBoxLayout();
        imageDetailsLayout->setSpacing(0);
        imageDetailsLayout->setObjectName("imageDetailsLayout");

        verticalLayout->addLayout(imageDetailsLayout);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ImageResultsWidget);

        QMetaObject::connectSlotsByName(ImageResultsWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageResultsWidget)
    {
        ImageResultsWidget->setWindowTitle(QCoreApplication::translate("ImageResultsWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageResultsWidget: public Ui_ImageResultsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGERESULTSWIDGET_H
