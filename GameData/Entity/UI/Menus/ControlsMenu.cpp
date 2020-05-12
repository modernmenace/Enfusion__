#include "ControlsMenu.h"
#include "../../../Engine/Core/Settings.h"

ControlsMenu::ControlsMenu(sf::Vector2f position) : applyButton("Apply", sf::Vector2f(100, 150)),
                                                    cancelButton("Cancel", sf::Vector2f(-225, 150)),
                                                    c_Area(sf::Vector2f(position.x + 50, position.y + 50), sf::Vector2f(620, 475))
{
    addComponent<Position>(position);
    addComponent<Sprite>("UI/ui.png");
}

void ControlsMenu::initialize()
{
    Entity::initialize();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(15, 15);
    applyButton.initialize();
    cancelButton.initialize();
    c_Area.initialize();

    //TODO: init scroll area
    for(auto i = 0; i < Settings::Instance()->controlCount(); i++)
    {
        Control_t cntl = Settings::Instance()->controlAt(i);
        dbg_log(cntl.name);
    }
}

void ControlsMenu::handleInput(sf::Keyboard::Key key)
{
    if (!c_active) return;
    if (key == 36)
        hide();
}

void ControlsMenu::handleInput(sf::Mouse::Button button)
{
    if (!c_active) return;

    if (applyButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        //TODO: Implement this
    }
    else if (cancelButton.getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
    {
        hide();
    }
}

void ControlsMenu::show()
{
    c_active = true;
}

void ControlsMenu::render(sf::RenderWindow* window)
{
    if (!c_active) return;

    Entity::render(window);
    applyButton.render(window);
    cancelButton.render(window);
    c_Area.render(window);
}