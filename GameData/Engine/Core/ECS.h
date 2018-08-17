#ifndef ENFUSION_ECS_H
#define ENFUSION_ECS_H

#include "Engine.h"

class Component;
class Entity;

using ComponentID = std::size_t;

constexpr std::size_t maxComponents = 32;

// generate a new componentID for each component
inline ComponentID getComponentID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

// ensure all components have the same ID
/*
template <typename T>
inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = getComponentID();
    return typeID();
}
*/

#endif //ENFUSION_ECS_H
