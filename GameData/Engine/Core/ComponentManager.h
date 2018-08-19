#ifndef ENFUSION_COMPONENTMANAGER_H
#define ENFUSION_COMPONENTMANAGER_H

#include "Engine.h"

/* Macros to hide gross reused code */
#define REGISTER_COMPONENT  if (!registered) generateComponentID();
#define INTREG              static bool registered = false;

using ComponentID = std::size_t;

// TODO: Need a way of reliably generating one ID per type of component
// TODO: trying to use macros to hide nasty code right now

inline ComponentID generateComponentID()
{
    static ComponentID currentComponentID = 0;
    return currentComponentID++;
}


#endif //ENFUSION_COMPONENTMANAGER_H
