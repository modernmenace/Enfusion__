#include "AnimatedMovement.h"

AnimatedMovement::AnimatedMovement(int speed)
{
    this->speed = speed;
}

void AnimatedMovement::initialize()
{
    assert(entity->hasComponent<AnimatedSprite>());
    this->characterSprite = &entity->getComponent<AnimatedSprite>().getSprite();
}

void AnimatedMovement::update(sf::Time tickRate)
{
    auto currDT = tickRate.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) st.up    = true; else st.up    = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) st.down  = true; else st.down  = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) st.left  = true; else st.left  = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) st.right = true; else st.right = false;

    if (st.up)
    {
        if (st.left)
            characterSprite->move(-speed * currDT, -speed * currDT);
        else if (st.right)
            characterSprite->move(speed * currDT, -speed * currDT);
        else
            characterSprite->move(0, -speed * currDT);
    }
    else if (st.left)
    {
        if (currentDirection == MovementDirection::RIGHT)
            flipSprite();

        if (st.up)
            characterSprite->move(-speed * currDT, -speed * currDT);
        else if (st.down)
            characterSprite->move(-speed * currDT, speed * currDT);
        else
            characterSprite->move(-speed * currDT, 0);

        currentDirection = MovementDirection::LEFT;
    }
    else if (st.down)
    {
        if(st.left)
            characterSprite->move(-speed * currDT, speed * currDT);
        else if (st.right)
            characterSprite->move(speed * currDT, speed * currDT);
        else
            characterSprite->move(0, speed * currDT);
    }
    else if (st.right)
    {
        if (currentDirection == MovementDirection::LEFT)
            flipSprite();

        if (st.up)
            characterSprite->move(speed * currDT, -speed * currDT);
        else if (st.down)
            characterSprite->move(speed * currDT, speed * currDT);
        else
            characterSprite->move(speed * currDT, 0);

        currentDirection = MovementDirection::RIGHT;
    }
    //switchAnimState();
}

void AnimatedMovement::switchAnimState()
{
    entity->getComponent<AnimatedSprite>().switchState(getRow(), 1);
}

int AnimatedMovement::getRow()
{
    //this needs work, only testing
    if (st.down)
        return 0;
    else if (st.left)
        return 1;
    else if (st.right)
        return 2;
    else if (st.down)
        return 3;
}

void AnimatedMovement::flipSprite()
{
    //TODO: Redo this function
    /*
    characterSprite->scale(-1.f,1.f);
    if (currentDirection == MovementDirection::RIGHT)
    {
        characterSprite->setPosition(characterSprite->getPosition().x + (characterSprite->getTexture()->getSize().x),
                                     characterSprite->getPosition().y);
        currentDirection = MovementDirection::LEFT;
    }
    else
    {
        characterSprite->setPosition(characterSprite->getPosition().x - (characterSprite->getTexture()->getSize().x),
                                     characterSprite->getPosition().y);
        currentDirection = MovementDirection::RIGHT;
    }
     */
}