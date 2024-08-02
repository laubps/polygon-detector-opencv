/********************************************************************************
** Form generated from reading UI file 'menubutton.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUBUTTON_H
#define UI_MENUBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuButton
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *MenuButton)
    {
        if (MenuButton->objectName().isEmpty())
            MenuButton->setObjectName("MenuButton");
        MenuButton->resize(400, 52);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MenuButton->sizePolicy().hasHeightForWidth());
        MenuButton->setSizePolicy(sizePolicy);
        MenuButton->setMinimumSize(QSize(0, 0));
        MenuButton->setMaximumSize(QSize(16777215, 60));
        MenuButton->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(MenuButton);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(MenuButton);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	text-align: center;\n"
"	padding: 15px; \n"
"	border: none;\n"
"	background-color: none;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../res/area.svg")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(MenuButton);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Small")});
        font.setPointSize(12);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: left;\n"
"	border: none;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: none;\n"
"}"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);

        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MenuButton);

        QMetaObject::connectSlotsByName(MenuButton);
    } // setupUi

    void retranslateUi(QWidget *MenuButton)
    {
        MenuButton->setWindowTitle(QCoreApplication::translate("MenuButton", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MenuButton", "Inicio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuButton: public Ui_MenuButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBUTTON_H
