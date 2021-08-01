#include "SettingsMenu.h"

SettingsMenu::SettingsMenu() : applyButton("Apply", sf::Vector2f(100, 150)),
                               cancelButton("Cancel", sf::Vector2f(-225, 150)),
                               controlsButton("Controls", sf::Vector2f(-65, -25)),
                               s_resolutionText("Resolution", sf::Vector2f(-200, -290), 30),
                               s_fullscreenText("Fullscreen", sf::Vector2f(-200, -185), 30),
                               s_fsrnTickBox(sf::Vector2f(125, -200)),
                               s_resDropBox(sf::Vector2f(0, -300)),
                               c_menu(sf::Vector2f(-300, -400))
{
    addComponent<Position>(sf::Vector2f(-300, -400));
    addComponent<Sprite>("UI/ui.png");
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
    s_fsrnTickBox.initialize();
    s_resDropBox.initialize();
    c_menu.initialize();
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
    if (c_menu.active())
    {
        c_menu.handleInput(button);
        return;
    }

    Entity::handleInput(button);

    if (applyButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        hide();
    }
    else if (cancelButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        hide();
    }
    else if (controlsButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        c_menu.show();
    }
    else if (s_fsrnTickBox.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        s_fsrnTickBox.set(!s_fsrnTickBox.get());
    }

}

void SettingsMenu::handleInput(sf::Keyboard::Key key)
{
    if (!s_active)       return;
    if (c_menu.active()) c_menu.handleInput(key);
    if (key == 36)       hide();
}

void SettingsMenu::render(sf::RenderWindow* window, uint8_t z)
{
    if (c_menu.active())
    {
        c_menu.render(window, z);
        return;
    }
    if (!s_active) return;
    Entity::render(window, z);
    applyButton.render(window, z);
    cancelButton.render(window, z);
    controlsButton.render(window, z);
    s_fullscreenText.render(window, z);
    s_resolutionText.render(window, z);
    s_fsrnTickBox.render(window, z);
    s_resDropBox.render(window, z);
}