#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"

class Player : public Entity {

public:
    Player(sf::Vector2f position);
    sf::FloatRect bounds() override;
    sf::Vector2f currentPosition();

    bool isMoving();
    void stopMovement();

    sf::FloatRect* collider();

};


#endif //ENFUSION_PLAYER_H
