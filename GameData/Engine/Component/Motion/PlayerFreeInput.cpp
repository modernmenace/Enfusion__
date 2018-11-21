#include "PlayerFreeInput.h"

/*
 *  Player Free Input Component
 *
 *  DESC: Allows for input-based free movement (WSAD/Numpad)
 *
 *  TODO: SPRITE IS CURRENTLY A UNSAFE POINTER, NOT WORKING OTHERWISE
 *
 */

PlayerFreeInput::PlayerFreeInput(int speed)
{
    this->speed = speed;
}

void PlayerFreeInput::initialize()
{
    assert(entity->hasComponent<Sprite>());
    this->sprite = &entity->getComponent<Sprite>().getSprite();
}

void PlayerFreeInput::update(sf::Time tickRate)
{
    //todo: update movement here rather than handleInput
    currDT = tickRate.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) st.up    = true; else st.up    = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) st.down  = true; else st.down  = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) st.left  = true; else st.left  = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) st.right = true; else st.right = false;

    if (st.up)
    {
        if (st.left)
            sprite->move(-speed * currDT, -speed * currDT);
        else if (st.right)
            sprite->move(speed * currDT, -speed * currDT);
        else
            sprite->move(0, -speed * currDT);
    }
    else if (st.left)
    {
        if (currentDirection == MovementDirection::RIGHT)
            flipSprite();

        if (st.up)
            sprite->move(-speed * currDT, -speed * currDT);
        else if (st.down)
            sprite->move(-speed * currDT, speed * currDT);
        else
            sprite->move(-speed * currDT, 0);

        currentDirection = MovementDirection::LEFT;
    }
    else if (st.down)
    {
        if(st.left)
            sprite->move(-speed * currDT, speed * currDT);
        else if (st.right)
            sprite->move(speed * currDT, speed * currDT);
        else
            sprite->move(0, speed * currDT);
    }
    else if (st.right)
    {
        if (currentDirection == MovementDirection::LEFT)
            flipSprite();

        if (st.up)
            sprite->move(speed * currDT, -speed * currDT);
        else if (st.down)
            sprite->move(speed * currDT, speed * currDT);
        else
            sprite->move(speed * currDT, 0);

        currentDirection = MovementDirection::RIGHT;
    }

}

void PlayerFreeInput::flipSprite()
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