#include "AnimatedMovement.h"

//TODO: AnimState kind of phasing out status due to framing

AnimatedMovement::AnimatedMovement(int speed)
{
    this->speed = speed;
}

void AnimatedMovement::initialize()
{
    assert(entity->hasComponent<AnimatedSprite>());
    this->characterSprite = &entity->getComponent<AnimatedSprite>().getSprite();
    entity->getComponent<AnimatedSprite>().switchState(0, 1);
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
        if (st.down) { }
        else if (st.left)
            characterSprite->move(-speed * currDT, -speed * currDT);
        else if (st.right)
            characterSprite->move(speed * currDT, -speed * currDT);
        else
            characterSprite->move(0, -speed * currDT);
    }
    else if (st.left)
    {
        if (st.up)
            characterSprite->move(-speed * currDT, -speed * currDT);
        else if (st.down)
            characterSprite->move(-speed * currDT, speed * currDT);
        else
            characterSprite->move(-speed * currDT, 0);

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

        if (st.up)
            characterSprite->move(speed * currDT, -speed * currDT);
        else if (st.down)
            characterSprite->move(speed * currDT, speed * currDT);
        else
            characterSprite->move(speed * currDT, 0);

    }
    checkAnimState();
    animate();
}

void AnimatedMovement::switchAnimState(int frame)
{
    entity->getComponent<AnimatedSprite>().switchState(getRow(), frame);
}

int AnimatedMovement::getRow()
{
    if (st.left)
        return 1;
    else if (st.right)
        return 2;
    else if (st.down)
        return 0;
    else if (st.up)
        return 3;

    switch (currentState)
    {
        case AnimState::UP:
            return 3;
        case AnimState::DOWN:
            return 0;
        case AnimState::LEFT:
            return 1;
        case AnimState::RIGHT:
            return 2;
    }
}

void AnimatedMovement::animate()
{
    auto moving = isMoving();
    if (!moving)
    {
        currentFrame = 1;
        switchAnimState();
        return;
    }
    

}

void AnimatedMovement::checkAnimState()
{
    // handle animation
    //update based on current state
    if (currentState == AnimState::DOWN)
    {
        if (st.left)
        {
            switchAnimState();
            currentState = AnimState::LEFT;
        }
        else if (st.right)
        {
            switchAnimState();
            currentState = AnimState::RIGHT;
        }
        else if (st.up)
        {
            switchAnimState();
            currentState = AnimState::UP;
        }
    }
    else if (currentState == AnimState::UP)
    {
        if (st.left)
        {
            switchAnimState();
            currentState = AnimState::LEFT;
        }
        else if (st.right)
        {
            switchAnimState();
            currentState = AnimState::RIGHT;
        }
        else if (st.down)
        {
            switchAnimState();
            currentState = AnimState::DOWN;
        }
    }
    else if (currentState == AnimState::LEFT)
    {
        if (st.right)
        {
            switchAnimState();
            currentState = AnimState::RIGHT;
        }
        if (!st.left)
        {
            if (st.up)
            {
                switchAnimState();
                currentState = AnimState::UP;
            }
            else if (st.down)
            {
                switchAnimState();
                currentState = AnimState::DOWN;
            }
        }
    }
    else if (currentState == AnimState::RIGHT)
    {
        if (st.left)
        {
            switchAnimState();
            currentState = AnimState::LEFT;
        }
        if (!st.right)
        {
            if (st.up)
            {
                switchAnimState();
                currentState = AnimState::UP;
            }
            else if (st.down)
            {
                switchAnimState();
                currentState = AnimState::DOWN;
            }
        }
    }
}