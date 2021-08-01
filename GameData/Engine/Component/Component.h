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
 *
 */

class Component {

public:
    Component() {}

    Entity      *entity;
    ComponentID cId;

    virtual void initialize()                                    {}
    virtual void update(sf::Time tickRate)                       {}
    virtual void render(sf::RenderWindow* window, uint8_t z = 0) {}
    virtual void handleInput(sf::Keyboard::Key)                  {}
    virtual void handleInput(sf::Mouse::Button button)           {}

    virtual ~Component()      {}

};


#endif //ENFUSION_COMPONENT_H
