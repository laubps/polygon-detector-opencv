/********************************************************************************
** Form generated from reading UI file 'dashfunctionwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHFUNCTIONWIDGET_H
#define UI_DASHFUNCTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashFunctionWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *selectImageWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *selectImageWidgetLayout;
    QFrame *container;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *containerVerticalLayout;
    QLabel *label;
    QPushButton *selectImageButton;

    void setupUi(QWidget *DashFunctionWidget)
    {
        if (DashFunctionWidget->objectName().isEmpty())
            DashFunctionWidget->setObjectName("DashFunctionWidget");
        DashFunctionWidget->resize(507, 407);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DashFunctionWidget->sizePolicy().hasHeightForWidth());
        DashFunctionWidget->setSizePolicy(sizePolicy);
        DashFunctionWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(DashFunctionWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(30, 30, 30, 30);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(DashFunctionWidget);
        stackedWidget->setObjectName("stackedWidget");
        selectImageWidget = new QWidget();
        selectImageWidget->setObjectName("selectImageWidget");
        selectImageWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(selectImageWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        selectImageWidgetLayout = new QVBoxLayout();
        selectImageWidgetLayout->setSpacing(0);
        selectImageWidgetLayout->setObjectName("selectImageWidgetLayout");
        selectImageWidgetLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        container = new QFrame(selectImageWidget);
        container->setObjectName("container");
        container->setFrameShape(QFrame::StyledPanel);
        container->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(container);
        verticalLayout_7->setObjectName("verticalLayout_7");
        containerVerticalLayout = new QVBoxLayout();
        containerVerticalLayout->setSpacing(15);
        containerVerticalLayout->setObjectName("containerVerticalLayout");
        label = new QLabel(container);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color: rgb(0,0,0);\n"
"	\n"
"	font: 700 14pt \"Segoe UI Variable Small\";\n"
"}"));

        containerVerticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        selectImageButton = new QPushButton(container);
        selectImageButton->setObjectName("selectImageButton");
        sizePolicy1.setHeightForWidth(selectImageButton->sizePolicy().hasHeightForWidth());
        selectImageButton->setSizePolicy(sizePolicy1);
        selectImageButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(255,255,255);\n"
"	font: 700 12pt \"Segoe UI Variable Small\";\n"
"	padding: 10px;\n"
"	border-radius: 15px;\n"
"}"));

        containerVerticalLayout->addWidget(selectImageButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_7->addLayout(containerVerticalLayout);


        selectImageWidgetLayout->addWidget(container, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_4->addLayout(selectImageWidgetLayout);

        stackedWidget->addWidget(selectImageWidget);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DashFunctionWidget);

        QMetaObject::connectSlotsByName(DashFunctionWidget);
    } // setupUi

    void retranslateUi(QWidget *DashFunctionWidget)
    {
        DashFunctionWidget->setWindowTitle(QCoreApplication::translate("DashFunctionWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("DashFunctionWidget", "Selecciona una imagen", nullptr));
        selectImageButton->setText(QCoreApplication::translate("DashFunctionWidget", "Abrir el explorador de archivos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashFunctionWidget: public Ui_DashFunctionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHFUNCTIONWIDGET_H
