#ifndef ENFUSION___CACTUS2_H
#define ENFUSION___CACTUS2_H

#include "../StaticMapObject.h"

class Cactus2 : public StaticMapObject
{

public:
    Cactus2() : StaticMapObject("Levels/desert.png", sf::IntRect(128, 192, 16, 32))
    {

    };

    StaticMapObject* createCopy() override
    {
        return new Cactus2(*this);
    };

    uint16_t zOrderBoundary() override
    {
        auto gBounds = o_sprite.getGlobalBounds();
        return gBounds.top - (gBounds.height / 1.5);
    }


};


#endif //ENFUSION___CACTUS2_H
