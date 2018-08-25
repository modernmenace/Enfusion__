#ifndef ENFUSION_GAMEOBJECT_H
#define ENFUSION_GAMEOBJECT_H

#include <memory>
#include "../Core/Engine.h"
#include "../Core/ComponentManager.h"
#include "../Component/Component.h"


/*
 *  Entity
 *
 *  DESC: Base class for all entities, contains templates
 *        and functions shared by all entities
 *
 *        TODO: Find way to store and check/get components
 *        TODO: Component IDs now being stored correctly!!!!
 *
 */

class Component;

class Entity {

public:
    Entity(sf::Vector2f position);

    sf::Vector2f position;

    /*
     *  Virtual Functions
     */

    virtual void initialize() {}
    virtual void update();
    virtual void render(sf::RenderWindow *window);

    // TODO: Deal with destructors
    virtual ~Entity() { }

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
        components.emplace_back(std::move(ptr));
        comp->entity = this;
        comp->initialize();
        componentIDSet[getComponentID<T>()] = true;
        return *comp;
    }

    /* W/ Args */
    template <typename T, typename... tArgs>
    T& addComponent(tArgs&&... arguments)
    {
        T* comp(new T(std::forward<tArgs>(arguments)...));
        std::unique_ptr<Component> ptr {comp};
        components.emplace_back(std::move(ptr));
        comp->entity = this;
        comp->initialize();
        componentIDSet[getComponentID<T>()] = true;
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
     *  DESC: TODO: Need to reimplement, use static cast to convert down inheritence tree
     *        TODO: Note: components inserted to array in order of component id (maybe?)
     *
     */

    template <typename T>
    T& getComponent() const
    {

        //auto &ptr(components[getComponentID<T>()]); // error is on this first line (EDIT: added &, now error is below)
        //return *static_cast<T*>(ptr);
    }


private:
    std::vector<std::unique_ptr<Component>> components;
    std::bitset<MAX_COMPONENTS>             componentIDSet;


};


#endif //ENFUSION_GAMEOBJECT_H
