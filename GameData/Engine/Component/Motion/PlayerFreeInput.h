#ifndef ENFUSION_PLAYERFREEINPUT_H
#define ENFUSION_PLAYERFREEINPUT_H

#include <memory>
#include "../Component.h"
#include "../Base/Sprite.h"

struct MovementStatus
{
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
};

class PlayerFreeInput : public Component {

public:
    PlayerFreeInput(int speed = 5);

    void initialize() override;
    void update(sf::Time tickRate) override;

private:
    int   speed;
    float currDT;

    MovementStatus st;

    sf::Sprite *sprite;
    enum MovementDirection { LEFT, RIGHT };
    MovementDirection currentDirection = MovementDirection::RIGHT;

    void flipSprite();
};


#endif //ENFUSION_PLAYERFREEINPUT_H
