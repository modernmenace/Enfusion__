#ifndef ENFUSION_GAMEOBJECT_H
#define ENFUSION_GAMEOBJECT_H

#include "../Core/Engine.h"
#include "../Component/Component.h"

class Component;

class Entity {

public:
    Entity(std::string spriteName, sf::Vector2f position);

    virtual void initialize();
    virtual void update();
    virtual void render(sf::RenderWindow *window);

    //TODO: Fix up this argument version
    /*
    template <typename T, typename... tArgs>
    void addComponent(tArgs&&... arguments)
    {
        T* c(new T(std::forward<tArgs>(arguments)...));
        std::unique_ptr<Component> uPtr {c};
        components.push_back(std::move(uPtr));
        c->initialize();
    } */

    template <typename T>
    void addComponent()
    {
        T* c(new T());
        std::unique_ptr<Component> uPtr {c};
        components.push_back(std::move(uPtr));
        c->initialize();
    }


protected:
    sf::Sprite   sprite;
    sf::Vector2f position;

private:
    std::vector<std::unique_ptr<Component>> components;

};


#endif //ENFUSION_GAMEOBJECT_H
