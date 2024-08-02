/********************************************************************************
** Form generated from reading UI file 'imagecardwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECARDWIDGET_H
#define UI_IMAGECARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageCardWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *vLayout;
    QLabel *title;
    QLabel *photo;

    void setupUi(QWidget *ImageCardWidget)
    {
        if (ImageCardWidget->objectName().isEmpty())
            ImageCardWidget->setObjectName("ImageCardWidget");
        ImageCardWidget->resize(450, 450);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageCardWidget->sizePolicy().hasHeightForWidth());
        ImageCardWidget->setSizePolicy(sizePolicy);
        ImageCardWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(ImageCardWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ImageCardWidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 20px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        vLayout = new QVBoxLayout();
        vLayout->setSpacing(20);
        vLayout->setObjectName("vLayout");
        title = new QLabel(frame);
        title->setObjectName("title");
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Small")});
        font.setPointSize(12);
        font.setBold(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	padding: 0px 10px;\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        vLayout->addWidget(title);

        photo = new QLabel(frame);
        photo->setObjectName("photo");
        sizePolicy.setHeightForWidth(photo->sizePolicy().hasHeightForWidth());
        photo->setSizePolicy(sizePolicy);
        photo->setMinimumSize(QSize(0, 0));
        photo->setMaximumSize(QSize(16777215, 16777215));
        photo->setStyleSheet(QString::fromUtf8(""));
        photo->setPixmap(QPixmap(QString::fromUtf8(":/test/test.jpg")));
        photo->setScaledContents(true);
        photo->setAlignment(Qt::AlignCenter);

        vLayout->addWidget(photo);

        vLayout->setStretch(0, 1);
        vLayout->setStretch(1, 10);

        verticalLayout->addLayout(vLayout);


        verticalLayout_2->addWidget(frame);


        retranslateUi(ImageCardWidget);

        QMetaObject::connectSlotsByName(ImageCardWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageCardWidget)
    {
        ImageCardWidget->setWindowTitle(QCoreApplication::translate("ImageCardWidget", "Form", nullptr));
        title->setText(QCoreApplication::translate("ImageCardWidget", "Imagen Original", nullptr));
        photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageCardWidget: public Ui_ImageCardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECARDWIDGET_H
