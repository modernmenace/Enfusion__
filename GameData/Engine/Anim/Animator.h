#ifndef ENFUSION_ANIMATOR_H
#define ENFUSION_ANIMATOR_H

#include <assert.h>
#include <map>
#include "../Core/Engine.h"

class Animator {

public:

    /*
     *  Animator Type
     *
     *  DESC: This enum holds the values for the different types of animators
     *        that are supported
     *
     */

    enum AnimatorType
    {
        PLAYER,
        AI,
        OBJECT
    };

    /*
     *  Animations
     *
     *  DESC: This enum holds the various animations that should be provided
     *
     *  NOTE: UNUSED_BOT and UNUSED_TOP are required for proper iteration
     *
     */

    enum Animations
    {
        UNUSED_BOT,

        IDLE,
        WALK,

        UNUSED_TOP
    };

    enum MovementDirection
    {
        LEFT,
        RIGHT
    };

    /*
     *  Required Animations
     *
     *  DESC: This map is used to store animations which are required for
     *        proper functionality
     *
     */

    Animator(AnimatorType type = AnimatorType::OBJECT, sf::IntRect spriteSize = sf::IntRect(0, 0, 64, 64));

    bool setupAnimator(std::map<Animations, sf::Texture> animationMap);
    sf::Texture& getAnimation(Animations animation);
    sf::Texture& getMovementAnimation(MovementDirection direction);

    void update(sf::Sprite* sprite);
    void setSpriteAnimation(sf::Sprite* sprite, Animations animations);

private:
    bool animatorSetUp = false;
    std::map<Animations, sf::Texture> anims;

    AnimatorType type;
    sf::IntRect  spriteSize;
    sf::IntRect  currentSprite;

    sf::Clock    animationclock;

    const std::map<AnimatorType, Animations> requiredAnimations
            {
                { AnimatorType :: PLAYER, Animations :: WALK }
            };

    bool animUp = true;
    int sprite_bottom;
    int sprite_top;

};


#endif //ENFUSION_ANIMATOR_H
