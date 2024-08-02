/********************************************************************************
** Form generated from reading UI file 'menuwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName("MenuWidget");
        MenuWidget->resize(300, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MenuWidget->sizePolicy().hasHeightForWidth());
        MenuWidget->setSizePolicy(sizePolicy);
        MenuWidget->setMinimumSize(QSize(0, 0));
        MenuWidget->setMaximumSize(QSize(16777215, 16777215));
        MenuWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color:rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(MenuWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 0, 15, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QCoreApplication::translate("MenuWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
