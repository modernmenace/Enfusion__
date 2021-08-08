#ifndef ENFUSION___CACTUS_H
#define ENFUSION___CACTUS_H

#include "../StaticMapObject.h"

class Cactus : public StaticMapObject
{

public:
    Cactus() : StaticMapObject("Levels/desert.png", sf::IntRect(112, 192, 16, 32))
    {
        //todo: block tiles
        //todo: pass map?
    };

    StaticMapObject* createCopy() override
    {
        return new Cactus(*this);
    };

    uint16_t zOrderBoundary() override
    {
        auto gBounds = o_sprite.getGlobalBounds();
        return gBounds.top - (gBounds.height / 1.5);
    }


};


#endif //ENFUSION___CACTUS_H
