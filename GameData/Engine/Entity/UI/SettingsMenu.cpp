#include "SettingsMenu.h"

//TODO: Resolution Drop Down Box Selector
//TODO: Fullscreen Tick Box
//TODO: Controls Menu

SettingsMenu::SettingsMenu() : applyButton("Apply", sf::Vector2f(100, 150)),
                               cancelButton("Cancel", sf::Vector2f(-225, 150)),
                               controlsButton("Controls", sf::Vector2f(-75, -75)),
                               s_resolutionText("Resolution", sf::Vector2f(-250, -300)),
                               s_fullscreenText("Fullscreen", sf::Vector2f(-250, -225))
{
    addComponent<Position>(sf::Vector2f(-300, -400));
    addComponent<Sprite>("UI/windowsheet.png");
}

void SettingsMenu::initialize()
{
    Entity::initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(15, 15);
    applyButton.initialize();
    cancelButton.initialize();
    controlsButton.initialize();
    s_resolutionText.initialize();
    s_fullscreenText.initialize();
}

void SettingsMenu::show()
{
    s_active = true;
}

void SettingsMenu::hide()
{
    s_active = false;
}

void SettingsMenu::handleInput(sf::Mouse::Button button)
{
    if (!s_active) return;
    Entity::handleInput(button);

    if (applyButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        hide();
    }
    else if (cancelButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        hide();
    }

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
    applyButton.render(window);
    cancelButton.render(window);
    controlsButton.render(window);
    s_fullscreenText.render(window);
    s_resolutionText.render(window);
}