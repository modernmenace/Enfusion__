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
    animate();
}

void AnimatedMovement::switchAnimState()
{
    entity->getComponent<AnimatedSprite>().switchState(getRow(), 1);
}

int AnimatedMovement::getRow()
{
    //this needs work, only testing
    if (st.left)
        return 1;
    else if (st.right)
        return 2;
    else if (st.down)
        return 0;
    else if (st.up)
        return 3;
}

void AnimatedMovement::animate() {
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