#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "Entity.h"
#include "../Component/Anim/AnimatedSprite.h"
#include "../Component/Base/Position.h"
#include "../Component/Motion/AnimatedMovement.h"
#include "../Component/Misc/Camera.h"
#include "../Component/Misc/Inventory.h"


class Player : public Entity {

public:
    Player(string_t spriteName, sf::Vector2f position);

};


#endif //ENFUSION_PLAYER_H
