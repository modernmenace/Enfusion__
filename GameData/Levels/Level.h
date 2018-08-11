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

    static std::string getLevelName();

private:
    sf::Texture background;
    std::string levelName;

};

#endif //ENFUSION_LEVEL_H
