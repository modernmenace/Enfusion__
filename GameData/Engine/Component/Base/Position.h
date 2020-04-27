#ifndef ENFUSION_POSITION_H
#define ENFUSION_POSITION_H

#include "../Component.h"
#include "Sprite.h"

class Position : public Component {

public:
    Position(sf::Vector2f position)               { this->position = position; }

    inline sf::Vector2f getPosition()             { return this->position; }

    void setPosition(sf::Vector2f pos)
    {
        this->position = pos;
        if (entity->hasComponent<Sprite>())
            entity->getComponent<Sprite>().updatePosition(position);
    }

private:
    sf::Vector2f position;

};


#endif //ENFUSION_POSITION_H
