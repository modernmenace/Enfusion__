#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "Entity.h"
#include "../Component/Anim/Animator.h"
#include "../Component/Base/Sprite.h"
#include "../Component/Motion/PlayerFreeInput.h"

#define MovementDirection Animator::MovementDirection

enum State
{
    IDLE,
    WALK
};

class Player : public Entity {

public:
    Player(std::string spriteName, sf::Vector2f position);

    void update();
    void handleInput(sf::Keyboard::Key key);

private:
    int speed = 15;

    void switchState(State nextState);

    State             currentState;
    Animator          animator;

    MovementDirection currentDirection = MovementDirection::RIGHT;

    const std::map<State, Animator::Animations> animStateMap
    {
        { State :: IDLE, Animator::Animations :: IDLE },
        { State :: WALK, Animator::Animations :: WALK }
    };

};


#endif //ENFUSION_PLAYER_H
