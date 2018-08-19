#ifndef ENFUSION_GAMEOBJECT_H
#define ENFUSION_GAMEOBJECT_H

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
        return *comp;
    }

    /*
     *  Has Component
     *
     *  DESC: TODO: Implement This
     *
     */
    template <typename T>
    inline bool hasComponent() const
    {

    }

    /*
     *  Get Component
     *
     *  DESC: TODO: Implement This
     *
     */

    template <typename T>
    inline T& getComponent()
    {

    }


private:
    std::vector<std::unique_ptr<Component>> components;


};


#endif //ENFUSION_GAMEOBJECT_H
