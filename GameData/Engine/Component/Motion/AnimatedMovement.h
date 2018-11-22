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

enum AnimState
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class AnimatedMovement : public Component {

public:
    AnimatedMovement(int speed = 250);

    void initialize()              override;
    void update(sf::Time tickRate) override;

private:
    int speed;

    sf::Sprite* characterSprite;

    AnimState currentState = AnimState::DOWN;
    MovementStatus st;

    void checkAnimState();
    void switchAnimState(int frame = 1);
    void animate();
    int getRow();

    // animation related
    int currentFrame     = 1;
    float currAnimTime   = 0.0f;
    float animThreshhold = 0.175f;

    bool sprinting = false;

    inline bool isMoving() const
    {
        return (st.up || st.down || st.left || st.right);
    }

};


#endif //ENFUSION_ANIMATEDMOVEMENT_H
