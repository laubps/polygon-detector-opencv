#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <Qvector>
#include <QString>
#include <QStackedWidget>

#include "menubutton.h"

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(std::vector<MenuButton*> &buttons, QWidget *parent = nullptr);
    ~MenuWidget();

    void setSelectedItem(const int selected);


public slots:
    void onButtonPress(MenuButton* button);

signals:
    void selectedItemChanged(int newItem);

private:
    Ui::MenuWidget *ui;

    static const MenuButton::Styles defaultStyles;
    static const MenuButton::Styles selectedStyles;
    static const MenuButton::Styles unselectedStyles;

    std::vector<MenuButton*> buttons;
    int selectedItem;

    void addButtons();
    void updateAllButtonStyles();
};

#endif // MENUWIDGET_H
