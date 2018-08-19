#ifndef ENFUSION_COMPONENT_H
#define ENFUSION_COMPONENT_H

#include "../Core/ComponentManager.h"
#include "../Core/Engine.h"

class Entity;

/*
 *  Component
 *
 *  DESC: Base class for all components
 *
 *  TODO: Add some asserts to check if component is registered
 *
 */

class Component {

public:
    Component();

    Entity      *entity;
    std::string componentName;

    virtual void initialize()                     {}
    virtual void update()                         {}
    virtual void render(sf::RenderWindow* window) {}

    //TODO: Deal with destructors
    virtual ~Component()      {}

};


#endif //ENFUSION_COMPONENT_H
