#ifndef ENFUSION_ANIMATEDSPRITE_H
#define ENFUSION_ANIMATEDSPRITE_H

#include "../../Core/Engine.h"
#include "../Component.h"


class AnimatedSprite : public Component {

public:
    AnimatedSprite(std::string spriteSheet = MISSING_TEXTURE);

};


#endif //ENFUSION_ANIMATEDSPRITE_H
