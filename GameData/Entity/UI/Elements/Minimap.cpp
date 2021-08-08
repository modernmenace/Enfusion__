#include <cmath>
#include "Minimap.h"

//todo: implement minimap boundaries

Minimap::Minimap(Entity* centerEntity, Level* level) : m_view(), m_center_marker()
{
    addComponent<Position>(sf::Vector2f(650, -525));
    addComponent<Sprite>("UI/ui.png");
    getComponent<Sprite>().getSprite()->setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite()->setScale(6, 6);

    m_view.setViewport(sf::FloatRect(0.852, 0.033, 0.125, 0.22));
    m_view.setCenter(centerEntity->getComponent<Position>().getPosition());
    m_view.zoom(5);

    m_center  = centerEntity;
    m_level   = level;

    m_center_marker.addComponent<Position>(sf::Vector2f(0, 0));
    m_center_marker.addComponent<Sprite>("UI/ui.png");
}

void Minimap::initialize()
{
    Entity::initialize();
    m_center_marker.initialize();
    m_center_marker.getComponent<Sprite>().getSprite()->setTextureRect(sf::IntRect(94, 76, 4, 4));
    m_center_marker.getComponent<Sprite>().getSprite()->setScale(sf::Vector2f(50, 50));
}

void Minimap::update(sf::Time tickRate)
{
    Entity::update(tickRate);
    m_center_marker.getComponent<Position>().setPosition(m_center->getComponent<Position>().getPosition());

    //todo: implement edge boundaries


}

void Minimap::render(sf::RenderWindow* window)
{
    Entity::render(window);
    auto oldView = window->getView();
    window->setView(m_view);

    if (m_tilemap)
    {
        m_view.setCenter(floor(m_center->getComponent<Position>().getPosition().x),
                         floor(m_center->getComponent<Position>().getPosition().y));
        window->draw(*m_tilemap);
    }
    m_center_marker.render(window);
    window->setView(oldView);

}
