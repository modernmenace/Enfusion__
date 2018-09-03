#ifndef ENFUSION_POSITION_H
#define ENFUSION_POSITION_H

#include "../Component.h"

using sf::Vector2f;

class Position : public Component {

public:
    Position(Vector2f position);

    Vector2f getPosition();
    Vector2f getPosition(sf::Sprite* sprite);


private:
    Vector2f position;

};


#endif //ENFUSION_POSITION_H
