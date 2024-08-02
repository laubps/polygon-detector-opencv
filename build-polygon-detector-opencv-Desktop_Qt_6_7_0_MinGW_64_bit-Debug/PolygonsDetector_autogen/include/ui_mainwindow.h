/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QWidget *sidebar;
    QVBoxLayout *sidebarVLayout_2;
    QVBoxLayout *sidebarVLayout;
    QLabel *logoLabel;
    QWidget *dashboardWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *header;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *headerVLayout;
    QLabel *headerTitle;
    QVBoxLayout *descriptionVLayout;
    QLabel *headerDescription;
    QStackedWidget *dashStackedWidget;
    QWidget *dashMenuWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *dashMenuHLayout;
    QGridLayout *dashMenuGridLayout;
    QPushButton *detailsBtn;
    QPushButton *areasBtn;
    QPushButton *perimetersBtn;
    QPushButton *contoursBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 566);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        mainWidget = new QWidget(MainWindow);
        mainWidget->setObjectName("mainWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy1);
        mainWidget->setMinimumSize(QSize(1000, 500));
        mainWidget->setMaximumSize(QSize(2000, 1500));
        mainWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: rgb(255, 255, 255)\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(mainWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        sidebar = new QWidget(mainWidget);
        sidebar->setObjectName("sidebar");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy2);
        sidebar->setMinimumSize(QSize(200, 0));
        sidebar->setMaximumSize(QSize(16777215, 16777215));
        sidebar->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border-right: 1px solid rgb(235, 235, 235);\n"
"	background-color: none:\n"
"}"));
        sidebarVLayout_2 = new QVBoxLayout(sidebar);
        sidebarVLayout_2->setSpacing(0);
        sidebarVLayout_2->setObjectName("sidebarVLayout_2");
        sidebarVLayout_2->setContentsMargins(0, 0, 0, 0);
        sidebarVLayout = new QVBoxLayout();
        sidebarVLayout->setSpacing(0);
        sidebarVLayout->setObjectName("sidebarVLayout");
        logoLabel = new QLabel(sidebar);
        logoLabel->setObjectName("logoLabel");
        sizePolicy1.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy1);
        logoLabel->setMinimumSize(QSize(0, 70));
        logoLabel->setMaximumSize(QSize(250, 70));
        logoLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	padding: 20px;\n"
"	padding-right: 40px;\n"
"	text-align: left;\n"
"}"));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/logo/logo.png")));
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        logoLabel->setMargin(0);

        sidebarVLayout->addWidget(logoLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        sidebarVLayout->setStretch(0, 1);

        sidebarVLayout_2->addLayout(sidebarVLayout);


        horizontalLayout->addWidget(sidebar);

        dashboardWidget = new QWidget(mainWidget);
        dashboardWidget->setObjectName("dashboardWidget");
        sizePolicy2.setHeightForWidth(dashboardWidget->sizePolicy().hasHeightForWidth());
        dashboardWidget->setSizePolicy(sizePolicy2);
        dashboardWidget->setMinimumSize(QSize(500, 0));
        dashboardWidget->setMaximumSize(QSize(16777215, 16777215));
        dashboardWidget->setAutoFillBackground(false);
        dashboardWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"rgb(249, 249, 249)\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(dashboardWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        header = new QWidget(dashboardWidget);
        header->setObjectName("header");
        sizePolicy1.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy1);
        header->setStyleSheet(QString::fromUtf8("QWidget {; \n"
"    background-color: rgb(255, 255, 255);\n"
"	border-bottom: 1px solid rgb(190, 190, 190);\n"
"	padding: 20px;\n"
"	padding-bottom:10px;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(header);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        headerVLayout = new QVBoxLayout();
        headerVLayout->setSpacing(0);
        headerVLayout->setObjectName("headerVLayout");
        headerVLayout->setContentsMargins(0, 0, 0, 0);
        headerTitle = new QLabel(header);
        headerTitle->setObjectName("headerTitle");
        headerTitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	padding: 30px 30px 10px 30px; \n"
"	font: 700 20pt \"Segoe UI Variable Small\";\n"
"	color: rgb(0,0,0);\n"
"border-color: rgb(255,255,255);\n"
"}"));

        headerVLayout->addWidget(headerTitle);

        descriptionVLayout = new QVBoxLayout();
        descriptionVLayout->setSpacing(0);
        descriptionVLayout->setObjectName("descriptionVLayout");
        descriptionVLayout->setContentsMargins(30, 0, 30, 15);
        headerDescription = new QLabel(header);
        headerDescription->setObjectName("headerDescription");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(headerDescription->sizePolicy().hasHeightForWidth());
        headerDescription->setSizePolicy(sizePolicy3);
        headerDescription->setMaximumSize(QSize(16777215, 40));
        headerDescription->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	padding: 5px 10px;\n"
"	font: 500 9pt \"Segoe UI Variable Small\";\n"
"background-color: rgb(255, 219, 239);\n"
"color: rgb(0,0,0);\n"
"border-radius: 10px;\n"
"}"));

        descriptionVLayout->addWidget(headerDescription);


        headerVLayout->addLayout(descriptionVLayout);

        headerVLayout->setStretch(0, 3);

        verticalLayout_4->addLayout(headerVLayout);


        verticalLayout->addWidget(header);

        dashStackedWidget = new QStackedWidget(dashboardWidget);
        dashStackedWidget->setObjectName("dashStackedWidget");
        sizePolicy1.setHeightForWidth(dashStackedWidget->sizePolicy().hasHeightForWidth());
        dashStackedWidget->setSizePolicy(sizePolicy1);
        dashStackedWidget->setMinimumSize(QSize(0, 0));
        dashStackedWidget->setMaximumSize(QSize(16777215, 16777215));
        dashStackedWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color:  rgb(235, 235, 235);\n"
"}"));
        dashMenuWidget = new QWidget();
        dashMenuWidget->setObjectName("dashMenuWidget");
        sizePolicy1.setHeightForWidth(dashMenuWidget->sizePolicy().hasHeightForWidth());
        dashMenuWidget->setSizePolicy(sizePolicy1);
        dashMenuWidget->setMinimumSize(QSize(0, 0));
        dashMenuWidget->setMaximumSize(QSize(16777215, 16777215));
        dashMenuWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(dashMenuWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        dashMenuHLayout = new QHBoxLayout();
        dashMenuHLayout->setSpacing(0);
        dashMenuHLayout->setObjectName("dashMenuHLayout");
        dashMenuHLayout->setContentsMargins(30, 30, 30, 30);
        dashMenuGridLayout = new QGridLayout();
        dashMenuGridLayout->setSpacing(30);
        dashMenuGridLayout->setObjectName("dashMenuGridLayout");
        detailsBtn = new QPushButton(dashMenuWidget);
        detailsBtn->setObjectName("detailsBtn");
        sizePolicy1.setHeightForWidth(detailsBtn->sizePolicy().hasHeightForWidth());
        detailsBtn->setSizePolicy(sizePolicy1);
        detailsBtn->setMinimumSize(QSize(0, 0));
        detailsBtn->setMaximumSize(QSize(16777215, 16777215));
        detailsBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(':/functions/2.png') stretch;\n"
"	border-radius: 20;\n"
"}\n"
""));

        dashMenuGridLayout->addWidget(detailsBtn, 0, 3, 1, 1);

        areasBtn = new QPushButton(dashMenuWidget);
        areasBtn->setObjectName("areasBtn");
        sizePolicy1.setHeightForWidth(areasBtn->sizePolicy().hasHeightForWidth());
        areasBtn->setSizePolicy(sizePolicy1);
        areasBtn->setMinimumSize(QSize(0, 0));
        areasBtn->setMaximumSize(QSize(16777215, 16777215));
        areasBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(':/functions/4.png') stretch;\n"
"	border-radius: 20;\n"
"}\n"
""));

        dashMenuGridLayout->addWidget(areasBtn, 1, 3, 1, 1);

        perimetersBtn = new QPushButton(dashMenuWidget);
        perimetersBtn->setObjectName("perimetersBtn");
        sizePolicy1.setHeightForWidth(perimetersBtn->sizePolicy().hasHeightForWidth());
        perimetersBtn->setSizePolicy(sizePolicy1);
        perimetersBtn->setMinimumSize(QSize(0, 0));
        perimetersBtn->setMaximumSize(QSize(16777215, 16777215));
        perimetersBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(':/functions/3.png') stretch;\n"
"	border-radius: 20;\n"
"}\n"
""));

        dashMenuGridLayout->addWidget(perimetersBtn, 1, 2, 1, 1);

        contoursBtn = new QPushButton(dashMenuWidget);
        contoursBtn->setObjectName("contoursBtn");
        sizePolicy1.setHeightForWidth(contoursBtn->sizePolicy().hasHeightForWidth());
        contoursBtn->setSizePolicy(sizePolicy1);
        contoursBtn->setMinimumSize(QSize(0, 0));
        contoursBtn->setMaximumSize(QSize(16777215, 16777215));
        contoursBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(':/functions/1') stretch;\n"
"	border-radius: 20;\n"
"}\n"
""));

        dashMenuGridLayout->addWidget(contoursBtn, 0, 2, 1, 1);


        dashMenuHLayout->addLayout(dashMenuGridLayout);


        verticalLayout_5->addLayout(dashMenuHLayout);

        dashStackedWidget->addWidget(dashMenuWidget);

        verticalLayout->addWidget(dashStackedWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);

        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(dashboardWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        horizontalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(mainWidget);

        retranslateUi(MainWindow);

        dashStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logoLabel->setText(QString());
        headerTitle->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        headerDescription->setText(QCoreApplication::translate("MainWindow", "Bienvenido. Con este programa puedes analizar imagenes y los pol\303\255gonos dentro de ella.", nullptr));
        detailsBtn->setText(QString());
        areasBtn->setText(QString());
        perimetersBtn->setText(QString());
        contoursBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
