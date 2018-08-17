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

    template <typename T, typename tArgs>
    void addComponent(tArgs arguments)
    {
        //std::forward -> tArgs -> T
    }


protected:
    sf::Sprite   sprite;
    sf::Vector2f position;

private:
    std::vector<std::unique_ptr<Component>> components;

};


#endif //ENFUSION_GAMEOBJECT_H
