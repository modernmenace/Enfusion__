#include "Animator.h"

/*
 *  Animator
 *
 *  DESC: The animator class is attached to the player/AI which require animation
 *
 *  NOTE: Only the PLAYER animator is currently implemented (in progress)
 *
 *  USAGE: < fill later >
 *
 */

 Animator::Animator(Animator::AnimatorType type, sf::IntRect spriteSize)
{
     this->type          = type;
     this->spriteSize    = spriteSize;
     this->currentSprite = spriteSize;
}

/*
 *  Setup Animator
 *
 *  DESC: This function is called to setup the animation array for the animator
 *
 *        Provided animations are checked by the required animation map, to ensure
 *        we have all necessary animations
 *
 */

bool Animator::setupAnimator(std::map<Animator::Animations, sf::Texture> animationMap) {

    auto validMap = true;

    if (requiredAnimations.count(type) != 0)
    {
        for (auto it = requiredAnimations.begin(); it != requiredAnimations.end(); it++)
            if (it->first == type)
                if(animationMap.count(static_cast<Animations>(it->second)) == 0)
                {
                    validMap = false;
                    dbg_err("Animator: Missing animation '" << it->second << "' required by current animator type.")
                    break;
                }
    }

    if (validMap)
    {
        this->anims = animationMap;
        animatorSetUp = true;
        animationclock.restart();
    }
    else
    {
        dbg_err("Animator: Invalid Animation Map Received")
    }

    return animatorSetUp;
}

/*
 *  Update
 *
 *  DESC: < fill this in >
 *
 */

void Animator::update(sf::Sprite* sprite)
{
    if (animationclock.getElapsedTime().asSeconds() > 0.5f)
    {
        dbg_log("updating animation")

        //works check to see if we exceed sprite sheet width somehow
        currentSprite.left += spriteSize.width;
        sprite->setTextureRect(currentSprite);

        animationclock.restart();
    }
}

/*
 *  Get Animation
 *
 *  DESC: This function is used to return an animation texture for
 *        the specified animation (Performs assertion to check animator is set up)
 *
 */

sf::Texture& Animator::getAnimation(Animations animation)
{
    assert(animatorSetUp);

    try
    {
        return anims.at(animation);
    }
    catch (std::out_of_range&)
    {
        dbg_err("Animator: Error loading animation '" << animation << "' for animator type '" << type << "'")
        return AssetManager::getTexture(MISSING_TEXTURE);
    }
}

/*
 *  Get Movement Animation
 *
 *  DESC: Called when a player/AI is moving
 *
 *  NOTE: Make this modular to support left/right/up/down animations
 *        but only if they are available (future)
 *
 */

sf::Texture& Animator::getMovementAnimation(Animator::MovementDirection direction)
{
    return AssetManager::getTexture(MISSING_TEXTURE);
}

/*
 *  Set Sprite Animatios
 *
 *  DESC: Called to update a sprite with the texture for the given animation
 *
 */

void Animator::setSpriteAnimation(sf::Sprite* sprite, Animator::Animations anim)
{
    assert(animatorSetUp);

    sprite->setTexture(getAnimation(anim), true);
    sprite->setTextureRect(currentSprite);
}