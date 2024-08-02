#include "menuwidget.h"
#include "ui_menuwidget.h"

MenuWidget::MenuWidget(std::vector<MenuButton *> &buttons, QWidget *parent)
    : buttons(buttons), QWidget(parent), ui(new Ui::MenuWidget){
    this->ui->setupUi(this);
    this->selectedItem = 0;

    connect(this, &MenuWidget::selectedItemChanged, this, &MenuWidget::updateAllButtonStyles);
    this->addButtons();
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

const MenuButton::Styles MenuWidget::defaultStyles = {"", "background-color: transparent; text-align: left;"};
const MenuButton::Styles MenuWidget::selectedStyles = defaultStyles + MenuButton::Styles({"background-color: black; border-radius: 15px;", "color: white;"});
const MenuButton::Styles MenuWidget::unselectedStyles = defaultStyles + MenuButton::Styles({"background-color: none;", "color: black;"});

// SLOTS //
void MenuWidget::onButtonPress(MenuButton* button){
    this->setSelectedItem(button->getId());
    this->updateAllButtonStyles();
}

// PUBLIC METHODS //
void MenuWidget::setSelectedItem(int item) {
    if (selectedItem != item) {
        selectedItem = item;
        emit selectedItemChanged(item);  // Emitir la señal cuando selectedItem cambia
    }
}

// PRIVATE METHODS //
void MenuWidget::updateAllButtonStyles() {
    for (MenuButton* button : this->buttons)
        button->setStylesIfSelected(button->getId() == this->selectedItem, &selectedStyles, &unselectedStyles);
}

//TODO: aqui manejar la señal
void MenuWidget::addButtons() {
    for (MenuButton *button : this->buttons){
        button->addOnClickedEvent([this, button]() { this->setSelectedItem(button->getId()); });
        button->setStylesIfSelected(button->getId() == this->selectedItem, &selectedStyles, &unselectedStyles);
        this->ui->verticalLayout->addWidget(button, 0, Qt::AlignTop);
    }
}
