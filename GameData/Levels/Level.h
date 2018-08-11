#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include <SFML/Graphics.hpp>
#include "../Core/Engine.h"

class Level {

public:
    Level(std::string levelName, std::string background);

    virtual void initialize();
    virtual void update();
    virtual void render();

private:
    std::string levelName;
    sf::Texture background;

};

#endif //ENFUSION_LEVEL_H
