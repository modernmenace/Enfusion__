#ifndef ENFUSION_TILESET_H
#define ENFUSION_TILESET_H

#include "../Core/Engine.h"

class Tileset {

public:
    Tileset(std::string setName, uint tileWidth = 32, uint tileHeight = 32);

    sf::Sprite& tileAt(uint row, uint column);

private:
    sf::Texture* tileSetTex;

    uint tileWidth;
    uint tileHeight;

    void fillTilesMap();

    std::map<sf::Vector2i, sf::Sprite*> tiles;

};


#endif //ENFUSION_TILESET_H
