#include "SettingsMenu.h"

SettingsMenu::SettingsMenu()
{
    addComponent<Position>(sf::Vector2f(0, 0));
    addComponent<Sprite>("UI/windowsheet.png");
}

void SettingsMenu::initialize()
{
    Entity::initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(12, 15);
}

void SettingsMenu::show()
{
    s_active = true;
    dbg_log("Show called")
}

void SettingsMenu::hide()
{
    s_active = false;
}

void SettingsMenu::handleInput(sf::Mouse::Button button)
{
    if (!s_active) return;
    Entity::handleInput(button);
}

void SettingsMenu::handleInput(sf::Keyboard::Key key)
{
    if (!s_active) return;
    hide();
}

void SettingsMenu::render(sf::RenderWindow* window)
{
    if (!s_active) return;
    Entity::render(window);
}