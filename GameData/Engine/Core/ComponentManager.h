#ifndef ENFUSION_COMPONENTMANAGER_H
#define ENFUSION_COMPONENTMANAGER_H

#include <string>
#include <map>
#include <iostream>

using ComponentID = std::size_t;

static std::map<std::string, ComponentID> ComponentMap;


inline ComponentID generateComponentID()
{
    static ComponentID currentComponentID = 0;
    return currentComponentID++;
}

/* get component ID of type */
/* note: each instantiated template has own static vars */
template <typename T>
inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = generateComponentID();
    return typeID;
}

#endif //ENFUSION_COMPONENTMANAGER_H
