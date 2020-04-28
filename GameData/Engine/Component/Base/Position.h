#ifndef ENFUSION_POSITION_H
#define ENFUSION_POSITION_H

#include "../Component.h"

class Position : public Component {

public:
    Position(sf::Vector2f position);
    void setPosition(sf::Vector2f pos);

    inline sf::Vector2f getPosition() { return this->position; }

private:
    sf::Vector2f position;

};


#endif //ENFUSION_POSITION_H
