#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "Entity.h"
#include "../Component/Base/Position.h"
#include "../Component/Base/Sprite.h"
#include "../Component/Motion/PlayerFreeInput.h"


enum State
{
    IDLE,
    WALK
};

class Player : public Entity {

public:
    Player(std::string spriteName, sf::Vector2f position);

    void update();

private:
    int speed = 15;

    void switchState(State nextState);

    State             currentState;

};


#endif //ENFUSION_PLAYER_H
