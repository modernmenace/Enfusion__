#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "Entity.h"
#include "../Component/Base/Position.h"
#include "../Component/Base/Sprite.h"
#include "../Component/Motion/PlayerFreeInput.h"
#include "../Component/Anim/AnimComp.h"


class Player : public Entity {

public:
    Player(std::string spriteName, sf::Vector2f position);

};


#endif //ENFUSION_PLAYER_H
