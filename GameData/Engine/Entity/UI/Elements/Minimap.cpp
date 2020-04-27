#include "Minimap.h"

Minimap::Minimap(Entity* centerEntity, Level* level) : m_view()
{
    addComponent<Position>(sf::Vector2f(650, -525));
    addComponent<Sprite>("UI/ui.png");
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(6, 6);

    m_view.setViewport(sf::FloatRect(0, 0, 0.5, 0.5));
    m_view.setCenter(centerEntity->getComponent<Position>().getPosition());
    
    m_center = centerEntity;
    m_level  = level;
}

void Minimap::initialize()
{
    Entity::initialize();
}

void Minimap::render(sf::RenderWindow* window)
{
    Entity::render(window);
    auto oldView = window->getView();
    window->setView(m_view);

    //draw minimap here
    //draw tiles
    //then draw current levels entities

    window->setView(oldView);

}
