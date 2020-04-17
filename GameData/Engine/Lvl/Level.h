#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include <SFML/Graphics.hpp>

#include "../Core/Engine.h"
#include "../Entity/Entity.h"

enum GameState
{
    RUNNING,
    PAUSE
};

class Level {

public:
    Level(string_t levelName, string_t background);
    virtual ~Level();

    virtual void initialize();
    virtual void update(sf::Time tickRate);
    virtual void render(sf::RenderWindow* window);
    virtual void handleInput(sf::Keyboard::Key key);
    virtual void handleInput(sf::Mouse::Button button);

    inline void setState(GameState g) { l_state = g; }
    inline GameState state()          { return l_state; }

protected:
    sf::RectangleShape background;
    string_t levelName;

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
    GameState l_state = GameState::RUNNING;

};

#endif //ENFUSION_LEVEL_H
