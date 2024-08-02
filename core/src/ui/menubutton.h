#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class MenuButton;  // Forward declaration de la clase Ui
}

class MenuButton : public QWidget {
    Q_OBJECT

public:
    explicit MenuButton(const int &id, const QString &text, const QIcon &icon, std::function<void()> onClicked, QWidget *parent = nullptr);
    ~MenuButton();

    void addOnClickedEvent(std::function<void()> onClicked);

    //structs
    struct Styles{
        QString container;
        QString button;

        // Constructor que acepta listas de inicialización
        Styles(const QString &container = "", const QString &button = "")
            : button(button), container(container) {}

        Styles operator+(const Styles &other) const {
            Styles newStyles;
            newStyles.button = this->button + other.button;
            newStyles.container = this->container + other.container;
            return newStyles;
        }
    };

    //setters
    void setStyles(const Styles *styles);
    void setStylesIfSelected(bool isSelected, const Styles *selectedStyles, const Styles *unselectedStyles);

    //getters
    const int& getId() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MenuButton *ui;
    const QString text;
    const QIcon icon;
    const int id;
};

#endif // MENUBUTTON_H
