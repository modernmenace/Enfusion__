#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include <SFML/Graphics.hpp>
#include "../Core/Engine.h"
#include "../Entity/Entity.h"

class Level {

public:
    Level(std::string levelName, std::string background);

    virtual void initialize();
    virtual void update(sf::Time tickRate);
    virtual void render(sf::RenderWindow* window);
    virtual void handleInput(sf::Keyboard::Key key); //called on key press

    static std::string getLevelName();

protected:
    sf::RectangleShape background;
    std::string levelName;

    std::vector<Entity*> entities;

    template <typename Entity>
    inline void addEntity(Entity* e)
    {
        entities.emplace_back(e);
    }

};

#endif //ENFUSION_LEVEL_H
