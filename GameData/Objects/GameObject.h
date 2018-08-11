#ifndef ENFUSION_GAMEOBJECT_H
#define ENFUSION_GAMEOBJECT_H

#include "../Core/Engine.h"

class GameObject {

public:
    GameObject(std::string spriteName, sf::Vector2f position);

    void render(sf::RenderWindow *window);

protected:
    sf::Sprite   sprite;
    sf::Vector2f position;

};


#endif //ENFUSION_GAMEOBJECT_H
