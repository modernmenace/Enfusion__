#ifndef ENFUSION_COMPONENT_H
#define ENFUSION_COMPONENT_H

#include "../Core/ComponentManager.h"
#include "../Core/Engine.h"
#include "../Entity/Entity.h"

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
    ComponentID cId;

    virtual void initialize()                     {}
    virtual void update()                         {}
    virtual void render(sf::RenderWindow* window) {}
    virtual void handleInput(sf::Keyboard::Key)   {}

    //TODO: Deal with destructors
    virtual ~Component()      {}

};


#endif //ENFUSION_COMPONENT_H
