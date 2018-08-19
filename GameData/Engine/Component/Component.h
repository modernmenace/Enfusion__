#ifndef ENFUSION_COMPONENT_H
#define ENFUSION_COMPONENT_H

#include "../Core/Engine.h"

using ComponentID = std::size_t;

class Entity;

class Component {

public:
    Entity *entity;

    virtual void initialize()                     {}
    virtual void update()                         {}
    virtual void render(sf::RenderWindow* window) {}

    //TODO: Deal with destructors
    virtual ~Component()      {}

private:



};


#endif //ENFUSION_COMPONENT_H
