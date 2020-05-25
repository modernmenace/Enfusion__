#ifndef ENFUSION___CACTUS_H
#define ENFUSION___CACTUS_H

#include "../StaticMapObject.h"

class Cactus : public StaticMapObject
{

public:
    Cactus(sf::Vector2f position) : StaticMapObject("Levels/desert.png", sf::IntRect(112, 192, 16, 32), position){};


private:


};


#endif //ENFUSION___CACTUS_H
