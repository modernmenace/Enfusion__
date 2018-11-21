#ifndef ENFUSION_COMPONENTMANAGER_H
#define ENFUSION_COMPONENTMANAGER_H

#include <string>
#include <map>
#include <iostream>


using ComponentID = std::size_t;

/*
 *  Generate Component ID
 *
 *  DESC: Stores the last generated ComponentID and
 *        returns a new one
 *
 */

inline ComponentID generateComponentID()
{
    static ComponentID currentComponentID = 0;
    return currentComponentID++;
}

/*
 *  Get Component ID
 *
 *  DESC: Returns the ComponentID of the passed
 *        type
 *
 *  NOTE: Each instantiated template of type T
 *        has unique static variables
 *
 */

template <typename T>
inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = generateComponentID();
    return typeID;
}

#endif //ENFUSION_COMPONENTMANAGER_H
