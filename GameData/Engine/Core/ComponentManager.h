#ifndef ENFUSION_COMPONENTMANAGER_H
#define ENFUSION_COMPONENTMANAGER_H

#include <string>
#include <map>

/* Macros to hide gross reused code */
#define REGISTER_COMPONENT    if (!registered) { auto cID = generateComponentID(); registered = true; ComponentMap.emplace(componentName, cID); };
#define INITIALIZE_COMPONENT  static bool registered = false;

using ComponentID = std::size_t;

/* map very inefficient please replace this */
static std::map<std::string, ComponentID> ComponentMap;

// TODO: Kind of working, test this with multiple components

inline ComponentID generateComponentID()
{
    static ComponentID currentComponentID = 0;
    return currentComponentID++;
}


#endif //ENFUSION_COMPONENTMANAGER_H
