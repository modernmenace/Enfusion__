#include "Animator.h"

/*
 *  Animator
 *
 *  DESC: The animator class is attached to the player/AI which require animation
 *
 *  NOTE: Plain gameobjects are currently not supported, as all enumed animations are currently required
 *
 *  USAGE: < fill later >
 *
 */

/*
 *  Setup Animator
 *
 *  DESC: This function is called to setup the animation array for the animator
 *
 *  NOTE: Possible improvements include an optimized check loop, or an option to not
 *        require every animation
 *
 */

bool Animator::setupAnimator(std::map<Animator::Animations, sf::Texture> animationMap) {

    auto validMap = true;
    for (int a = Animations::UNUSED_BOT + 1; a != Animations::UNUSED_TOP; a++) {
        if (animationMap.count(static_cast<Animations>(a)) == 0) {
            validMap = false;
            break;
        }
    }

    if (validMap)
    {
        this->anims = animationMap;
        animatorSetUp = true;
    }
    else
    {
        dbg_err("Animator: Invalid Animation Map Received")
    }

    return animatorSetUp;
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
    return anims.at(animation);
}
