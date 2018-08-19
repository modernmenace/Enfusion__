#ifndef ENFUSION_COMPONENTMANAGER_H
#define ENFUSION_COMPONENTMANAGER_H


#include "Engine.h"

using ComponentID = std::size_t;

// TODO: Need a way of reliably generating one ID per type of component

inline ComponentID generateComponentID()
{
    static ComponentID currentComponentID = 0;
    return currentComponentID++;
}

#endif //ENFUSION_COMPONENTMANAGER_H
