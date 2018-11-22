#ifndef ENFUSION_GAMEOBJECT_H
#define ENFUSION_GAMEOBJECT_H

#include <memory>
#include <bitset>
#include "../Core/Engine.h"
#include "../Core/ComponentManager.h"
#include "../Component/Component.h"


/*
 *  Entity
 *
 *  DESC: Base class for all entities, contains templates
 *        and functions shared by all entities
 *
 *
 */

class Component;

class Entity {

public:
    Entity();

    /*
     *  Virtual Functions
     */

    virtual void initialize() {}
    virtual void update(sf::Time tickRate);
    virtual void render(sf::RenderWindow *window);
    virtual void handleInput(sf::Keyboard::Key);

    virtual ~Entity();

    /*
     *  Add Component
     *
     *  DESC: Add a component of type T to the entity
     *        and initialize it
     *
     */

    /* W/O Args */
    template <typename T>
    T& addComponent()
    {
        T* comp(new T());
        std::unique_ptr<Component> ptr {comp};
        componentMap.insert(std::make_pair(getComponentID<T>(), std::move(ptr)));
        comp->entity = this;
        componentIDSet[getComponentID<T>()] = true;
        comp->initialize();
        return *comp;
    }

    /* W/ Args */
    template <typename T, typename... tArgs>
    T& addComponent(tArgs&&... arguments)
    {
        T* comp(new T(std::forward<tArgs>(arguments)...));
        std::unique_ptr<Component> ptr {comp};
        componentMap.insert(std::make_pair(getComponentID<T>(), std::move(ptr)));
        comp->entity = this;
        componentIDSet[getComponentID<T>()] = true;
        comp->initialize();
        return *comp;
    }

    /*
     *  Has Component
     *
     *  DESC: Returns whether this entity has the specified
     *        component (using bitset)
     *
     */
    template <typename T>
    inline bool hasComponent() const
    {
        return componentIDSet[getComponentID<T>()];
    }

    /*
     *  Get Component
     *
     *  DESC: Returns a pointer to the requested component
     *
     *  Note: This doesn't look like much, but it was a
     *        bitch to write
     *
     */

    template <typename T>
    inline T& getComponent() const
    {
        return *static_cast<T*>(componentMap.at(getComponentID<T>()).get());
    }


private:
    std::map<ComponentID, std::unique_ptr<Component>> componentMap;
    std::bitset<MAX_COMPONENTS>                       componentIDSet;


};


#endif //ENFUSION_GAMEOBJECT_H
