#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "GameObject.h"
#include "../Anim/Animator.h"

enum State
{
    IDLE,
    WALK
};

class Player : public GameObject {

public:
    Player(std::string spriteName, sf::Vector2f position);

    void update();
    void handleInput(sf::Keyboard::Key key);

private:
    int speed = 15;

    void switchState(State nextState);

    State    currentState;
    Animator animator;

    const std::map<State, Animator::Animations> animStateMap
    {
        { State::IDLE, Animator::Animations::IDLE },
        { State::WALK, Animator::Animations::WALK }
    };

};


#endif //ENFUSION_PLAYER_H
