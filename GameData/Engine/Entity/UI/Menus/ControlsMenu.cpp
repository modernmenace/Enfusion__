#include "ControlsMenu.h"

ControlsMenu::ControlsMenu(sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");
}

void ControlsMenu::initialize()
{
    Entity::initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(15, 15);
}

void ControlsMenu::handleInput(sf::Mouse::Button button)
{

}

void ControlsMenu::show()
{
    c_active = true;
}

void ControlsMenu::render(sf::RenderWindow* window)
{
    if (!c_active) return;

    Entity::render(window);

}