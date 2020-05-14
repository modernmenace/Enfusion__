#ifndef ENFUSION_GAME_H
#define ENFUSION_GAME_H

#include <SFML/Graphics.hpp>
#include "Engine/Core/Engine.h"
#include "Engine/Lvl/LevelManager.h"
#include "Data/Items.h"
#include "Data/Controls.h"

#define LEVEL LevelManager::Instance()->getCurrentLevel()

#ifdef __cplusplus
extern "C"
{
#endif
    void SE_init(const char*);
#ifdef __cplusplus
}
#endif

class Game {

public:
    Game(int argc, char *argv[]);
    void run(sf::RenderWindow* window, sf::Thread* renderThread);

private:
    void initialize();
    void processEvents(sf::RenderWindow* window);
    void update(sf::Time tickRate);
    void render(sf::RenderWindow* window);

    sf::Thread* renderThread = nullptr;
    bool flag_close = false;

};

#endif
