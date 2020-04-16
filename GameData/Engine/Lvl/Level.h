#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include <SFML/Graphics.hpp>

#include "../Core/Engine.h"
#include "../Entity/Entity.h"

extern bool LEVEL_PAUSED;

class Level {

public:
    Level(std::string levelName, std::string background);
    virtual ~Level();

    virtual void initialize();
    virtual void update(sf::Time tickRate);
    virtual void render(sf::RenderWindow* window);
    virtual void handleInput(sf::Keyboard::Key key);
    virtual void handleInput(sf::Mouse::Button button);

    static std::string getLevelName();

protected:
    sf::RectangleShape background;
    std::string levelName;

    std::vector<Entity*> entities;
    std::vector<Entity*> uiEntities;

    template <typename Entity>
    inline void addEntity(Entity* e)
    {
        entities.emplace_back(e);
    }

    template <typename Entity>
    inline void addUIEntity(Entity* e)
    {
        uiEntities.emplace_back(e);
    }

    sf::View defaultView;

};

#endif //ENFUSION_LEVEL_H
