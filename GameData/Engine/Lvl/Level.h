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

    inline void addEntity(Entity* e)
    {
        entities.insert(entities.begin(), e);
    }

    inline void addUIEntity(Entity* e)
    {
        uiEntities.emplace_back(e);
    }

    inline Entity* player() { return l_player; }

protected:
    sf::RectangleShape background;
    string_t levelName;

    std::vector<Entity*> entities;
    std::vector<Entity*> uiEntities;

    sf::View defaultView;
    GameState l_state  = GameState::RUNNING;
    Entity*   l_player = nullptr;

};

#endif //ENFUSION_LEVEL_H
