#include "PauseMenu.h"

PauseMenu::PauseMenu() : p_b_resume("Resume", sf::Vector2f(-50, -275)),
                         p_b_settings("Settings", sf::Vector2f(-50, -175)),
                         p_b_exit("Exit", sf::Vector2f(-50, -75))
{
    addComponent<Position>(sf::Vector2f(-125, -350));
    addComponent<Sprite>("UI/windowsheet.png");
}

void PauseMenu::initialize()
{
    Entity::initialize();
    p_b_resume.initialize();
    p_b_settings.initialize();
    p_b_exit.initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(8, 12);
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
    p_b_settings.render(window);
    p_b_exit.render(window);
}