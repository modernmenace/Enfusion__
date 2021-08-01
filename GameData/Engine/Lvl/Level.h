#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include <SFML/Graphics.hpp>

#include "../Core/Engine.h"
#include "../Entity/Entity.h"
#include "../../Entity/Player.h"

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
    virtual void renderUI(sf::RenderWindow* window);
    virtual void handleInput(sf::Keyboard::Key key);
    virtual void handleInput(sf::Mouse::Button button);

    inline void setState(GameState g) { l_state = g; }
    inline GameState state()          { return l_state; }

    inline void addEntity(Entity* e, uint8_t z = 0)
    {
        entities.insert(entities.begin(), RenderPair {z, e});
    }

    inline void addUIEntity(Entity* e)
    {
        uiEntities.emplace_back(e);
    }

    void removeEntity(Entity* e);

    inline Player* player() { return l_player; }

protected:
    sf::RectangleShape background;
    string_t levelName;

    struct RenderPair
    {
        uint8_t z;
        Entity* entity;
    };

    std::vector<RenderPair> entities;
    std::vector<Entity*> uiEntities;

    sf::View defaultView;
    GameState l_state  = GameState::RUNNING;
    Player*   l_player = nullptr;

};

#endif //ENFUSION_LEVEL_H
