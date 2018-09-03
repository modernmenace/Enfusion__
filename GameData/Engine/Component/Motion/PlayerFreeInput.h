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

    sf::Sprite *sprite;
    enum MovementDirection { LEFT, RIGHT };
    MovementDirection currentDirection = MovementDirection::RIGHT;

    void flipSprite()
    {
        sprite->scale(-1.f,1.f);
        if (currentDirection == MovementDirection::RIGHT)
        {
            sprite->setPosition(sprite->getPosition().x + (sprite->getTexture()->getSize().x),
                                sprite->getPosition().y);
            currentDirection = MovementDirection::LEFT;
        }
        else
        {
            sprite->setPosition(sprite->getPosition().x - (sprite->getTexture()->getSize().x),
                                sprite->getPosition().y);
            currentDirection = MovementDirection::RIGHT;
        }
    }
};


#endif //ENFUSION_PLAYERFREEINPUT_H
