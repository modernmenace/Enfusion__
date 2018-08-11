#ifndef ENFUSION_GAME_H
#define ENFUSION_GAME_H

#include <SFML/Graphics.hpp>
#include "Misc/Engine.h"

class Game {

public:
    Game();
    void run();

private:
    void             processEvents();
    void             update();
    void             render();

    sf::RenderWindow mWindow;
    sf::CircleShape  mPlayer;

};

#endif
