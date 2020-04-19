#include "PauseMenu.h"

PauseMenu::PauseMenu() : p_b_resume("Resume", sf::Vector2f(-50, 0))
{
    addComponent<Position>(sf::Vector2f(-125, -400));
    addComponent<Sprite>("UI/windowsheet.png");
}

void PauseMenu::initialize()
{
    Entity::initialize();
    p_b_resume.initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(8, 15);
}

void PauseMenu::handleInput(sf::Mouse::Button button)
{
    if (!p_active) return;
    Entity::handleInput(button);
}

void PauseMenu::toggleMenu()
{
    p_active = !p_active;
}

void PauseMenu::render(sf::RenderWindow *window)
{
    if (!p_active) return;
    Entity::render(window);
    p_b_resume.render(window);
}