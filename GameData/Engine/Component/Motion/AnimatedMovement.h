#ifndef ENFUSION_ANIMATEDMOVEMENT_H
#define ENFUSION_ANIMATEDMOVEMENT_H

#include "../Component.h"
#include "../Anim/AnimatedSprite.h"

struct MovementStatus
{
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
};

class AnimatedMovement : public Component {

public:
    AnimatedMovement(int speed = 250);

    void initialize()              override;
    void update(sf::Time tickRate) override;

private:
    int speed;

    sf::Sprite* characterSprite;

    enum MovementDirection { LEFT, RIGHT };

    MovementDirection currentDirection = MovementDirection::RIGHT;
    MovementStatus st;

    void flipSprite();
    void switchAnimState();
    int getRow();

};


#endif //ENFUSION_ANIMATEDMOVEMENT_H
