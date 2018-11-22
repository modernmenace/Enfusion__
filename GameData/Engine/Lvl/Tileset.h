#ifndef ENFUSION_TILESET_H
#define ENFUSION_TILESET_H

#include "../Core/Engine.h"

class Tileset {

public:
    Tileset(std::string setName, uint tileWidth = 32, uint tileHeight = 32);

    sf::Texture& tileAt(uint row, uint column);

private:
    sf::Texture* tiles;

    uint tileWidth;
    uint tileHeight;

};


#endif //ENFUSION_TILESET_H
