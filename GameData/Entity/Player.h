#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"
#include "../Lvl/LvlStructs.h"

class Player : public Entity {

public:
    Player(sf::Vector2f position);
    void handleInput(sf::Keyboard::Key)        override;
    void handleInput(sf::Mouse::Button button) override;
    sf::FloatRect bounds() override;
};


#endif //ENFUSION_PLAYER_H
