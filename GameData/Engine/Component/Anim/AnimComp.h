#ifndef ENFUSION_ANIMCOMP_H
#define ENFUSION_ANIMCOMP_H

#include "../Component.h"

class AnimComp : public Component
{

public:
    void initialize() override;
    void update()     override;

private:
    sf::Sprite* sprite;

};


#endif //ENFUSION_ANIMCOMP_H
