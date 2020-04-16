#ifndef ENFUSION_POSITION_H
#define ENFUSION_POSITION_H

#include "../Component.h"

class Position : public Component {

public:
    Position(sf::Vector2f position)               { this->position = position; }

    inline sf::Vector2f getPosition()             { return this->position; }
    inline void setPosition(sf::Vector2f pos)     { this->position = pos;  }

private:
    sf::Vector2f position;

};


#endif //ENFUSION_POSITION_H
