#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include <SFML/Graphics.hpp>
#include "../Core/Engine.h"

class Level {

public:
    Level(std::string levelName, std::string background);

    virtual void initialize();
    virtual void update();
    virtual void render(sf::RenderWindow* window);
    virtual void handleInput(sf::Keyboard::Key key); //called on key press

    static std::string getLevelName();

protected:
    sf::RectangleShape background;
    std::string levelName;

};

#endif //ENFUSION_LEVEL_H
