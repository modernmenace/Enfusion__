#ifndef ENFUSION_COMPONENT_H
#define ENFUSION_COMPONENT_H

#include "../Core/Engine.h"

class Entity;

class Component {

public:
    Entity *entity;

    virtual void initialize() {}
    virtual void update()     {}
    virtual void render(sf::RenderWindow* window)     {}

    //TODO: Deal with destructors
    virtual ~Component()      {}


};


#endif //ENFUSION_COMPONENT_H
