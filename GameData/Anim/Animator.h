#ifndef ENFUSION_ANIMATOR_H
#define ENFUSION_ANIMATOR_H

#include <assert.h>
#include <map>
#include "../Core/Engine.h"

class Animator {

public:

    enum Animations
    {
        UNUSED_BOT,

        IDLE,
        WALK,

        UNUSED_TOP
    };

    bool setupAnimator(std::map<Animations, sf::Texture> animationMap);
    sf::Texture& getAnimation(Animations animation);

private:
    bool animatorSetUp = false;
    std::map<Animations, sf::Texture> anims;

};


#endif //ENFUSION_ANIMATOR_H
