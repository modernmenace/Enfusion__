#include "Animator.h"

Animator::Animator()
{

}

void Animator::setupAnimator(std::map<Animator::Animations, sf::Texture>)
{
    // setup animations
    // then check w/ assert to make sure all are set up

    animatorSetUp = true;
}

sf::Texture& Animator::getAnimation(Animations animation)
{
    assert(animatorSetUp);
    return anims.at(animation);
}
