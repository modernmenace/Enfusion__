#include "AnimatedMovement.h"

//TODO: AnimState kind of phasing out status due to framing
//TODO: When removed: weird slowdowns with getRow()

AnimatedMovement::AnimatedMovement(float speed)
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
    auto tempSpeed = speed;
    if (sprinting) speed *= 2;
    auto currDT = tickRate.asSeconds();
    currAnimTime += currDT;

    sf::Keyboard::isKeyPressed(sf::Keyboard::W)      ? st.up    = true  : st.up    = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::S)      ? st.down  = true  : st.down  = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::A)      ? st.left  = true  : st.left  = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::D)      ? st.right = true  : st.right = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? sprinting = true : sprinting = false;

    if (st.up)
    {
        if (st.down) { }
        else if (st.left)
            characterSprite->move(-speed_diag * currDT, -speed_diag * currDT);
        else if (st.right)
            characterSprite->move(speed_diag * currDT, -speed_diag * currDT);
        else
            characterSprite->move(0, -speed_vert * currDT);
    }
    else if (st.left)
    {
        if (st.right) { }
        else if (st.up)
            characterSprite->move(-speed_diag * currDT, -speed_diag * currDT);
        else if (st.down)
            characterSprite->move(-speed_diag * currDT, speed_diag * currDT);
        else
            characterSprite->move(-speed_horz * currDT, 0);

    }
    else if (st.down)
    {
        if(st.left)
            characterSprite->move(-speed_diag * currDT, speed_diag * currDT);
        else if (st.right)
            characterSprite->move(speed_diag * currDT, speed_diag * currDT);
        else
            characterSprite->move(0, speed_vert * currDT);
    }
    else if (st.right)
    {

        if (st.up)
            characterSprite->move(speed_diag * currDT, -speed_diag * currDT);
        else if (st.down)
            characterSprite->move(speed_diag * currDT, speed_diag * currDT);
        else
            characterSprite->move(speed_horz * currDT, 0);

    }
    checkAnimState();
    animate();
    speed = tempSpeed;
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
        currAnimTime = 0.0f;
        switchAnimState();
        return;
    }

    if ((!sprinting && (currAnimTime >= animThreshhold)) || (sprinting && (currAnimTime >= animThreshhold / 2.0f)))
    {
        //animate
        if (currentFrame < 2)
            currentFrame++;
        else
            currentFrame = 0;

        switchAnimState(currentFrame);

        currAnimTime = 0.0f;
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