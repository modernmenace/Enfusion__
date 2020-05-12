#ifndef ENFUSION___SCROLLAREA_H
#define ENFUSION___SCROLLAREA_H

#include "../../../Engine/Entity/Entity.h"

class ScrollArea : public Entity {

public:
    ScrollArea(sf::Vector2f, sf::Vector2f);
    ~ScrollArea();
    void initialize()              override;
    void render(sf::RenderWindow*) override;

    void addElement(Entity*, sf::Vector2f);

private:
    sf::Vector2f       s_area;
    sf::RectangleShape s_backRect;
    sf::RectangleShape s_scrollRect;
    Entity             s_scrollBar;

    std::vector<Entity*>      s_elements;
    std::vector<sf::Vector2f> s_elementPositions;

    void updateScrollbar();
    bool s_scrollbarNeeded = false;
};


#endif //ENFUSION___SCROLLAREA_H
