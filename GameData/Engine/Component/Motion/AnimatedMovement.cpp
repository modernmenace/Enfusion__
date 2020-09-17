#include "AnimatedMovement.h"
#include "../../Lvl/LevelManager.h"
#include "../Misc/Camera.h"

//TODO: implement movement collider
//todo: store collider pointer, switch based on direction

AnimatedMovement::AnimatedMovement(bool hasCollider, float speed)
{
    this->speed         = speed;
    this->m_hasCollider = hasCollider;
}

void AnimatedMovement::render(sf::RenderWindow *window)
{
    #if DEBUG_MOVEMENT_IGNORE_COLLISION != 1
    #if DEBUG_MOVEMENT_SHOW_COLLIDERS == 1
    if (m_hasCollider && moving)
    {
        window->draw(c_test_rect);
    }
    #endif
    #endif
}

void AnimatedMovement::initialize()
{
    assert(entity->hasComponent<AnimatedSprite>());
    this->characterSprite = &entity->getComponent<AnimatedSprite>().getSprite();
    entity->getComponent<AnimatedSprite>().switchState(0, 1);

    #if DEBUG_MOVEMENT_IGNORE_COLLISION != 1
    #if DEBUG_MOVEMENT_SHOW_COLLIDERS == 1
    if (m_hasCollider)
    {
        c_test_rect.setSize(sf::Vector2f(characterSprite->getGlobalBounds().width, characterSprite->getGlobalBounds().height));
        c_test_rect.setFillColor(sf::Color::Green);
    }
    #endif
    #endif
}

void AnimatedMovement::handleInput(sf::Keyboard::Key key)
{
    if (LevelManager::Instance()->getCurrentLevel().state() == GameState::PAUSE)
        return;

    moving = (sf::Keyboard::isKeyPressed(sf::Keyboard::W )|| sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}

void AnimatedMovement::update(sf::Time tickRate)
{
    if (LevelManager::Instance()->getCurrentLevel().state() == GameState::PAUSE)
        return;

    if (moving)
    {
        auto currTickRate = tickRate.asSeconds();
        auto tempSpeed = speed;
        #if DEBUG_MOVEMENT_FAST_SPRINT == 1
        if (sprinting) speed *= 15;
        #else
        if (sprinting) speed *= 3;
        #endif

        currAnimTime += currTickRate;

        sf::Keyboard::isKeyPressed(sf::Keyboard::W)      ? st.up    = true  : st.up    = false;
        sf::Keyboard::isKeyPressed(sf::Keyboard::S)      ? st.down  = true  : st.down  = false;
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)      ? st.left  = true  : st.left  = false;
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)      ? st.right = true  : st.right = false;
        sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? sprinting = true : sprinting = false;


        if (st.up)
        {
            if (st.down) { }
            else if (st.left)
                characterSprite->move(-speed_diag * currTickRate, -speed_diag * currTickRate);
            else if (st.right)
                characterSprite->move(speed_diag * currTickRate, -speed_diag * currTickRate);
            else
                characterSprite->move(0, -speed_vert * currTickRate);
        }
        else if (st.left)
        {
            if (st.right) { }
            else if (st.up)
                characterSprite->move(-speed_diag * currTickRate, -speed_diag * currTickRate);
            else if (st.down)
                characterSprite->move(-speed_diag * currTickRate, speed_diag * currTickRate);
            else
                characterSprite->move(-speed_horz * currTickRate, 0);

        }
        else if (st.down)
        {
            if(st.left)
                characterSprite->move(-speed_diag * currTickRate, speed_diag * currTickRate);
            else if (st.right)
                characterSprite->move(speed_diag * currTickRate, speed_diag * currTickRate);
            else
                characterSprite->move(0, speed_vert * currTickRate);
        }
        else if (st.right)
        {

            if (st.up)
                characterSprite->move(speed_diag * currTickRate, -speed_diag * currTickRate);
            else if (st.down)
                characterSprite->move(speed_diag * currTickRate, speed_diag * currTickRate);
            else
                characterSprite->move(speed_horz * currTickRate, 0);

        }
        else
        {
            moving = false;
        }
        checkAnimState();
        animate();
        speed = tempSpeed;
        entity->getComponent<Position>().setPosition(characterSprite->getPosition());

        //todo: mess with these collider size values
        //todo: diagonal movement colliders
        #if DEBUG_MOVEMENT_IGNORE_COLLISION != 1
        if (m_hasCollider)
        {
            switch (currentState)
            {
                case UP:
                    m_colliderRect.left = characterSprite->getPosition().x + (characterSprite->getLocalBounds().width / 2);
                    m_colliderRect.top  = characterSprite->getPosition().y + characterSprite->getGlobalBounds().height / 2;
                    m_colliderRect.width = characterSprite->getGlobalBounds().width * 0.7;
                    m_colliderRect.height = 10;
                    break;
                case LEFT:
                    m_colliderRect.left = characterSprite->getPosition().x;
                    m_colliderRect.top  = characterSprite->getPosition().y + (characterSprite->getGlobalBounds().height / 2);
                    m_colliderRect.width = 10;
                    m_colliderRect.height = characterSprite->getGlobalBounds().height * 0.4;
                    break;
                case RIGHT:
                    m_colliderRect.left = characterSprite->getPosition().x + characterSprite->getGlobalBounds().width * 0.8;
                    m_colliderRect.top  = characterSprite->getPosition().y + (characterSprite->getGlobalBounds().height / 2);
                    m_colliderRect.width = 10;
                    m_colliderRect.height = characterSprite->getGlobalBounds().height * 0.4;
                    break;
                case DOWN:
                    m_colliderRect.left = characterSprite->getPosition().x + (characterSprite->getLocalBounds().width / 2);
                    m_colliderRect.top  = characterSprite->getPosition().y + characterSprite->getGlobalBounds().height;
                    m_colliderRect.width = characterSprite->getGlobalBounds().width * 0.7;
                    m_colliderRect.height = 10;
                    break;
            }
            #if DEBUG_MOVEMENT_SHOW_COLLIDERS == 1
            c_test_rect.setPosition(m_colliderRect.left, m_colliderRect.top);
            c_test_rect.setSize(sf::Vector2f(m_colliderRect.width, m_colliderRect.height));
            #endif
        }
        #endif
    }
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
    if (!moving)
    {
        currentFrame = 1;
        currAnimTime = 0.0f;
        switchAnimState(currentFrame);
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