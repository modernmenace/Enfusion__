#ifndef ENFUSION_COMPONENTMANAGER_H
#define ENFUSION_COMPONENTMANAGER_H

#include <string>
#include <map>
#include <iostream>

/* Macros to hide gross reused code */
#define REGISTER_COMPONENT(componentName)  checkComponentRegistered(componentName);

using ComponentID = std::size_t;

/* map very inefficient please replace this */
static std::map<std::string, ComponentID> ComponentMap;

// TODO: Kind of working, test this with multiple components

inline ComponentID generateComponentID()
{
    static ComponentID currentComponentID = 0;
    return currentComponentID++;
}

inline void printMap()
{
    std::cout << "Length: " << ComponentMap.size() << std::endl;
    for(const auto &i : ComponentMap)
        std::cout << "Component Map: " << i.first << ", " << i.second << std::endl;
}

static void checkComponentRegistered(std::string componentName)
{
    // check if the component is in the map
    // this is probably very inefficient

    auto t = ComponentMap.find(componentName);
    if (t == ComponentMap.end())
    {
        //this working correcvylt, only adding once
        std::cout << "Component Missing: " << componentName << std::endl;
        auto cID = generateComponentID();
        ComponentMap.insert(std::make_pair(componentName, cID));
    }
    else
        std::cout << "Component Found: " << componentName << std::endl;

}


#endif //ENFUSION_COMPONENTMANAGER_H
