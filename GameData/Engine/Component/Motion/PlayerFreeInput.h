#ifndef ENFUSION_PLAYERFREEINPUT_H
#define ENFUSION_PLAYERFREEINPUT_H

#include <memory>
#include "../Component.h"
#include "../Base/Sprite.h"

class PlayerFreeInput : public Component {

public:
    PlayerFreeInput(int speed = 5);

    void initialize() override;
    void handleInput(sf::Keyboard::Key) override;

private:
    int speed;

    //std::unique_ptr<sf::Sprite> sprite;
    sf::Sprite *sprite;
    enum MovementDirection { LEFT, RIGHT };
    MovementDirection currentDirection = MovementDirection::RIGHT;
};


#endif //ENFUSION_PLAYERFREEINPUT_H
