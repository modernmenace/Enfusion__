#ifndef ENFUSION___DEADTREE_H
#define ENFUSION___DEADTREE_H

#include "../StaticMapObject.h"

class DeadTree : public StaticMapObject
{

public:
    DeadTree() : StaticMapObject("Levels/desert.png", sf::IntRect(0, 304, 32, 48))
    {

    };


};

#endif //ENFUSION___DEADTREE_H
