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

    uint16_t zOrderBoundary() override
    {
        //TODO: use override correctly
        dbg_log("override used")
        auto gBounds = o_sprite.getGlobalBounds();
        return gBounds.top + (gBounds.height / 8);
    }


};


#endif //ENFUSION___CACTUS_H
