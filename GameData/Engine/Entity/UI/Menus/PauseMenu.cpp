#include "PauseMenu.h"
#include "../../../Lvl/LevelManager.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"

PauseMenu::PauseMenu() : p_b_resume("Resume", sf::Vector2f(-50, -275)),
                         p_b_settings("Settings", sf::Vector2f(-50, -175)),
                         p_b_exit("Exit", sf::Vector2f(-50, -75)),
                         s_menu()
{
    addComponent<Position>(sf::Vector2f(-125, -350));
    addComponent<Sprite>("UI/ui.png");
}

void PauseMenu::initialize()
{
    Entity::initialize();
    p_b_resume.initialize();
    p_b_settings.initialize();
    p_b_exit.initialize();
    s_menu.initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(8, 12);
}

void PauseMenu::handleInput(sf::Mouse::Button button)
{
    if (!p_active) return;
    Entity::handleInput(button);
    s_menu.handleInput(button);
    if (s_menu.active()) return;
    if (p_b_resume.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        p_active = false;
        LevelManager::Instance()->getCurrentLevel().setState(GameState::RUNNING);
    }
    else if (p_b_settings.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        s_menu.show();
    }
    else if (p_b_exit.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        exit(0);
    }
}

void PauseMenu::handleInput(sf::Keyboard::Key key)
{
    Entity::handleInput(key);
    s_menu.handleInput(key);
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
    s_menu.render(window);
}