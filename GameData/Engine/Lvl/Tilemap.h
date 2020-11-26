#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "../Core/Engine.h"
#include "../../Lvl/LvlStructs.h"
#include <vector>

class Tilemap : public sf::Drawable, public sf::Transformable {

public:
    Tilemap(std::string tileSetName, std::vector<Tile> tiles, sf::Vector2i size, uint16_t tileSize);

    void initialize();
    void render(sf::RenderWindow* window);

    inline uint16_t getTileSize()           { return tileSize; };

private:
    sf::Texture     tileset;
    sf::VertexArray vertices;

    uint16_t width;
    uint16_t height;
    uint16_t tileSize;

    std::vector<Tile> tiles;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //ENFUSION_TILEMAP_H
