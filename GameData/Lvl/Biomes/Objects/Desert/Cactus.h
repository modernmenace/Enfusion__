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


};


#endif //ENFUSION___CACTUS_H
