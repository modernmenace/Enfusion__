#ifndef ENFUSION_GAMEOBJECT_H
#define ENFUSION_GAMEOBJECT_H

#include "../Core/Engine.h"
#include "../Component/Component.h"

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
        T* c(new T());
        std::unique_ptr<Component> uPtr {c};
        components.push_back(std::move(uPtr));
        c->entity = this;
        c->initialize();
        return *c;
    }

    /* W/ Args */
    template <typename T, typename... tArgs>
    T& addComponent(tArgs&&... arguments)
    {
        T* c(new T(std::forward<tArgs>(arguments)...));
        std::unique_ptr<Component> uPtr {c};
        components.push_back(std::move(uPtr));
        c->entity = this;
        c->initialize();
        return *c;
    }

private:
    std::vector<std::unique_ptr<Component>> components;

};


#endif //ENFUSION_GAMEOBJECT_H
