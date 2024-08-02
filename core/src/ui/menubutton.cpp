#include "menubutton.h"
#include "ui_menubutton.h"


MenuButton::MenuButton(const int &id, const QString &text, const QIcon &icon,
                       std::function<void()> onClicked, QWidget *parent)
    : id(id), text(text), icon(icon), QWidget(parent), ui(new Ui::MenuButton) {

    ui->setupUi(this);
    ui->pushButton->setText(text);
    ui->label->setPixmap(icon.pixmap(QSize(20,20)));

    this->addOnClickedEvent(onClicked);
}

MenuButton::~MenuButton() {
    delete ui;
}

// EVENTS //
void MenuButton::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void MenuButton::addOnClickedEvent(std::function<void()> onClicked){
    connect(ui->pushButton, &QPushButton::clicked, this, onClicked);
}


// GETTERS //
const int& MenuButton::getId() const{
    return id;
}


// SETTERS //
void MenuButton::setStyles(const Styles *styles){
    QString containerStyle = "MenuButton { " + styles->container + "}";
    QString buttonStyle = "MenuButton QPushButton { " + styles->button + "}";
    QString MenuButtonStyleSheet = containerStyle + buttonStyle;

    this->ui->pushButton->setStyleSheet("");
    this->setStyleSheet(MenuButtonStyleSheet);
}

void MenuButton::setStylesIfSelected(bool isSelected, const Styles *selectedStyles, const Styles *unselectedStyles){
    if (isSelected)
        this->setStyles(selectedStyles);
    else
        this->setStyles(unselectedStyles);
}
