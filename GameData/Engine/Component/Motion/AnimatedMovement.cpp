#include "AnimatedMovement.h"
#include "../../Lvl/LevelManager.h"
#include "../../../Lvl/MapGenerator.h"

//TODO: documentation
//TODO: z-ordering

AnimatedMovement::AnimatedMovement(float speed)
{
    this->speed = speed;
}

void AnimatedMovement::initialize()
{
    assert(entity->hasComponent<AnimatedSprite>());
    this->characterSprite = entity->getComponent<AnimatedSprite>().getSprite();
    entity->getComponent<AnimatedSprite>().switchState(0, 1);
}

void AnimatedMovement::handleInput(sf::Keyboard::Key key)
{
    if (LevelManager::Instance()->getCurrentLevel().state() == GameState::PAUSE)
        return;

    moving = (sf::Keyboard::isKeyPressed(sf::Keyboard::W )|| sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}

//TODO: using magic numbers to check for collision
//TODO: similiar to lvlstructs.h
void AnimatedMovement::update(sf::Time tickRate)
{
    if (LevelManager::Instance()->getCurrentLevel().state() == GameState::PAUSE)
        return;

    if (moving)
    {
        sf::Vector2f lastPos = characterSprite->getPosition();
        Tile* lastTile       = &MapGenerator::Instance()->map()->m_tiles[resolvePositionToTile(lastPos)];
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

        //occTiles seems to be set correctly
        #if DEBUG_MOVEMENT_IGNORE_COLLISION == 0
        sf::Rect<uint32_t> occTiles = resolvePositionRectToTileRect(characterSprite->getGlobalBounds());

        //check if any tiles are blocked
        bool coll = false;
        std::vector<Tile>* m_tiles = &MapGenerator::Instance()->map()->m_tiles;
        for(int i = 0; i < occTiles.width; i++)
        {
            if (coll) break;
            for(int j = 0; j < occTiles.height; j++)
            {
                if (m_tiles->at(occTiles.top + i + (j * 250)).blocked)
                {
                    coll = true;
                    break;
                }
            }
        }
        if (coll)
        {
            characterSprite->setPosition(lastPos);
            return;
        }
        #endif
        checkAnimState();
        animate();
        speed = tempSpeed;
        entity->getComponent<Position>().setPosition(characterSprite->getPosition());
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