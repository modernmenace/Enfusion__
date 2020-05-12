#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"

class Player : public Entity {

public:
    Player(string_t spriteName, sf::Vector2f position);
    sf::FloatRect bounds() override;

};


#endif //ENFUSION_PLAYER_H
