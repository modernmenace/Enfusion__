#include "ScrollArea.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Engine/Component/Base/Sprite.h"

//TODO: Scroll bar size based on element count

ScrollArea::ScrollArea(sf::Vector2f position, sf::Vector2f area)
{
    s_area = area;
    addComponent<Position>(position);

    s_scrollBar.addComponent<Position>(sf::Vector2f(position.x + area.x - 40, position.y));
    s_scrollBar.addComponent<Sprite>("UI/ui.png");
}

ScrollArea::~ScrollArea() noexcept
{
    for(auto* e : s_elements)
        delete e;
}

void ScrollArea::initialize()
{
    Entity::initialize();
    s_backRect.setPosition(getComponent<Position>().getPosition());
    s_backRect.setSize(s_area);
    s_backRect.setFillColor(sf::Color(85, 67, 21, 75));
    s_scrollRect.setPosition(s_scrollBar.getComponent<Position>().getPosition());
    s_scrollRect.setSize(sf::Vector2f(40, s_area.y));
    s_scrollRect.setFillColor(sf::Color(55, 42, 11, 75));
    s_scrollBar.initialize();
    s_scrollBar.getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(93, 68, 4, 6));
    s_scrollBar.getComponent<Sprite>().getSprite().setScale(10, 10);
    updateScrollbar();
}

void ScrollArea::updateScrollbar()
{
    //TODO: Implement this, update scrollbar size if needed
    s_scrollbarNeeded = false;
}

void ScrollArea::render(sf::RenderWindow* window)
{
    Entity::render(window);
    window->draw(s_backRect);

    if (s_scrollbarNeeded)
    {
        window->draw(s_scrollRect);
        s_scrollBar.render(window);
    }

    for(auto* e : s_elements)
        e->render(window);
}

void ScrollArea::addElement(Entity* element, sf::Vector2f position)
{
    element->initialize(); //TODO: is this necessary?
    s_elements.push_back(element);
    s_elementPositions.push_back(position);
    updateScrollbar();
}